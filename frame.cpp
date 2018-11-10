#include "frame.h"


Frame::Frame()
{

}

Frame::~Frame()
{
    //nothing is needed here, the pixels array will free itself
}

std::tuple<int, int, int, int> Frame::getPixel(int x, int y)
{
    return this->pixels[x][y];
}

void Frame::setPixel(int x, int y, std::tuple<int, int, int, int> p)
{
    this->pixels[x][y] = p;
}

void Frame::setPixel(int x, int y, int r, int g, int b, int a)
{
    this->pixels[x][y] = std::make_tuple(r, g, b, a);
}


QColor Frame::getColor(int x, int y)
{
    return QColor(std::get<0>(this->pixels[x][y]), std::get<1>(this->pixels[x][y]), std::get<2>(this->pixels[x][y]), std::get<3>(this->pixels[x][y]));
}
