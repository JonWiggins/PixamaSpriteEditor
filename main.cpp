#include "pixamawindow.h"
#include "pixamamodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixamaWindow window;
    PixamaModel model;
    window.show();

    QObject::connect(&window, (void (PixamaWindow::*)(int, int))&PixamaWindow::mouseClickSignal, &model, &PixamaModel::mouseEventSlot);


    return a.exec();
}
