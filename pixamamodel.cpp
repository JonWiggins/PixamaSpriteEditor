#include "pixamamodel.h"
#include <iostream>
#include <tuple>
#include <QFile>
#include <QDataStream>

PixamaModel::PixamaModel()
{

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

    //TODO output all values here
    outputStream << " ";

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

    //TODO save all the values here
    //inputFile >> "";
}
