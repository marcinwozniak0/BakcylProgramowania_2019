#include <iostream>
#include "exceptions.hpp"
#include <vector>
#include <cstdint>
#include <string>
#include <exception>
#include <stdexcept>

struct Week
{
    struct TimePoint
    {
        uint _hour;
        uint _minute;
    };

    struct Event
    {
        TimePoint _begin;
        TimePoint _end;
        std::string _name;

        Event(TimePoint begin, TimePoint end, std::string name)
        {
            _begin = begin;
            _end = end;
            _name = name;
        }
    };

    struct Day
    {
        std::vector<Event> _events;
        std::string _name;
        Day(std::string name)
        {
            _name = name;
        }
    };

    std::vector<Day> _week  = {Day("Mon"), Day("Tue"), Day("Wed"), Day("Thu"), Day("Fri"), Day("Sat"), Day("Sun")};
};
bool operator== (const Week::TimePoint& lhs, const Week::TimePoint& rhs)
{
        return lhs._hour == rhs._hour && lhs._minute == rhs._minute;
}

bool operator< (const Week::TimePoint &lhs, const Week::TimePoint &rhs)
{
    return lhs._hour < rhs._hour || (lhs._hour == rhs._hour && lhs._minute < rhs._minute);
}

bool operator >( const Week::TimePoint& lhs, const Week::TimePoint& rhs)
{
    return lhs._hour > rhs._hour || (lhs._hour == rhs._hour && lhs._minute > rhs._minute);
}

bool ConverterToTimepoint(const uint8_t& input, Week::TimePoint& output)
{
    return true;
}


bool Decode(const std::vector<uint8_t>& input, Week& output) try
{

    for(int dayNumber = 0; dayNumber < 7; dayNumber++)
    {
        for(int eventNumber = 0; eventNumber < 8; eventNumber++)
        {
            if(input.at(dayNumber * 24 + eventNumber * 3 + 0) < input.at(dayNumber * 24 + eventNumber * 3 + 1) )
            {
                Week::TimePoint begin;
                ConverterToTimepoint(input.at(dayNumber * 24 + eventNumber * 3 + 0), begin);

                Week::TimePoint end;
                ConverterToTimepoint(input.at(dayNumber * 24 + eventNumber * 3 + 1), end);

                std::string name = std::to_string(input.at(dayNumber *  24 + eventNumber * 3 + 2));

                output._week.at(dayNumber)._events.emplace_back(begin, end, name);
            }
            else
            {
                throw std::overflow_error("Invalid value");
            }
        }
    }

    return true;
}

catch(std::overflow_error exception)
{
    std::cout << exception.what();
    return false;
}

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

