#include "pixamawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixamaWindow w;
    w.show();

    return a.exec();
}
