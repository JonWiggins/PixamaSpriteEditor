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
      // debug
      std::cout << " Trying to export to " << fileName.toStdString() << std::endl;

      try {

          // Create a new image
          Image toSave(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange,
          0));

          toSave.magick("PNG");

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
                  int alphaQValue = static_cast<int>((std::get<3> (color) / 100.0) * 65535.0);

                  //debug printing the color writing
                  if(std::get<0>(color) != 0){
                  std::cout << redQValue << " " << greenQValue << " " << blueQValue << " " << alphaQValue << std::endl;
                  std::cout << wCount << " " << hCount << std::endl;
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

void MagicKHandler::exportFrameAsGIF(QString fileName, Frame* toExport, int height, int width)
{
      // debug
      std::cout << " Trying to export to " << fileName.toStdString() << std::endl;

      try {

          // Create a new image
          Image toSave(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange,
          QuantumRange));

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
                  int alphaQValue = static_cast<int>((std::get<3> (color) / 100.0) * 65535.0);

                  //debug printing the color writing
                  if(std::get<0>(color) != 0){
                  std::cout << redQValue << " " << greenQValue << " " << blueQValue << " " << alphaQValue << std::endl;
                  std::cout << wCount << " " << hCount << std::endl;
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

void MagicKHandler::exportAsJPG(QString fileName, Frame* toExport, int height, int width)
{
      // debug
      std::cout << " Trying to export to " << fileName.toStdString() << std::endl;

      try {

          // Create a new image
          Image toSave(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange,
          0));
          toSave.magick("jpeg");

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
                  int alphaQValue = static_cast<int>((std::get<3> (color) / 100.0) * 65535.0);

                  //debug printing the color writing
                  if(std::get<0>(color) != 0){
                  std::cout << redQValue << " " << greenQValue << " " << blueQValue << " " << alphaQValue << std::endl;
                  std::cout << wCount << " " << hCount << std::endl;
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
    // debug
    std::cout << " Trying to export to " << fileName.toStdString() << std::endl;

    try {

        // Create a new image
        std::vector<Magick::Image> frames;

        for(Frame* toExport : framesToExport)
        {
            Image toSave(Geometry(width, height), Color(QuantumRange, QuantumRange, QuantumRange,
                0));
            toSave.magick("jpeg");

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
                    int alphaQValue = static_cast<int>((std::get<3> (color) / 100.0) * 65535.0);

                   //debug printing the color writing
                    if(std::get<0>(color) != 0){
                    std::cout << redQValue << " " << greenQValue << " " << blueQValue << " " << alphaQValue << std::endl;
                    std::cout << wCount << " " << hCount << std::endl;
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
