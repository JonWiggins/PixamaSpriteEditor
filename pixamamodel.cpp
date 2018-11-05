#include "pixamamodel.h"
#include <iostream>

PixamaModel::PixamaModel()
{

}

void PixamaModel::mouseEventSlot(int x, int y){
    std::cout << "setting backing frame" << std::endl;
    //Frame toChange = frameList.at(0);
    //toChange.setPixel(0,0, std::make_tuple(0, 0, 0, 0.0));
}
