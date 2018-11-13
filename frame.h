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


#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include <tuple>
#include <iostream>
#include <QColor>
#include <QGraphicsScene>

class Frame
{


public:
    Frame(int x, int y);
    ~Frame();
    //Create 2D array of Pixel structs
    //Note that this is public for now, along with some getters/setters
    std::tuple<int, int, int, int> pixels[100][100];

    void setPixel(int x, int y, int r, int g, int b, int a);
    void setPixel(int x, int y, std::tuple<int, int, int, int> p);
    std::tuple<int, int, int, int> getPixel(int x, int y);
    QColor getColor(int x, int y);
    QImage *image;

};



#endif // FRAME_H
