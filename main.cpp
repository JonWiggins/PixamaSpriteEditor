#include "pixamawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixamaWindow window;
    window.show();

    return a.exec();
}
