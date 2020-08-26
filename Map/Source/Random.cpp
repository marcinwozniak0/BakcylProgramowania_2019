#include "Random.hpp"
#include <random>

int random(int min, int max)
{
    thread_local std::mt19937 gen{std::random_device{}()};
    /* thread_local std::mt19937 gen{2}; */
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return dist(gen);
}
