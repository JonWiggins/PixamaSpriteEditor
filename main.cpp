/* CS 3505 A7: Sprite Editor
 *
 * Purpose: Sprite Editor was made for CS 3505.
 * It enables users to select colors, draw on frames, add frames, and export sprites as .ssp as well as
 *  animated gif files.
 * This project was created along the software specifications outlined in the A6, planning phase
 *  software documents.
 * This main class creates a Sprite Editor window and displays it.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */

#include "pixamawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixamaWindow window;
    window.show();
    return a.exec();
}
