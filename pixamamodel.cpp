#include "pixamamodel.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

PixamaModel::PixamaModel()
{
    //TODO replace these with meaningful values
    this->height = 100;
    this->width = 100;
    this->pixelSize = 5; //Assuming pixels are square
    this->currentFrame = 0; //Sets the currentFrame to the first frame
    Frame firstFrame;
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            firstFrame.setPixel( i, j, 0, 0, 255, 1.0); //Setting a pixel in the frame to be green
        }
    }

    this->frameList.push_back(firstFrame);
    this->currentColor = std::make_tuple<int, int, int, double>(0, 0, 0, 0.0); //Current color at startup is transparent
    this->currentTool = 0; //starting tool is single pixel draw
}

//Changes color of backing
void PixamaModel::colorChangeSlot(std::tuple<int, int, int, double> color)
{
    this->currentColor = color;
}

void PixamaModel::toolSelectSlot(int tool)
{
    this->currentTool = tool;
}

//When mouse is clicked on frame
void PixamaModel::mouseEventSlot(int x, int y, QImage *image)
{
    //Changing x and y to the size of pixels
    x = x / this->pixelSize;
    y = y / this->pixelSize;

    //Checking to make sure x and y are bigger than the current bounds
    if(x >= this->width || y >= this->height)
    {
        return;
    }
    draw(x, y, image);
}

void PixamaModel::draw(int x, int y, QImage *image)
{
    Frame frame = this->frameList[static_cast<unsigned int>(currentFrame)];
    switch(this->currentTool) //Using switch for possibility of new tools
    {
        case 0:  //draw/erase tool
        {
            std::cout << "Setting " << x << " " << y << " " << std::get<0>(this->currentColor) << std::endl;
            frame.setPixel(x, y, this->currentColor);
            for(int pixelSizeCounterX = 0; pixelSizeCounterX < pixelSize; pixelSizeCounterX++)
            {
                for(int pixelSizeCounterY = 0; pixelSizeCounterY < pixelSize; pixelSizeCounterY++)
                {
                image->setPixelColor(x*pixelSize + pixelSizeCounterX, y*pixelSize + pixelSizeCounterY, frame.getColor(x, y));
                }
            }
            break;
        }
        case 1: //bucket tool
        {
            break;
        }
    }
}

void PixamaModel::saveFileSlot(QString fileName)
{
    if(fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        emit displayErrorMessageSignal("Unable to Save File",file.errorString());
        return;
    }

    QTextStream outputStream(&file);


    //TODO ensure that this is correct
    //outputStream.setVersion(QDataStream::Qt_5_4);


    //File format:
    //The height and width of a sprite frame specified by 2 integers with a space between followed by a \n newline.
    outputStream << this->height << " " << this->width << "\n";

    //The number of frames represented by a single integer followed by a newline.
    outputStream << static_cast<int>(this->frameList.size()) << "\n";
  
    //Each frame in order from lowest to highest numbered. A frame is output by
    // starting at the top row and going to the bottom, list the pixels for each row as red green blue alpha values with spaces in-between two values. Finish a row with a newline. Do not add extra whitespace between color values or pixels or between rows or between frames.
    for(Frame &element : frameList)
    {
        for(int hIndex = 0; hIndex < this->height; hIndex ++)
        {
            for(int wIndex = 0; wIndex < this->width - 1; wIndex++)
            {
                std::tuple<int, int, int, double> toWrite = element.getPixel(hIndex, wIndex);
                outputStream << std::get<0>(toWrite) << " " << std::get<1>(toWrite) << " " << std::get<2>(toWrite) << " " << std::get<3>(toWrite) << " ";
            }

            //Cannot have an extra ' ' at the end of the line
            std::tuple<int, int, int, double> toWrite = element.getPixel(hIndex, this->width - 1);
            outputStream << std::get<0>(toWrite) << " " << std::get<1>(toWrite) << " " << std::get<2>(toWrite) << " " << std::get<3>(toWrite);

            outputStream << "\n";
        }
    }

}

void PixamaModel::openFileSlot(QString fileName)
{
    if(fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        emit displayErrorMessageSignal("Unable to open file", file.errorString());
        return;
    }

    QDataStream inputFile(&file);
    inputFile.setVersion(QDataStream::Qt_5_4);

    //inputFile >> "";

    //File format:
    //The height and width of a sprite frame specified by 2 integers with a space between followed by a \n newline.
    //The number of frames represented by a single integer followed by a newline.
    //Each frame in order from lowest to highest numbered. A frame is output by
    // starting at the top row and going to the bottom, list the pixels for each row as red green blue alpha values with spaces in-between two values. Finish a row with a newline. Do not add extra whitespace between color values or pixels or between rows or between frames.

}

void PixamaModel::copyFrameSlot(QImage *image)
{

    Frame newFrame;
    for(int xCounter = 0; xCounter < 100 ; xCounter++)
    {
        for(int yCounter = 0; yCounter < 100 ; yCounter++)
        {
            newFrame.pixels[xCounter][yCounter] = frameList.at(static_cast<unsigned long>(currentFrame)).pixels[xCounter][yCounter];
        }
    }
    frameList.push_back(newFrame);
    currentFrame = static_cast<int>(frameList.size()-1);
    std::cout << "copied frame" << std::endl;
    for(int xCounter = 0; xCounter < 100 ; xCounter++)
    {
        for(int yCounter = 0; yCounter < 100 ; yCounter++)
        {
            for(int pixelSizeCounterX = 0; pixelSizeCounterX < pixelSize; pixelSizeCounterX++)
            {
                for(int pixelSizeCounterY = 0; pixelSizeCounterY < pixelSize; pixelSizeCounterY++)
                {
                image->setPixelColor( pixelSize*xCounter + pixelSizeCounterX, pixelSize*yCounter + pixelSizeCounterY, frameList[static_cast<unsigned long>(currentFrame)].getColor(xCounter, yCounter) );
                }
            }
        }
    }
    std::cout << "Displayed new frame" << std::endl;
}
