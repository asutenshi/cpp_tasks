#ifndef _FIGURE_H
#define _FIGURE_H

#include <iostream>

class Figure
{
    virtual double calc_area() { return 0; };
    virtual double calc_perimeter() { return 0; };
    virtual void name() { std::cout << "figure"; };
};

#endif