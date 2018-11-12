/* CS 3505 A7: Sprite Editor
 *
 * Purpose: This Model serves as the backing logic frame for the Sprite Editor
 * It handles all of the user actions, which it recives in its slots, from signals sent from the Window
 * It keeps track of a vector of Frames which represent the curernt sprite project
 * It holds a MagicKHandler object which it uses to export projects.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */

#ifndef PIXAMAMODEL_H
#define PIXAMAMODEL_H

#include <QObject>
#include <vector>
#include <tuple>
#include <QGraphicsScene>
#include <stack>
#include "frame.h"
#include "magickhandler.h"

class PixamaModel : public QObject
{
    Q_OBJECT

    int currentFrame;
    std::vector<Frame*> frameList;
    MagicKHandler* magick;

public:
    PixamaModel();
    int height;
    int width;
    int pixelSize;
    QImage *image;
    std::tuple<int, int, int, int> currentColor;
    int currentTool; //0 for draw/erase 1 for paintbucket can be different number for other tools
    void draw(int x, int y);
    void colorPixel(int x, int y, Frame *frame);

public slots:
    //void updateFrameSlot(int x, int y, Pixel p);
    //void updateFrameSlot(int x, int y, int r, int g, int b, int a);
    //void openSlot(std::string file);
    void mouseEventSlot(int x, int y);
    void saveFileSlot(QString fileName);
    void openFileSlot(QString filename);
    void newFrameSlot();
    void copyFrameSlot();
    void colorChangeSlot(std::tuple<int, int, int, int> color);
    void toolSelectSlot(int tool);
    void exportAsPNGSlot(QString fileName);
    void exportAsJPGSlot(QString fileName);
    void exportFrameAsGIFSlot(QString fileName);
    void selectFrameSlot(int frameNumber);

signals:
    void imageSignal(QImage image);
    void displayErrorMessageSignal(QString title, QString details);
    void frameStateSignal(std::vector<int> frameState);
    //Frame updateCanvasSignal();
    //std::vector<Frame> exportSignal(int indicestoExport[], std::string filetype);
    //void saveSignal();

};

#endif // PIXAMAMODEL_H
