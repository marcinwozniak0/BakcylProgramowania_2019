#pragma once
#include "Field.hpp"

class FightField : public Field
{
    public:
        char getType();
        void action();
    private:
        char fieldType = 'F';
};