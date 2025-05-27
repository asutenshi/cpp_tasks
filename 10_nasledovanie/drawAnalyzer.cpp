#include "drawAnalyzer.h"
#include <iostream> 
#include <fstream>

using namespace std;

DrawAnalyzer::DrawAnalyzer(const int* const* image, int width, int height)
{
    this->image = image;
    this->width = width;
    this->height = height;
}

DrawAnalyzer::DrawAnalyzer(string filename)
{
    ifstream in(filename);

    if (!in.is_open())
    {
        cout << "File " << filename << " is not opened" << endl;
        throw DrawAnalyzerException();
    }

    string line;
    getline(in, line);
    int width = line.size() - 1;
    int height = 1;

    while (getline(in, line))
    {
        height++;
    }



}