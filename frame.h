#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include <tuple>
#include <iostream>
#include <QColor>

class Frame
{


public:
    Frame();
    ~Frame();
    //Create 2D array of Pixel structs
    //Note that this is public for now, along with some getters/setters
    std::tuple<int, int, int, int> pixels[100][100];

    void setPixel(int x, int y, int r, int g, int b, int a);
    void setPixel(int x, int y, std::tuple<int, int, int, int> p);
    std::tuple<int, int, int, int> getPixel(int x, int y);
    QColor getColor(int x, int y);

};



#endif // FRAME_H
