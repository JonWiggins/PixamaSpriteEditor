#ifndef PIXAMAMODEL_H
#define PIXAMAMODEL_H

#include <QObject>
#include <vector>
#include <tuple>
#include <QGraphicsScene>
#include <stack>
#include "frame.h"

class PixamaModel : public QObject
{
    Q_OBJECT

    std::vector<Frame*> frameList;
    int currentFrame;

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
    void copyFrameSlot(QImage *image);
    void colorChangeSlot(std::tuple<int, int, int, int> color);
    void toolSelectSlot(int tool);

signals:
    void imageSignal(QImage *image);
    void displayErrorMessageSignal(QString title, QString details);
    //Frame updateCanvasSignal();
    //std::vector<Frame> exportSignal(int indicestoExport[], std::string filetype);
    //void saveSignal();

};

#endif // PIXAMAMODEL_H
