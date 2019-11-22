#pragma once

class Field
{
public:
    Field(char sym);
    char getType() const;
private:
    char symbol;
};
