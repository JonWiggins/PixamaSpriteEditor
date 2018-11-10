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

    Frame* firstFrame = new Frame();
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            firstFrame->setPixel(i, j, 0, 0, 0, 0.0); //Setting a pixel in the frame to be green
        }
    }

    this->image = new QImage(500, 500, QImage::Format_RGB32);
    for(int i = 0; i<500; i++)
    {
        for(int j = 0; j<500; j++)
        {
            image->setPixel(i, j, qRgba(0, 0, 0, 0.0));

        }
    }

    emit imageSignal(image);
    this->frameList.push_back(firstFrame);
    this->currentColor = std::make_tuple<int, int, int, int>(0, 0, 0, 0.0); //Current color at startup is transparent
    this->currentTool = 0; //starting tool is single pixel draw
}

//Changes color of backing
void PixamaModel::colorChangeSlot(std::tuple<int, int, int, int> color)
{
    this->currentColor = color;
}

void PixamaModel::toolSelectSlot(int tool)
{
    this->currentTool = tool;
}

//When mouse is clicked on frame
void PixamaModel::mouseEventSlot(int x, int y)
{
    //Changing x and y to the size of pixels
    x = x / this->pixelSize;
    y = y / this->pixelSize;

    //Checking to make sure x and y are bigger than the current bounds
    if(x >= this->width || y >= this->height)
    {
        return;
    }
    draw(x, y);
}

void PixamaModel::draw(int x, int y)
{
    Frame* frame = this->frameList[static_cast<unsigned int>(currentFrame)];
    switch(this->currentTool) //Using switch for possibility of new tools
    {
        case 0:  //draw/erase tool
        {
            colorPixel(x, y, frame);
            break;
        }
        case 1: //bucket tool
        {
            //Creating a stack and adding the first position to start filling the bucket
            std::stack<std::tuple<int, int>> stack;
            stack.push(std::make_tuple(x, y));
            QColor startColor = frame->getColor(x, y);
            int x;
            int y;
            bool reachedLeft, reachedRight;
            while(!stack.empty())
            {
                std::tuple<int, int> currentPixel = stack.top();
                stack.pop();
                x = std::get<0>(currentPixel);
                y = std::get<1>(currentPixel);
                while(y-- > 0 && startColor == frame->getColor(x, y)) {} //travels up to the top

                y++;
                reachedLeft = false;
                reachedRight = false;

                while(y++ < this->height - 1 && startColor == frame->getColor(x, y))
                {
                    //First color the pixel
                    colorPixel(x, y, frame);

                    if(x > 0) //Check if you can go left
                    {
                        if(startColor == frame->getColor(x - 1, y))
                        {
                            if(!reachedLeft)
                            {
                                stack.push(std::make_tuple(x - 1, y));
                                reachedLeft = true;
                            }
                        }
                        else if(reachedLeft)
                        {
                            reachedLeft = false;
                        }
                    }
                    if(x < this->width - 1) //Check if you can go right
                    {
                        if(startColor == frame->getColor(x + 1, y))
                        {
                            if(!reachedRight)
                            {
                                stack.push(std::make_tuple(x + 1, y));
                                reachedRight = true;
                            }
                        }
                        else if(reachedRight)
                        {
                            reachedRight = false;
                        }
                    }
                }
            }
            break;
        }
    }
}

void PixamaModel::colorPixel(int x, int y, Frame *frame)
{
    frame->setPixel(x, y, std::get<0>(this->currentColor), std::get<1>(this->currentColor), std::get<2>(this->currentColor), std::get<3>(this->currentColor));
    for(int pixelSizeCounterX = 0; pixelSizeCounterX < pixelSize; pixelSizeCounterX++)
    {
        for(int pixelSizeCounterY = 0; pixelSizeCounterY < pixelSize; pixelSizeCounterY++)
        {
            image->setPixelColor(x*pixelSize + pixelSizeCounterX, y*pixelSize + pixelSizeCounterY, frame->getColor(x, y));
        }
    }
    emit imageSignal(image);
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
    for(Frame* element : frameList)
    {
        for(int hIndex = 0; hIndex < this->height; hIndex ++)
        {
            for(int wIndex = 0; wIndex < this->width - 1; wIndex++)
            {
                std::tuple<int, int, int, int> toWrite = element->getPixel(hIndex, wIndex);
                outputStream << std::get<0>(toWrite) << " " << std::get<1>(toWrite) << " " << std::get<2>(toWrite) << " " << std::get<3>(toWrite) << " ";
            }

            //Cannot have an extra ' ' at the end of the line
            std::tuple<int, int, int, int> toWrite = element->getPixel(hIndex, this->width - 1);
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

    //clear the current frames
    frameList.clear();

    QTextStream inputFile(&file);

    //File format:
    //The height and width of a sprite frame specified by 2 integers with a space between followed by a \n newline.
    int height;
    int width;

    inputFile >> height;
    //std::cout << "height " << height << std::endl;

    inputFile >> width;
    //std::cout << "width " << width << std::endl;

    //The number of frames represented by a single integer followed by a newline.
    int frameCount;
    inputFile >> frameCount;

    //std::cout << "count " << frameCount << std::endl;

    //Each frame in order from lowest to highest numbered. A frame is output by
    // starting at the top row and going to the bottom, list the pixels for each row as red green blue alpha values with spaces in-between two values. Finish a row with a newline. Do not add extra whitespace between color values or pixels or between rows or between frames.
    for(int frameCounter = 0; frameCounter < frameCount; frameCounter++)
    {
        Frame* toAdd = new Frame();
        for(int hCounter = 0; hCounter < height; hCounter++)
        {
            for(int wCounter = 0; wCounter < width; wCounter++)
            {
                int r, g, b, a;
                inputFile >> r;
                inputFile >> g;
                inputFile >> b;
                inputFile >> a;

                toAdd->setPixel(hCounter, wCounter, r, g, b, a);

                //TODO this needs to update the canvas
                //draw()

            }
        }

        frameList.push_back(toAdd);

    }
}

void PixamaModel::copyFrameSlot(QImage *image)
{

    Frame* newFrame = new Frame();
    for(int xCounter = 0; xCounter < 100 ; xCounter++)
    {
        for(int yCounter = 0; yCounter < 100 ; yCounter++)
        {
            newFrame->pixels[xCounter][yCounter] = frameList.at(static_cast<unsigned long>(currentFrame))->pixels[xCounter][yCounter];
        }
    }
    frameList.push_back(newFrame);
    currentFrame = static_cast<int>(frameList.size()-1);
    for(int xCounter = 0; xCounter < 100 ; xCounter++)
    {
        for(int yCounter = 0; yCounter < 100 ; yCounter++)
        {
            for(int pixelSizeCounterX = 0; pixelSizeCounterX < pixelSize; pixelSizeCounterX++)
            {
                for(int pixelSizeCounterY = 0; pixelSizeCounterY < pixelSize; pixelSizeCounterY++)
                {
                image->setPixelColor( pixelSize*xCounter + pixelSizeCounterX, pixelSize*yCounter + pixelSizeCounterY, frameList[static_cast<unsigned long>(currentFrame)]->getColor(xCounter, yCounter) );
                }
            }
        }
    }
    std::cout << "Displayed new frame" << std::endl;
}
