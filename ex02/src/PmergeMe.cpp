#include "../include/PmergeMe.hpp"

template <typename T>
void    insertionSort(T& container, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; i++)
    {
        typename T::value_type key = container[i];
        size_t j = i - 1;
        while (j >= left && container[j] > key)
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

template <typename T>
void    mergeSort(T& container, size_t left, size_t middle, size_t right)
{
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    typename T::value_type L[n1], R[n2];

    for (size_t i = 0; i < n1; i++)
        L[i] = container[left + i];
    for (size_t j = 0; j < n2; j++)
        R[j] = container[middle + 1 + j];
    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            container[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        container[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        container[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
pm::PmergeMe(T& container)
{
    sort(container, 0, container.size() - 1);
}

pm::~PmergeMe()
{

}

void   pm::sort(std::vector<int>& container, size_t left, size_t right)
{
    if (right - left < 16)
        insertionSort(container, left, right);
    else
    {
        size_t mid = left + (right - left) / 2;
        sort(container, left, mid);
        sort(container, mid + 1, right);
        mergeSort(container, left, mid, right);
    }
}

void   pm::sort(std::list<int>& container, size_t left, size_t right)
{
    if (right - left < 16)
        insertionSort(container, left, right);
    else
    {
        size_t mid = left + (right - left) / 2;
        sort(container, left, mid);
        sort(container, mid + 1, right);
        mergeSort(container, left, mid, right);
    }
}