#include <iostream>
#include "MergeSort.hpp"
int main()
{
    std::vector<int> a;

    int now;
    for (int i = 0; i !=5 ; ++i)
    {
        std::cin >> now;
        a.push_back(now);
    }

    MergeSort::sort<int>(a);

    for(auto v : a)
    {
        std::cout << v << " ";
    }

    system("pause");
    return 0;
}