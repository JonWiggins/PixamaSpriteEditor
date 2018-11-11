/* CS 3505 A7: Sprite Editor
 *
 * Purpose: Frame Class represents the backing data structure for each sprite Frame.
 * This class holds a 2D array which represents each pixel in the Frame, accessors and mutators
 *  are provided to access this 2D array.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */

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
