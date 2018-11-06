#include "pixamamodel.h"
#include <iostream>
#include <tuple>
#include <QFile>
#include <QDataStream>
#include <tuple>

PixamaModel::PixamaModel()
{
    //TODO replace these with meaningful values
    this->height = 100;
    this->width = 100;
}

void PixamaModel::mouseEventSlot(int x, int y){
    std::cout << "setting backing frame" << std::endl;
    Frame toChange = frameList.at(0);
    //toChange.setPixel(0,0, std::make_tuple(0, 0, 0, 0.0));
}

void PixamaModel::saveFileSlot(QString fileName){
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        emit displayErrorMessageSignal("Unable to Save File",file.errorString());
        return;
    }

    QDataStream outputStream(&file);


    //TODO ensure that this is correct
    outputStream.setVersion(QDataStream::Qt_5_4);


    //File format:
    //The height and width of a sprite frame specified by 2 integers with a space between followed by a \n newline.
    outputStream << this->height << " " << this->width << "\n";
    //The number of frames represented by a single integer followed by a newline.
    outputStream << static_cast<int>(this->frameList.size()) << "\n";
    //Each frame in order from lowest to highest numbered. A frame is output by
    // starting at the top row and going to the bottom, list the pixels for each row as red green blue alpha values with spaces in-between two values. Finish a row with a newline. Do not add extra whitespace between color values or pixels or between rows or between frames.
    for(auto &element : frameList){
        for(int hIndex = 0; hIndex < this->height; hIndex ++){
            for(int wIndex = 0; wIndex < this->width - 1; wIndex++){
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

void PixamaModel::openFileSlot(QString fileName){
    if(fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
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
