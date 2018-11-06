#ifndef PIXAMAMODEL_H
#define PIXAMAMODEL_H

#include <QObject>
#include <vector>
#include "frame.h"

class PixamaModel : public QObject
{
    Q_OBJECT

    std::vector<Frame> frameList;

public:
    PixamaModel();
    int height;
    int width;

public slots:
    //void updateFrameSlot(int x, int y, Pixel p);
    //void updateFrameSlot(int x, int y, int r, int g, int b, int a);
    //void openSlot(std::string file);
    void mouseEventSlot(int x, int y);
    void saveFileSlot(QString fileName);
    void openFileSlot(QString filename);

signals:
    //Frame updateCanvasSignal();
    //std::vector<Frame> exportSignal(int indicestoExport[], std::string filetype);
    //void saveSignal();
    void displayErrorMessageSignal(QString title, QString details);

};

#endif // PIXAMAMODEL_H
