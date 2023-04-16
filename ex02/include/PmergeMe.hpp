#include <iostream>
#include <vector>
#include <list>

typedef class PmergeMe pm;

class PmergeMe
{
    public:
        template<typename T>
        PmergeMe(T& container);
        ~PmergeMe();
        void   sort(std::vector<int>& container, size_t left, size_t right);
        void   sort(std::list<int>& container, size_t left, size_t right);
};