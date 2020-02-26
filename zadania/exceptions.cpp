#include "exceptions.hpp"
#include <vector>

/*
 ZADANIE 1
 1. Zaprojektuj łapanie wyjatku out_of_range, tak aby podczas obsługi tego wyjatky funkcja func() zwróciła false.
 2. Popraw i dopisz test jednostkowy sprawdzajcy nową funkcjonalność.
*/

bool firstTask(const int position)
{
    std::vector<int> vec(2,2);

    vec.at(position) = 5;

    return true;
}
