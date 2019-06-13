#include <random>

#include "Accelerometer.hpp"

bool Accelerometer::isRoomEmpty()
{
    std::random_device device;
    std::mt19937 range(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

    if (0 == dist6(range) % 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
