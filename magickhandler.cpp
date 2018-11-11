/* CS 3505 A7: Sprite Editor
 *
 * Purpose: The MagickHandler Class handles all interfacing with the Magick++ Library
 * This library is used to export sprite projects as different common filetpyes.
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */


#include "magickhandler.h"

MagicKHandler::MagicKHandler()
{
    InitializeMagick("");

}

void MagicKHandler::exportAsPNG(QString fileName, Frame* toExport, int height, int width)
{
       std::cout << " Trying to export to " << fileName.toStdString() << std::endl;
      try {
        // Read a file into image object
          Image toSave(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange,
          0));
          toSave.magick("gif");
          for(int hCount = 0; hCount < height; hCount++)
          {
              for(int wCount = 0; wCount < width; wCount++)
              {
                  std::tuple<int, int, int, int> color = toExport->getPixel(wCount, hCount);
                  Color toSet("Red");
                  toSave.pixelColor(wCount, hCount, toSet);
              }
          }
        // Write the image to a file
        toSave.write(fileName.toStdString());

      }
      catch( Exception &error_ )
      {
          std::cout << "Caught exception: " << error_.what() << std::endl;
      }
}
