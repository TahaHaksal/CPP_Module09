#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(intVec container)
{
    std::cout << "\n-----------VECTOR-----------" << std::endl << std::endl;
    _vecContainer = container;
    std::cout << "**Before**\n";
    for (intVec::iterator it = _vecContainer.begin(); it != _vecContainer.end(); it++)
    {
        std::cout << *it << " ";
        if (std::distance(_vecContainer.begin(), it) == 10)
        {
            std::cout << "... " << *(_vecContainer.end() - 1) << std::endl;
            break ;
        }
    }
    std::cout << std::endl;
    clock_t start = clock();
    sort(_vecContainer,0, _vecContainer.size() - 1);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "**After**\n";
    for (intVec::iterator it = _vecContainer.begin(); it != _vecContainer.end(); it++)
    {
        std::cout << *it << " ";
        if (std::distance(_vecContainer.begin(), it) == 10)
        {
            std::cout << "... " << *(_vecContainer.end() - 1) << std::endl;
            break ;
        }
    }
    std::cout << "Sorting took " << duration << " miliseconds\n";
}

PmergeMe::PmergeMe(intList container)
{
    _listContainer = container;
    std::cout << "\n-----------LIST-----------" << std::endl << std::endl ;
    std::cout << "**Before**\n";
    for (intList::iterator it = _listContainer.begin(); it != _listContainer.end(); it++)
    {
        std::cout << *it << " ";
        if (std::distance(_listContainer.begin(), it) == 10)
        {
            std::cout << "... " << _listContainer.back() << std::endl;
            break ;
        }
    }
    std::cout << std::endl;
    clock_t start = clock();
    sort(_listContainer, _listContainer.begin(), _listContainer.end());
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "**After**\n";
    for (intList::iterator it = _listContainer.begin(); it != _listContainer.end(); it++)
    {
        std::cout << *it << " ";
        if (std::distance(_listContainer.begin(), it) == 10)
        {
            std::cout << "... " << _listContainer.back() << std::endl;
            break ;
        }
    }
    std::cout << "Sorting took " << duration << " miliseconds\n";
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}

void   PmergeMe::sort(intList& lst, intList::iterator start, intList::iterator end)
{
    if (start == end) {
        return;
    }

    // If the sublist is small enough, use insertion sort instead of merge sort
    const int INSERTION_SORT_THRESHOLD = 16;
    int len = std::distance(start, end);
    if (len < INSERTION_SORT_THRESHOLD) {
        for (intList::iterator i = start; i != end; i++) {
            int key = *i;
            intList::iterator j = i;
            while (j != start && *std::prev(j) > key) {
                std::iter_swap(j, std::prev(j));
                j = std::prev(j);
            }
            *j = key;
        }
        return;
    }


    // Recursively sort the two halves of the sublist using merge sort
    intList::iterator mid = start;
    std::advance(mid, len/2);
    sort(lst, start, mid);
    sort(lst, mid, end);

    // Merge the two sorted halves of the sublist
    intList tmp;
    intList::iterator left = start;
    intList::iterator right = mid;


    while (left != mid && right != end) {
        if (*left < *right) {
            tmp.push_back(*left++);
        } else {
            tmp.push_back(*right++);
        }
    }
    tmp.insert(tmp.end(), left, mid);
    tmp.insert(tmp.end(), right, end);
    std::copy(tmp.begin(), tmp.end(), start);

}

void   PmergeMe::sort(intVec& v, int start, int end)
{
    if (start >= end) {
        return;
    }

    // If the subvector is small enough, use insertion sort instead of merge sort
    const int INSERTION_SORT_THRESHOLD = 16;
    if (end - start < INSERTION_SORT_THRESHOLD) {
        for (int i = start + 1; i <= end; i++) {
            int key = v[i];
            int j = i - 1;
            while (j >= start && v[j] > key) {
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = key;
        }
        return;
    }

    int mid = (start + end) / 2;
    sort(v, start, mid);
    sort(v, mid + 1, end);

    // Check if the two halves are already sorted
    if (v[mid] <= v[mid+1]) {
        return;
    }

    intVec temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = v[i++];
    }
    while (j <= end) {
        temp[k++] = v[j++];
    }
    for (int i = 0; i < k; i++) {
        v[start + i] = temp[i];
    }
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    if (copy._vecContainer.size() > 0)
        PmergeMe a(copy._vecContainer);
    else
        PmergeMe a(copy._listContainer);
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
    if (copy._vecContainer.size() > 0)
        PmergeMe a(copy._vecContainer);
    else
        PmergeMe a(copy._listContainer);
    return *this;
}