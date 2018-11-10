#include "frame.h"


Frame::Frame()
{
    std::make_tuple<int,int,int,double>(1,2,3,1.0);
}

std::tuple<int, int, int, double> Frame::getPixel(int x, int y)
{
    auto toreturn = this->pixels[x][y];
    std::cout << "returning color " << std::get<0>(toreturn) << " " << std::get<1>(toreturn) << " " << std::get<2>(toreturn) << std::endl;
    return toreturn;
}

void Frame::setPixel(int x, int y, std::tuple<int, int, int, double> p)
{
    std::cout << "Storing color " << std::get<0>(p) << " " << std::get<1>(p) << " " << std::get<2>(p) << std::endl;
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
