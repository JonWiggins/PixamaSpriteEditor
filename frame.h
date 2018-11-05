#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include <tuple>

class Frame
{


public:
    Frame();
    //Create 2D array of Pixel structs
    //Note that this is public for now, along with some getters/setters
    std::tuple<int, int, int, double> pixels[100][100];
    void setPixel(int x, int y, int r, int g, int b, double a);
    void setPixel(int x, int y, std::tuple<int, int, int, double> p);
    std::tuple<int, int, int, double> getPixel(int x, int y);

};



#endif // FRAME_H
