#ifndef PIXAMAMODEL_H
#define PIXAMAMODEL_H

#include <QObject>
#include <vector>
#include "frame.h"

class PixamaModel : QObject
{
    Q_OBJECT

    std::vector<Frame> frameList;

public:
    PixamaModel();

public slots:
    //void updateFrameSlot(int x, int y, Pixel p);
    //void updateFrameSlot(int x, int y, int r, int g, int b, int a);
    //void openSlot(std::string file);

signals:
    //Frame updateCanvasSignal();
    //std::vector<Frame> exportSignal(int indicestoExport[], std::string filetype);
    //void saveSignal();

};

#endif // PIXAMAMODEL_H
