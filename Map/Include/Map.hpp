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
    virtual bool isMoveUpPossible(const Position&) = 0;
    virtual bool isMoveDownPossible(const Position&) = 0;
    virtual bool isMoveRightPossible(const Position&) = 0;
    virtual bool isMoveLeftPossible(const Position&) = 0;
};
