#pragma once
#include "Field.hpp"
#include "Position.hpp"
#include <memory>
#include <vector>

using FieldList = std::vector<std::vector<std::unique_ptr<Field>>>;

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Map
{
public:
    virtual const FieldList& getFields() = 0;
    virtual char printField(const std::unique_ptr<Field>& field) = 0;
    virtual std::string getMapToPrint(const Position& playerPosition) = 0;
    virtual bool isMovePossible(const Position&, const Direction&) = 0;
    virtual void makeFieldEmpty(const Position&) = 0;

private:
    bool isMoveUpPossible(const Position&);
    bool isMoveDownPossible(const Position&);
    bool isMoveRightPossible(const Position&);
    bool isMoveLeftPossible(const Position&);
};
