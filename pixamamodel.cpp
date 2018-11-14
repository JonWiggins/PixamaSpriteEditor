/* CS 3505 A7: Sprite Editor
 *
 * Purpose: This Model serves as the backing logic frame for the Sprite Editor
 * It handles all of the user actions, which it recives in its slots, from signals sent from the Window
 * It keeps track of a vector of Frames which represent the curernt sprite project
 * It holds a MagicKHandler object which it uses to export projects.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */


#include "pixamamodel.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

PixamaModel::PixamaModel()
{
    this->magick = new MagicKHandler();

    this->height = 32;
    this->width = 32;
    this->pixelSize = 500/32; //Assuming pixels are square
    this->currentFrame = 0; //Sets the currentFrame to the first frame
    this->playFrame = 0;

    Frame* firstFrame = new Frame(width, height);
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            firstFrame->setPixel(i, j, 0, 0, 0, 0);
        }
    }

    this->frameList.push_back(firstFrame);
    this->currentColor = std::make_tuple<int, int, int, int>(0, 0, 0, 0); //Current color at startup is transparent
    this->currentTool = 0; //starting tool is single pixel draw
}

//Changes color of backing
void PixamaModel::colorChangeSlot(std::tuple<int, int, int, int> color)
{
    this->currentColor = color;
}

//Changing what the current tool is
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
    //Or if they are below 0
    if(x < 0 || y < 0)
    {
        return;
    }
    //Draw using the current tool for deciding what to do
    draw(x, y);
}

void PixamaModel::draw(int x, int y)
{
    Frame* frame = this->frameList[static_cast<unsigned int>(currentFrame)];
    switch(this->currentTool) //Using switch for possibility of new tools
    {
        case 0:  //draw/erase tool
        {
            //Colors the pixel in the backing array and image then displaying it
            colorPixel(x, y, frame);
            emit imageSignal(frame->image->scaled(500, 500));
            break;
        }
        case 1: //bucket tool
        {
            //No use to use bucket tool of same color on the color so ends if they are equal
            if(frame->getPixel(x, y) == currentColor)
            {
                break;
            }
            //Creating a stack and adding the first position to start filling the bucket
            std::stack<std::tuple<int, int>> stack;
            stack.push(std::make_tuple(x, y));
            //initalizing values
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

                reachedLeft = false;
                reachedRight = false;

                //While going down coloring pixels check left and right to see if they need to be colored
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
            emit imageSignal(frame->image->scaled(500, 500));
            break;
        }
        case 2: // Move tool
        {
            x = x - width/2;
            y = y - height/2;
            Frame* holder = new Frame(width, height);

            for(int xCounter = 0; xCounter + x < width; xCounter++)
            {
                for(int yCounter = 0; yCounter + y < height; yCounter++)
                {

                    if(yCounter + y > 0)
                    {
                        if(xCounter + x > 0)
                        {
                             holder->setPixel(xCounter + x, yCounter + y, frame->getPixel(xCounter, yCounter));
                        }
                    }

                }
            }



            for(int xCounter = 0; xCounter < width; xCounter++)
            {
                for(int yCounter = 0; yCounter < height; yCounter++)
                {
                    if(holder->getColor(xCounter, yCounter) == QColor(0, 0, 0, 0))
                    {
                        frame->image->setPixelColor(xCounter, yCounter, QColor(255, 255, 255, 255));
                    }
                    else
                    {
                        holder->image->setPixelColor(xCounter, yCounter, holder->getColor(xCounter, yCounter));
                    }
                }
            }
            frame = holder;
            frameList[static_cast<unsigned long>(this->currentFrame)] = holder;
            this->currentTool = 0;
            emit imageSignal(frame->image->scaled(500, 500));
            break;
        }
    }
}

