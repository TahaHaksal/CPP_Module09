#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <math.h>
#include <cstdlib>

typedef std::list<int> intList;

typedef std::vector<int> intVec;

class PmergeMe
{
    public:
        PmergeMe(intVec container);
        PmergeMe(intList container);
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& copy);
    private:
        void    sort(intVec& v, int start, int end);
        void    sort(intList& lst, intList::iterator start, intList::iterator end);
        intVec    _vecContainer;
        intList      _listContainer;
};