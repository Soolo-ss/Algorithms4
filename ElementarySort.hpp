#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cin;
using std::iter_swap;

class SelectionSort
{
public:
    SelectionSort(size_t n)
    { 
        int now = 0;
        for (int i = 0; i != 5; ++i)
        {
            cin >> now;
            array.push_back(now);
        }

        size = n;
    }

    void sort()
    {
        for(int i = 0; i != array.size(); ++i)
        {
            int smalllest = array[i];
            int smalllestIndex = i;
            for (int j = i; j != array.size(); ++j)
            {
                if (array[j] < smalllest)
                {
                    smalllest = array[j];
                    smalllestIndex = j;
                }
            }

            std::cout << "smalllest: " << smalllest << "   " << "index: " << smalllestIndex << std::endl;
            iter_swap(array.begin() + i, array.begin() + smalllestIndex);
        }
    }

    void print()
    {
        for(auto v : array)
        {
            std::cout << v << " ";
        }
    }

private:
    vector<int> array;
    size_t size;
};

class InsertionSort
{
public:
    InsertionSort(size_t n)
        : size(n)
    {
        int now = 0;
        while (cin >> now)
        {
            array.push_back(now);
            if (array.size() == 5)
                break;
        }
    }

    void sort()
    {
        int compare = 0;
        for (int i = 0; i != array.size(); ++i)
        {
            compare = array[i];

            for(int j = i; j != 0; j--)
            {
                if (array[j - 1] > compare)
                {
                    iter_swap(array.begin() + j - 1, array.begin() + j);
                }
            }
        }
    }

    void print()
    {
        for(auto v : array)
        {
            std::cout << v << " ";
        }
    }

private:
    std::vector<int> array;
    size_t size;
};

