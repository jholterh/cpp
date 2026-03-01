#pragma once

#include <vector>
#include <deque>

struct Pair {
    int     smaller;
    int     larger;
};

class PmergeMe
{
    public:
        PmergeMe(std::vector<int> input);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void                sort();
        void                displayResults();

    private:
        std::vector<int>    _unsorted;
        int                 _straggler;
        bool                _has_straggler;
        std::vector<int>    _jakobsthal_number;

        // vec
        std::vector<int>    _vec;
        std::vector<Pair>   _vecPairs;
        unsigned int        _vec_comp_count;
        double              _vec_time;
        void                sortVec();
        bool                compareVec(int a, int b);
        std::vector<Pair>   pairVec();
        void                sortLargerVec(std::vector<Pair>& pairs);
        int                 binarySearchVec(int value, int start, int end);
        void                binaryInsertVec(int value, int maxSearchIndex);
        void                buildMainChainVec();

        // deque
        std::deque<int>     _deq;
        std::deque<Pair>    _deqPairs;
        unsigned int        _deq_comp_count;
        double              _deq_time;
        void                sortDeq();
        bool                compareDeq(int a, int b);
        std::deque<Pair>    pairDeq();
        void                sortLargerDeq(std::deque<Pair>& pairs);
        int                 binarySearchDeq(int value, int start, int end);
        void                binaryInsertDeq(int value, int maxSearchIndex);
        void                buildMainChainDeq();
        
        // helpers
        void                generateJacobsthal();
        std::vector<int>    buildInsertionOrder(int pairCount);
        void                displayBefore();
        void                displayAfter();
        void                displayTiming();


};