#include <vector>
#include "valgrind_and_pointers.hpp"

bool secondTask(const int position)
{
    int * i = new int(4);

    std::vector<int> vec(2,2);

    vec.at(position) = 5;

    return true;
}
