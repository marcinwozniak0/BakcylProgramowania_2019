#pragma once

#include <algorithm>
#include <vector>

struct comparator
{
    bool operator() (int value){return value % 2 != 0;}
};

int getNumOfOddValues(const std::vector<int>& vec)
{
    return std::count_if(vec.begin(), vec.end(), comparator());
}

void reverse(std::vector<int>& vec)
{
    std::vector<int> newVector;

    for(int i = vec.size(); i > 0; --i)
    {
        newVector.push_back(vec[i-1]);
    }

    vec = newVector;
}

bool isAllOfValuesAreEven(const std::vector<int>& vec)
{
    return true;
}
