#include <iostream>
#include "polygon.h"
#include "drawAnalyzer.h"

using namespace std;

int main(void)
{
    // string filename = "granitsy-uchastka2.txt";
    // Polygon polygon = Polygon(filename);
    // for (Point p : polygon.getPoints())
    // {
    //     cout << "p " << p.getX() << " " << p.getY() << endl;
    // }
    // cout << "area = " << polygon.calc_area() << endl;
    // cout << "perimeter = " << polygon.calc_perimeter() << endl;
    // cout << "name = ";
    // polygon.name();
    string filepath("./data/input1.dat");
    DrawAnalyzer d(filepath);
    
    return 0;
}