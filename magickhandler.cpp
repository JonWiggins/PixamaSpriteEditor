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

void MagicKHandler::exportSingleFrame(QString fileName, QString type, Frame* toExport, int height, int width)
{
      try {

          // Create a new image
          Image toSave(Geometry(static_cast<unsigned long>(width), static_cast<unsigned long>(height)), Color(QuantumRange, QuantumRange, QuantumRange,
          0));

          toSave.magick(type.toStdString());

          //If the file name does not end with .(type), add .(type) to the end of it
          if(!fileName.endsWith("." + type.toUpper()) && !fileName.endsWith("." + type))
          {
              fileName.append("." + type);
          }

          //Loop through each pixel in the image at sent its values
          for(int hCount = 0; hCount < height; hCount++)
          {
              for(int wCount = 0; wCount < width; wCount++)
              {
                  std::tuple<int, int, int, int> color = toExport->getPixel(wCount, hCount);

                  //Magick++ uses color ranges as 0-65535, we must convert these values from our 0-255
                  int redQValue = static_cast<int>((std::get<0>(color) / 255.0) * 65535.0);
                  int greenQValue = static_cast<int>((std::get<1> (color) / 255.0) * 65535.0);
                  int blueQValue = static_cast<int>((std::get<2> (color) / 255.0) * 65535.0);

                  //GIF and JPG cannot have transparency
                  int alphaQValue = QuantumRange;

                  if(type.compare("PNG") == 0)
                  {
                      alphaQValue = static_cast<int>((std::get<3> (color) / 100.0) * 65535.0);
                  }
                  else
                  {
                    //If it is not PNG, and the pixel is empty, make it white
                    if(redQValue == 0 && greenQValue == 0 && blueQValue == 0)
                    {
                        redQValue = QuantumRange;
                        blueQValue = QuantumRange;
                        greenQValue = QuantumRange;
                    }
                  }

                  Color toSet(redQValue, blueQValue, greenQValue, alphaQValue);
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

void MagicKHandler::exportAsAnimatedGIF(QString fileName, std::vector<Frame*> framesToExport, int height, int width, int fps)
{
    try {

        // Create a new image
        std::vector<Magick::Image> frames;

        for(Frame* toExport : framesToExport)
        {
            Image toSave(Geometry(static_cast<unsigned long>(width), static_cast<unsigned long>(height)), Color(QuantumRange, QuantumRange, QuantumRange,
                0));

            //If the file name does not end with .gif, add .gif to the end of it
            if(!fileName.endsWith(".gif") && !fileName.endsWith(".GIF"))
            {
                fileName.append(".gif");
            }

            toSave.magick("gif");

            //Loop through each pixel in the image at sent its values
            for(int hCount = 0; hCount < height; hCount++)
            {
                for(int wCount = 0; wCount < width; wCount++)
                {
                    std::tuple<int, int, int, int> color = toExport->getPixel(wCount, hCount);

                    //Magick++ uses color ranges as 0-65535, we must convert these values from our 0-255
                    int redQValue = static_cast<int>((std::get<0>(color) / 255.0) * 65535.0);
                    int greenQValue = static_cast<int>((std::get<1> (color) / 255.0) * 65535.0);
                    int blueQValue = static_cast<int>((std::get<2> (color) / 255.0) * 65535.0);

                    //Note: GIF does not have transparency.
                    int alphaQValue = QuantumRange;

                    //If the pixel is empty, make it white
                    if(redQValue == 0 && greenQValue == 0 && blueQValue == 0)
                    {
                        redQValue = QuantumRange;
                        blueQValue = QuantumRange;
                        greenQValue = QuantumRange;
                    }

                    Color toSet(redQValue, blueQValue, greenQValue, alphaQValue);
                    toSave.pixelColor(wCount, hCount, toSet);
                }
            }
            toSave.animationDelay(static_cast<unsigned int>(fps / 60.0));
            frames.push_back(toSave);
        }
      // Write the image to a file
      writeImages(frames.begin(), frames.end(), fileName.toStdString());

    }
    catch( Exception &error_ )
    {
        std::cout << "Caught exception: " << error_.what() << std::endl;
    }
}
