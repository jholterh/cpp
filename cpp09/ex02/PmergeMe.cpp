#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _straggler(0), _has_straggler(false), _vec_comp_count(0), _vec_time(0), _deq_comp_count(0), _deq_time(0) {}

PmergeMe::PmergeMe(std::vector<int> &input) : _unsorted(input), _straggler(0), _has_straggler(input.size() % 2 != 0), _vec_comp_count(0), _vec_time(0), _deq_comp_count(0), _deq_time(0)
{
    if (_has_straggler)
        _straggler = _unsorted.back();
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _unsorted(copy._unsorted), _straggler(copy._straggler), _has_straggler(copy._has_straggler), _vec_comp_count(copy._vec_comp_count), _vec_time(copy._vec_time), _deq_comp_count(copy._deq_comp_count), _deq_time(copy._deq_time) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _unsorted = other._unsorted;
        _vec_comp_count = other._vec_comp_count;
        _vec_time = other._vec_time;
        _deq_comp_count = other._deq_comp_count;
        _deq_time = other._deq_time;
        _has_straggler = other._has_straggler;
        _straggler = other._straggler;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Shared helper
// jacobsthal recurrence: t(k) = t(k-1) + 2 * t(k-2)
// k is index, t(k) means jacobstal of index k

std::vector<int> PmergeMe::buildInsertionOrder(int totalPending)
{
    std::vector<int> order;
    if (totalPending <= 0)
        return order;
    std::vector<int> jacob;
    int prev2 = 1, prev1 = 1;
    while (true)
    {
        int current = prev1 + 2 * prev2;
        int groupEnd = current - 1;
        if (groupEnd > totalPending)
            groupEnd = totalPending;
        jacob.push_back(groupEnd);
        if (groupEnd >= totalPending)
            break;
        prev2 = prev1;
        prev1 = current;
    }
    int prev = 0;
    for (int i = 0; i < (int)jacob.size(); i++)
    {
        for (int j = jacob[i]; j > prev; j--)
            order.push_back(j);
        prev = jacob[i];
    }
    return order;
}

// Vector pipeline

// wrapper function to count the comparisons
bool                    PmergeMe::compareVec(int a, int b)
{
    _vec_comp_count++;
    return (a > b);
}

// creates the pairs and saves them in a vec
std::vector<Pair>       PmergeMe::pairVec()
{
    std::vector<Pair> pairs;
    for (int i = 0; (int)_unsorted.size() / 2 > i; i++)
    {
        Pair p;
        if (compareVec(_unsorted[i * 2], _unsorted[i * 2 + 1]))
        {
            p.larger = _unsorted[i * 2];
            p.smaller = _unsorted[i * 2 + 1];
        }
        else
        {
            p.smaller = _unsorted[i * 2];
            p.larger = _unsorted[i * 2 + 1];
        }
        pairs.push_back(p);
    }
    return pairs;
}

// recursively sorts the larger numbers carrying the lower number with them
void                    PmergeMe::sortLargerVec(std::vector<Pair>& pairs)
{
    if (pairs.size() <= 1)
        return;

    // pairwise comparisons, track winner-loser pairings
    bool hasOdd = pairs.size() % 2 != 0;
    Pair oddPair;
    if (hasOdd)
        oddPair = pairs.back();

    std::vector<Pair> winners;
    std::vector<Pair> losers;
    for (int i = 0; i + 1 < (int)pairs.size(); i += 2)
    {
        if (compareVec(pairs[i].larger, pairs[i + 1].larger))
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }
    // save pairings before recursive sort reorders winners
    std::vector<Pair> origWinners(winners);

    // recursively sort winners
    sortLargerVec(winners);

    // reorder losers to match sorted winners
    std::vector<Pair> sortedLosers(winners.size());
    for (int i = 0; i < (int)winners.size(); i++)
    {
        for (int j = 0; j < (int)origWinners.size(); j++)
        {
            if (origWinners[j].larger == winners[i].larger
                && origWinners[j].smaller == winners[i].smaller)
            {
                sortedLosers[i] = losers[j];
                break;
            }
        }
    }

    // build main chain with Jacobsthal insertion order
    std::vector<Pair> chain;
    chain.push_back(sortedLosers[0]);
    for (int i = 0; i < (int)winners.size(); i++)
        chain.push_back(winners[i]);

    // total pending: losers[1..m-1] + oddPair (if exists)
    int numLosers = (int)sortedLosers.size();
    int totalPending = (numLosers - 1) + (hasOdd ? 1 : 0);

    if (totalPending > 0)
    {
        std::vector<int> insertOrder = buildInsertionOrder(totalPending);

        // insert in Jacobsthal order
        std::vector<int> insertionShifts(winners.size(), 0);
        for (int k = 0; k < (int)insertOrder.size(); k++)
        {
            int pendingIdx = insertOrder[k]; // 1-based pending index
            Pair toInsert;
            int searchHi;

            if (pendingIdx <= numLosers - 1)
            {
                toInsert = sortedLosers[pendingIdx];
                searchHi = pendingIdx + insertionShifts[pendingIdx];
            }
            else
            {
                toInsert = oddPair;
                searchHi = (int)chain.size() - 1;
            }

            int searchLo = 0;
            while (searchHi >= searchLo)
            {
                int mid = (searchLo + searchHi) / 2;
                if (compareVec(chain[mid].larger, toInsert.larger))
                    searchHi = mid - 1;
                else
                    searchLo = mid + 1;
            }
            chain.insert(chain.begin() + searchLo, toInsert);
            for (int i = 0; i < (int)winners.size(); i++)
            {
                if (i + 1 + insertionShifts[i] >= searchLo)
                    insertionShifts[i]++;
            }
        }
    }
    pairs = chain;
}

// ties it all together
void PmergeMe::buildMainChainVec()
{
    _vec.push_back(_vecPairs[0].smaller);
    for (int i = 0; i < (int)_vecPairs.size(); i++)
        _vec.push_back(_vecPairs[i].larger);

    int numLosers = (int)_vecPairs.size();
    int totalPending = (numLosers - 1) + (_has_straggler ? 1 : 0);

    if (totalPending > 0)
    {
        std::vector<int> insertOrder = buildInsertionOrder(totalPending);

        std::vector<int> insertionShifts(_vecPairs.size(), 0);
        for (int k = 0; k < (int)insertOrder.size(); k++)
        {
            int pendingIdx = insertOrder[k]; // 1-based pending index
            int value;
            int searchHi;

            if (pendingIdx <= numLosers - 1)
            {
                value = _vecPairs[pendingIdx].smaller;
                searchHi = pendingIdx + insertionShifts[pendingIdx];
            }
            else
            {
                value = _straggler;
                searchHi = (int)_vec.size() - 1;
            }

            int searchLo = 0;
            while (searchHi >= searchLo)
            {
                int mid = (searchLo + searchHi) / 2;
                if (compareVec(_vec[mid], value))
                    searchHi = mid - 1;
                else
                    searchLo = mid + 1;
            }
            _vec.insert(_vec.begin() + searchLo, value);
            for (int i = 0; i < (int)_vecPairs.size(); i++)
            {
                if (i + 1 + insertionShifts[i] >= searchLo)
                    insertionShifts[i]++;
            }
        }
    }
}

void PmergeMe::sortVec()
{
    clock_t start = clock();
    if (_unsorted.size() <= 1)
    {
        _vec = _unsorted;
    }
    else
    {
        _vecPairs = pairVec();
        sortLargerVec(_vecPairs);
        buildMainChainVec();
    }
    clock_t end = clock();
    _vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

// === Deque pipeline ===

bool                    PmergeMe::compareDeq(int a, int b)
{
    _deq_comp_count++;
    return (a > b);
}

std::deque<Pair>        PmergeMe::pairDeq()
{
    std::deque<Pair> pairs;
    for (int i = 0; (int)_unsorted.size() / 2 > i; i++)
    {
        Pair p;
        if (compareDeq(_unsorted[i * 2], _unsorted[i * 2 + 1]))
        {
            p.larger = _unsorted[i * 2];
            p.smaller = _unsorted[i * 2 + 1];
        }
        else
        {
            p.smaller = _unsorted[i * 2];
            p.larger = _unsorted[i * 2 + 1];
        }
        pairs.push_back(p);
    }
    return pairs;
}

void                    PmergeMe::sortLargerDeq(std::deque<Pair>& pairs)
{
    if (pairs.size() <= 1)
        return;

    bool hasOdd = pairs.size() % 2 != 0;
    Pair oddPair;
    if (hasOdd)
        oddPair = pairs.back();

    std::deque<Pair> winners;
    std::deque<Pair> losers;
    for (int i = 0; i + 1 < (int)pairs.size(); i += 2)
    {
        if (compareDeq(pairs[i].larger, pairs[i + 1].larger))
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }
    std::deque<Pair> origWinners(winners);

    sortLargerDeq(winners);

    std::deque<Pair> sortedLosers(winners.size());
    for (int i = 0; i < (int)winners.size(); i++)
    {
        for (int j = 0; j < (int)origWinners.size(); j++)
        {
            if (origWinners[j].larger == winners[i].larger
                && origWinners[j].smaller == winners[i].smaller)
            {
                sortedLosers[i] = losers[j];
                break;
            }
        }
    }

    std::deque<Pair> chain;
    chain.push_back(sortedLosers[0]);
    for (int i = 0; i < (int)winners.size(); i++)
        chain.push_back(winners[i]);

    int numLosers = (int)sortedLosers.size();
    int totalPending = (numLosers - 1) + (hasOdd ? 1 : 0);

    if (totalPending > 0)
    {
        std::vector<int> insertOrder = buildInsertionOrder(totalPending);

        std::vector<int> insertionShifts(winners.size(), 0);
        for (int k = 0; k < (int)insertOrder.size(); k++)
        {
            int pendingIdx = insertOrder[k];
            Pair toInsert;
            int searchHi;

            if (pendingIdx <= numLosers - 1)
            {
                toInsert = sortedLosers[pendingIdx];
                searchHi = pendingIdx + insertionShifts[pendingIdx];
            }
            else
            {
                toInsert = oddPair;
                searchHi = (int)chain.size() - 1;
            }

            int searchLo = 0;
            while (searchHi >= searchLo)
            {
                int mid = (searchLo + searchHi) / 2;
                if (compareDeq(chain[mid].larger, toInsert.larger))
                    searchHi = mid - 1;
                else
                    searchLo = mid + 1;
            }
            chain.insert(chain.begin() + searchLo, toInsert);
            for (int i = 0; i < (int)winners.size(); i++)
            {
                if (i + 1 + insertionShifts[i] >= searchLo)
                    insertionShifts[i]++;
            }
        }
    }
    pairs = chain;
}

void PmergeMe::buildMainChainDeq()
{
    _deq.push_back(_deqPairs[0].smaller);
    for (int i = 0; i < (int)_deqPairs.size(); i++)
        _deq.push_back(_deqPairs[i].larger);

    int numLosers = (int)_deqPairs.size();
    int totalPending = (numLosers - 1) + (_has_straggler ? 1 : 0);

    if (totalPending > 0)
    {
        std::vector<int> insertOrder = buildInsertionOrder(totalPending);

        std::vector<int> insertionShifts(_deqPairs.size(), 0);
        for (int k = 0; k < (int)insertOrder.size(); k++)
        {
            int pendingIdx = insertOrder[k];
            int value;
            int searchHi;

            if (pendingIdx <= numLosers - 1)
            {
                value = _deqPairs[pendingIdx].smaller;
                searchHi = pendingIdx + insertionShifts[pendingIdx];
            }
            else
            {
                value = _straggler;
                searchHi = (int)_deq.size() - 1;
            }

            int searchLo = 0;
            while (searchHi >= searchLo)
            {
                int mid = (searchLo + searchHi) / 2;
                if (compareDeq(_deq[mid], value))
                    searchHi = mid - 1;
                else
                    searchLo = mid + 1;
            }
            _deq.insert(_deq.begin() + searchLo, value);
            for (int i = 0; i < (int)_deqPairs.size(); i++)
            {
                if (i + 1 + insertionShifts[i] >= searchLo)
                    insertionShifts[i]++;
            }
        }
    }
}

void PmergeMe::sortDeq()
{
    clock_t start = clock();
    if (_unsorted.size() <= 1)
    {
        for (int i = 0; i < (int)_unsorted.size(); i++)
            _deq.push_back(_unsorted[i]);
    }
    else
    {
        _deqPairs = pairDeq();
        sortLargerDeq(_deqPairs);
        buildMainChainDeq();
    }
    clock_t end = clock();
    _deq_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

// === Entry point ===

void PmergeMe::sort()
{
    sortVec();
    sortDeq();
}

// === Display ===

void PmergeMe::displayBefore()
{
    std::cout << "Before:";
    for (int i = 0; i < (int)_unsorted.size(); i++)
        std::cout << " " << _unsorted[i];
    std::cout << std::endl;
}

void PmergeMe::displayAfter()
{
    std::cout << "After:";
    for (int i = 0; i < (int)_vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::displayTiming()
{
    std::cout << "Time to process a range of " << _unsorted.size()
              << " elements with std::vector : " << _vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << _unsorted.size()
              << " elements with std::deque  : " << _deq_time << " us" << std::endl;
    // F(n) = sum of ceil(log2(3k/4)) for k=1..n
    int ideal = 0;
    for (int k = 1; k <= (int)_unsorted.size(); k++)
        ideal += (int)std::ceil(std::log(3.0 * k / 4.0) / std::log(2.0));
    std::cout << "Comparisons (vec): " << _vec_comp_count << " | ideal F(n): " << ideal << std::endl;
    std::cout << "Comparisons (deq): " << _deq_comp_count << " | ideal F(n): " << ideal << std::endl;
}

void PmergeMe::displayResults()
{
    displayBefore();
    displayAfter();
    displayTiming();
}
