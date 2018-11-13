/* CS 3505 A7: Sprite Editor
 *
 * Purpose: The MagickHandler Class handles all interfacing with the Magick++ Library
 * This library is used to export sprite projects as different common filetpyes.
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */

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
    void exportSingleFrame(QString fileName, QString type, Frame* toExport, int height, int width);
    void exportAsAnimatedGIF(QString fileName, std::vector<Frame*>, int height, int width, int fps);


};

#endif // MAGICKHANDLER_H
