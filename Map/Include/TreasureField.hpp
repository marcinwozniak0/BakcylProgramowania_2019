#pragma once
#include "Field.hpp"

class TreasureField : public Field
{
    public:
        char getType();
        void action();
    private:
        char fieldType = 'T';
};