//Helper method to color the backing array pixel and image
void PixamaModel::colorPixel(int x, int y, Frame *frame)
{
    frame->setPixel(x, y, std::get<0>(this->currentColor), std::get<1>(this->currentColor), std::get<2>(this->currentColor), std::get<3>(this->currentColor));
    //If color is transparent, display it as white to help viability
    if(frame->getColor(x, y) == QColor(0, 0, 0, 0))
    {
        frame->image->setPixelColor(x, y, QColor(255, 255, 255, 255));
    }
    else
    {
        frame->image->setPixelColor(x, y, frame->getColor(x, y));
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
    inputFile >> width;

    //The number of frames represented by a single integer followed by a newline.
    int frameCount;
    inputFile >> frameCount;

    //Each frame in order from lowest to highest numbered. A frame is output by
    // starting at the top row and going to the bottom, list the pixels for each row as red green blue alpha values with spaces in-between two values. Finish a row with a newline. Do not add extra whitespace between color values or pixels or between rows or between frames.
    for(int frameCounter = 0; frameCounter < frameCount; frameCounter++)
    {

        Frame* toAdd = new Frame(height, width);
        for(int wCounter = 0; wCounter < width; wCounter++)

        {
            for(int hCounter = 0; hCounter < height; hCounter++)
            {
                int r, g, b, a;
                inputFile >> r;
                inputFile >> g;
                inputFile >> b;
                inputFile >> a;

                toAdd->setPixel(wCounter, hCounter, r, g, b, a);
                toAdd->image->setPixelColor(wCounter, hCounter, QColor(r, g, b, a) );

            }
        }

        frameList.push_back(toAdd);
    }

    this->width = width;
    this->height = height;

    std::vector<int> state;
    state.push_back(static_cast<int>(frameList.size()));
    state.push_back(currentFrame + 1);
    emit frameStateSignal(state);
    emit imageSignal(frameList[static_cast<int>(0)]->image->scaled(width*pixelSize, height*pixelSize));
}

//Copies the current frame the user is using and making a new one at end of list
void PixamaModel::copyFrameSlot()
{

    Frame* newFrame = new Frame(width, height);
    Frame* thisFrame = frameList[static_cast<unsigned long>(this->currentFrame)];
    //Copying the original frames backing array to new frames backing array
    for(int xCounter = 0; xCounter < width ; xCounter++)
    {
        for(int yCounter = 0; yCounter < height ; yCounter++)
        {
            newFrame->setPixel(xCounter, yCounter, thisFrame->pixels[xCounter][yCounter]);
        }
    }
    frameList.push_back(newFrame);
    currentFrame = static_cast<int>(frameList.size()-1);
    //Setting up the new image with transparent displaying as white
    for(int xCounter = 0; xCounter < width ; xCounter++)
    {
        for(int yCounter = 0; yCounter < height ; yCounter++)
        {
            if(newFrame->getColor(xCounter, yCounter) == QColor(0, 0, 0, 0))
            {
                newFrame->image->setPixelColor( xCounter, yCounter, QColor(255, 255, 255, 255) );

            }
            else
            {
                newFrame->image->setPixelColor( xCounter, yCounter, newFrame->getColor(xCounter, yCounter) );

            }
        }
    }

    std::vector<int> state;
    state.push_back(static_cast<int>(frameList.size()));
    state.push_back(currentFrame + 1);
    emit frameStateSignal(state);
    emit imageSignal(newFrame->image->scaled(500, 500));
}

//Creating a new empty frame
void PixamaModel::newFrameSlot()
{
    //initalizing new backing frame data
    Frame* newFrame = new Frame(width, height);
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            newFrame->setPixel(i, j, 0, 0, 0, 0);
        }
    }

    frameList.push_back(newFrame);
    currentFrame = static_cast<int>(frameList.size() - 1);

    //Coloring new backing frame image
    for(int xCounter = 0; xCounter < 100 ; xCounter++)
    {
        for(int yCounter = 0; yCounter < 100 ; yCounter++)
        {
            if(newFrame->getColor(xCounter, yCounter) == QColor(0, 0, 0, 0))
            {
                newFrame->image->setPixelColor( xCounter, yCounter, QColor(255, 255, 255, 255) );

            }
            else
            {
                newFrame->image->setPixelColor( xCounter, yCounter, newFrame->getColor(xCounter, yCounter) );

            }
        }
    }

    std::vector<int> state;
    state.push_back(static_cast<int>(frameList.size()));
    state.push_back(currentFrame + 1);
    emit frameStateSignal(state);
    emit imageSignal(newFrame->image->scaled(500, 500));
}

void PixamaModel::resizeSlot(int x, int y)
{
    if (x > 100 || x < 1)
    {
        return;
    }
    if (y > 100 || y < 1)
    {
        return;
    }
    width = x;
    height = y;
    if(x > y)
    {
        pixelSize = 500 / x;
    }
    else
    {
        pixelSize = 500 / y;
    }
    Frame* frame;
    for(int frameCount = 0; frameCount < static_cast<unsigned int>(frameList.size());frameCount++ )
    {
        frame = this->frameList[static_cast<unsigned int>(frameCount)];
        if(width > height)
        {
            frame->image = new QImage(width, width, QImage::Format_RGB32);
            for(int i = 0; i<width; i++)
            {
                for(int j = 0; j<width; j++)
                {
                    frame->image->setPixel(i, j, qRgba(255, 255, 255, 255));
                }
            }
        }
        else
        {
            frame->image = new QImage(height, height, QImage::Format_RGB32);
            for(int i = 0; i<height; i++)
            {
                for(int j = 0; j<height; j++)
                {
                    frame->image->setPixel(i, j, qRgba(255, 255, 255, 255));
                }
            }
        }
        for(int xCounter = 0; xCounter < width; xCounter++)
        {
            for(int yCounter = 0; yCounter < height; yCounter++)
            {
                if(frame->getColor(xCounter, yCounter) == QColor(0, 0, 0, 0))
                {
                    frame->image->setPixelColor(xCounter, yCounter, QColor(255, 255, 255, 255));
                }
                else
                   {
                    frame->image->setPixelColor(xCounter, yCounter, frame->getColor(xCounter, yCounter));
                }
            }
        }

    }
    frame = this->frameList[static_cast<unsigned int>(currentFrame)];
    emit imageSignal(frame->image->scaled(500, 500));
}

void PixamaModel::selectFrameSlot(int frameNumber)
{
    currentFrame = frameNumber - 1;
    emit imageSignal(frameList[static_cast<unsigned long>(currentFrame)]->image->scaled(500, 500));

}

void PixamaModel::exportAsPNGSlot(QString fileName)
{
    this->magick->exportSingleFrame(fileName, "PNG", frameList[static_cast<unsigned long>(currentFrame)], this->height, this->width);
}

void PixamaModel::exportAsJPGSlot(QString fileName)
{
    this->magick->exportSingleFrame(fileName, "JPG", frameList[static_cast<unsigned long>(currentFrame)], this->height, this->width);

}

void PixamaModel::exportFrameAsGIFSlot(QString fileName)
{
    this->magick->exportSingleFrame(fileName, "GIF", frameList[static_cast<unsigned long>(currentFrame)], this->height, this->width);
}

void PixamaModel::exportAsGIFSlot(QString fileName, int fps)
{
    this->magick->exportAsAnimatedGIF(fileName, frameList, this->height, this->width, fps);
}

void PixamaModel::playSlot()
{
    if (playFrame < static_cast<int>(frameList.size()))
    {
        emit playFrameSignal(frameList[static_cast<unsigned long>(playFrame)]->image->scaled(320, 320));
        playFrame++;
    }
    else
    {
        playFrame = 0;
    }
}
