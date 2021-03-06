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
    static void sort(vector<T>& vec)
    {
        vector<T> vec_aux(vec.size());
        sort(vec, vec_aux, 0, vec.size() - 1);
    }

private:
    template <typename T>
    static void sort(vector<T>& vec, vector<T>& vec_aux, int lo, int hi)
    {
        int mid = (lo + hi) / 2;

        if ((hi - lo) < 1)
            return;

        sort(vec, vec_aux, lo, mid);
        sort(vec, vec_aux, mid + 1, hi);
        //merge
        merge(vec, vec_aux, lo, mid, hi);
    }

private:
    template <typename T>
    static void merge(vector<T>& vec, vector<T>& vec_aux, int lo, int mid, int hi)
    {
        int lo_iter = lo;
        int mid_iter = ((lo + hi ) / 2) + 1;
        int hi_iter = hi;

        int push = 0;

        while (true)
        {

            if (vec[lo_iter] < vec[mid_iter])
            {
                vec_aux[lo + push] = vec[lo_iter];
                ++lo_iter;
            }
            else
            {
                vec_aux[lo + push] = vec[mid_iter];
                ++mid_iter;
            }

            ++push;

            if (lo_iter >= mid || mid_iter > hi)
                break;
        }
        for( ; lo_iter <= mid; ++lo_iter)
        {
            vec_aux[lo + push] = vec[lo_iter];
            ++push;
        }

        for( ; mid_iter <= hi; ++mid_iter)
        {
            vec_aux[lo + push] = vec[mid_iter];
        }

        for ( int i = lo; i <= hi; ++i)
        {
            vec[i] = vec_aux[i];
        }
    }
};

#endif //ALGORITHMS4_MERGESORT_H
