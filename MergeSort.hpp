//
// Created by pc4 on 2018/6/13.
//

#ifndef ALGORITHMS4_MERGESORT_H
#define ALGORITHMS4_MERGESORT_H

#include <iostream>
#include <vector>

using std::vector;

class MergeSort
{
public:
    template <typename T>
    static void sort(Iterator<T> start, Iterator<T> end)
    {
        Iterator<T> mid = start + (end - start) / 2;

        if (mid == start || mid == end)
            return;

        sort<T>(start, mid);
        sort<T>(mid, end);
        merge<T>(start, mid, end);
    }

    template <typename T>
    static void sort(vector<T> vec)
    {
        vector<T> vec_aux(vec.size());
        sort(vec, vec_aux, 0, vec.size() - 1);
    }


private:
    template <typename T>
    static void sort(vector<T>& vec, vector<T>& vec_aux, int lo, int hi)
    {
        int mid = (lo + hi) / 2;

        if (mid == lo)
            return;

        sort(vec, vec_aux, lo, mid);
        sort(vec, vec_aux, mid + 1, hi);
        //merge
    }

private:
    template <typename T>
    static void merge(vector<T>& vec, vector<T>& vec_aux, int lo, int mid, int hi)
    {
        int left = vec

        while (true)
        {
            if (vec[lo] < vec[mid + 1])
            {

            }
        }
    }

    template <typename T>
    static void merge(Iterator<T> start, Iterator<T> mid, Iterator<T> end)
    {
        std::vector<T> sorted;

        Iterator<T> startIter = start;
        Iterator<T> midIter = mid;
        Iterator<T> endIter = end;

        while (true)
        {
            if ((*startIter) < (*midIter))
            {
                sorted.push_back(*startIter);
                start++;
            }
            else
            {
                sorted.push_back(*midIter);
                midIter++;
            }

            if (startIter == mid || midIter == endIter)
                break;
        }

        //处理额外长度
        if (startIter == mid)
        {
            for( ; midIter != end; ++midIter)
            {
                sorted.push_back(*midIter);
            }
        }
        else
        {
            for( ; startIter != mid; ++startIter)
            {
                sorted.push_back(*startIter);
            }
        }

        //赋值给原始列表
        for (auto v : sorted)
        {
            (*start) = v;
            ++start;
        }
    }

};

#endif //ALGORITHMS4_MERGESORT_H
