//
// Created by 46127 on 2018/6/18.
//

#ifndef ALGORITHMS4_QUICKSORT_HPP
#define ALGORITHMS4_QUICKSORT_HPP

#include <vector>
#include <algorithm>

using std::vector;
using std::iter_swap;

class QuickSort
{
public:
    template <typename T>
    static void sort(vector<T>& vec)
    {
        sort(vec, 0, vec.size() - 1);
    }

private:
    template <typename T>
    static void sort(vector<T>& a, int lo, int hi)
    {
		if (lo >= hi)
			return;

        int j = partiton(a, lo, hi);

        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }

    template <typename T>
    static int partiton(vector<T>& a, int lo, int li)
    {
        int i = lo, j = li + 1;
        T v = a[i];

        while (true)
        {
			while (a[++i] < v)
			{
				if (i == li)
					break;
			}

			while (a[--j] > v)
			{
				if (j == lo)
					break;
			}

			if (i >= j)
				break;

			iter_swap(a.begin() + i, a.begin() + j);
        }

		iter_swap(a.begin() + lo, a.begin() + j);

		return j;
    }
};

#endif //ALGORITHMS4_QUICKSORT_HPP
