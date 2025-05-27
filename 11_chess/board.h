#ifndef _BOARD_H
#define _BOARD_H

#include "figure.h"

struct Cell
{
    int x, y;
    Cell() : x(0), y(0) {}
    Cell(int x_, int y_) : x(x_), y(y_) {}
};

class Board
{
    private:
        Figure* pFigures[8][8];
    public:

};

#endif