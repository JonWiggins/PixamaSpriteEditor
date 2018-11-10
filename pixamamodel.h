#ifndef PIXAMAMODEL_H
#define PIXAMAMODEL_H

#include <QObject>
#include <vector>
#include <tuple>
#include <QGraphicsScene>
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
    std::tuple<int, int, int, double> currentColor;
    int currentTool; //0 for draw/erase 1 for paintbucket can be different number for other tools
    void draw(int x, int y, QImage *image);

public slots:
    //void updateFrameSlot(int x, int y, Pixel p);
    //void updateFrameSlot(int x, int y, int r, int g, int b, int a);
    //void openSlot(std::string file);
    void mouseEventSlot(int x, int y, QImage *image);
    void saveFileSlot(QString fileName);
    void openFileSlot(QString filename);
    void copyFrameSlot(QImage *image);
    void colorChangeSlot(std::tuple<int, int, int, double> color);
    void toolSelectSlot(int tool);

signals:
    //Frame updateCanvasSignal();
    //std::vector<Frame> exportSignal(int indicestoExport[], std::string filetype);
    //void saveSignal();
    void displayErrorMessageSignal(QString title, QString details);

};

#endif // PIXAMAMODEL_H
