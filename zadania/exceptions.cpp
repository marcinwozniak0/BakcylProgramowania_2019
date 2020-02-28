#include "exceptions.hpp"
#include <vector>
#include <cstdint>
#include <string>

struct Week
{
    struct TimePoint
    {
        uint _hour;
        uint _minute;T
    };

    struct Event
    {
        TimePoint _begin;
        TimePoint _end;
        std::string _name;

        Event(TimePoint begin, TimePoint end, uint8_t name)
        {
            _begin = begin;
            _end = end;
            _name = std::to_string(name);
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

bool ConverterToTimepoint(const uint8_t& input, TimePoint& output)
{
    return TimePoint();
}

bool Decode(const std::vector<uint8_t>& input, Week& output)
{
    for(int dayNumber = 0; dayNumber < 168; dayNumber += 24)
    {
        for(int eventNumber = dayNumber; evntNumber < dayNumber + 3; eventNumber++)
        {
            output._week.at(dayNumber)._events.emplace_back()
           output.Event(output._week.at(dayNumber)._events.at(eventNumber)._begin = ConverterToTimepoint(eventNumber) )
        }
    }
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

