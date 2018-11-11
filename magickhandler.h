#ifndef MAGICKHANDLER_H
#define MAGICKHANDLER_H
#include <Magick++.h>
#include <vector>
#include "frame.h"


using namespace Magick;

class MagicKHandler
{
public:
    MagicKHandler();
    void exportAsPNG(QString fileName, Frame* toExport, int height, int width);

};

#endif // MAGICKHANDLER_H
