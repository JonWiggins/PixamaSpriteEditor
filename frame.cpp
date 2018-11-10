#include "frame.h"


Frame::Frame()
{
    std::make_tuple<int,int,int,double>(1,2,3,1.0);
}

Frame::~Frame()
{
    //nothing is needed here, the pixels array will free itself
}

std::tuple<int, int, int, double> Frame::getPixel(int x, int y)
{
    return this->pixels[x][y];
}

void Frame::setPixel(int x, int y, std::tuple<int, int, int, double> p)
{
    this->pixels[x][y] = p;
}

void Frame::setPixel(int x, int y, int r, int g, int b, double a)
{
    this->pixels[x][y] = std::make_tuple(r, g, b, a);
}


QColor Frame::getColor(int x, int y)
{
    return QColor(std::get<0>(this->pixels[x][y]), std::get<1>(this->pixels[x][y]), std::get<2>(this->pixels[x][y]), std::get<3>(this->pixels[x][y]));
}
