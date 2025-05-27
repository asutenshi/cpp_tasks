#ifndef _DRAW_ANALYZER_H
#define _DRAW_ANALYZER_H

#include <string>

class DrawAnalyzerException {};

class DrawAnalyzer
{
    private:
        int width;
        int height;
        const int* const* image;
    public:
        DrawAnalyzer(const int* const* image, int width, int height);
        DrawAnalyzer(std::string filename);
};

#endif