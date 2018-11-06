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
    QObject::connect(&window, (void (PixamaWindow::*)(QString))&PixamaWindow::saveFileSignal, &model, &PixamaModel::saveFileSlot);
    QObject::connect(&model, (void (PixamaModel::*)(QString, QString))&PixamaModel::displayErrorMessageSignal, &window, &PixamaWindow::displayErrorMessageSlot);
    QObject::connect(&window, (void (PixamaWindow::*)(QString))&PixamaWindow::openFileSignal, &model, &PixamaModel::openFileSlot);

    return a.exec();
}
