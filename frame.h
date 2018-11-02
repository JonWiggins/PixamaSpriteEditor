#ifndef FRAME_H
#define FRAME_H
#include <vector>


struct Pixel{
    int r,g,b,a;
};

class Frame
{


public:
    Frame();
    //Create 2D array of Pixel structs
    //Note that this is public for now, along with some getters/setters
    Pixel pixels[100][100];

    void setPixel(int x, int y, int r, int g, int b, int a);
    void setPixel(int x, int y, Pixel p);
    Pixel getPixel(int x, int y);

};



#endif // FRAME_H
