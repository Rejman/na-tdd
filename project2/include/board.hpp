#pragma once
#include "field.hpp"
#include <vector> 

#include <iostream>

enum class Field;

// 2D matrix
using Matrix = std::vector<std::vector<Field>>;

struct Size
{
    unsigned width;
    unsigned height;
};

struct Coordinates
{
    int x;
    int y;
};

class BoardI
{
public:
    virtual Size getSize() const = 0;
    virtual Field getFieldState(const Coordinates&) const =0;
    virtual void setFieldState(const Coordinates&, Field) = 0;
    virtual ~BoardI() = default;
};

class Board : public BoardI
{
public:
    Board(const Size& size): size(size){

        for(unsigned i=0;i<size.height;i++){
            std::vector<Field> line(size.width, Field::Empty);
            states.push_back(line);
        }

    }
    Size getSize() const override;
    Field getFieldState(const Coordinates&) const override;
    void setFieldState(const Coordinates&, Field) override;
    ~Board() = default;
private:
    Size size;
    Field state{Field::Empty};
    Matrix states;
};
