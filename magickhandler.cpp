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
          for(int hCount = 0; hCount < height; hCount++)
          {
              for(int wCount = 0; wCount < width; wCount++)
              {
                  std::tuple<int, int, int, int> color = toExport->getPixel(wCount, hCount);
                  Color toSet(std::get<0>(color), std::get<1>(color), std::get<2>(color), 1);
                  toSave.magick("gif");
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
