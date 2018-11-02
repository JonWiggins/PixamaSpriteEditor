#include "frame.h"

Frame::Frame()
{
    int test = 3;
}

Pixel Frame::getPixel(int x, int y)
{
    return this->pixels[x][y];
}

void Frame::setPixel(int x, int y, Pixel p)
{
    this->pixels[x][y] = p;
}

void Frame::setPixel(int x, int y, int r, int g, int b, int a)
{
    this->pixels[x][y].a = a;

    this->pixels[x][y].r = r;
    this->pixels[x][y].g = g;
    this->pixels[x][y].b = b;
}
