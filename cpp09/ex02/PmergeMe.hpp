#pragma once

#include <vector>
#include <deque>
#include <ctime>
#include <cmath>
#include <iostream>

struct Pair {
    int     smaller;
    int     larger;
};

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(std::vector<int> &input);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void                sort();
        void                displayResults();

    private:
        std::vector<int>    _unsorted;
        int                 _straggler;
        bool                _has_straggler;
        // vec
        std::vector<int>    _vec;
        std::vector<Pair>   _vecPairs;
        unsigned int        _vec_comp_count;
        double              _vec_time;
        void                sortVec();
        bool                compareVec(int a, int b);
        std::vector<Pair>   pairVec();
        void                sortLargerVec(std::vector<Pair>& pairs);
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
        void                buildMainChainDeq();

        // helpers
        static std::vector<int> buildInsertionOrder(int totalPending);
        void                displayBefore();
        void                displayAfter();
        void                displayTiming();


};