#include "board.hpp"


Size Board::getSize() const {return size;}
Field Board::getFieldState(const Coordinates& cord) const{
    return states[cord.x][cord.y];
}
void Board::setFieldState(const Coordinates&, Field newState) {state = newState;}