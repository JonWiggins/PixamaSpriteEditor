/* CS 3505 A7: Sprite Editor
 *
 * Purpose: This window class represents the view for the Sprite Editor
 * It's constructor creates a model and connects to it.
 * It then feeds all user actions to the model for processing through signals.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */

#ifndef PIXAMAWINDOW_H
#define PIXAMAWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <pixamamodel.h>
#include <tuple>

namespace Ui {
class PixamaWindow;
}

class PixamaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PixamaWindow(QWidget *parent = nullptr);
    ~PixamaWindow() override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void openButtonClicked();
    void buttonDownScreenPos(QGraphicsSceneMouseEvent *event);
    void updateCanvas(QImage image);

private:
    Ui::PixamaWindow *ui;
    PixamaModel model;
    QGraphicsScene *graphic;


signals:
    void mouseClickSignal(int x, int y);
    void colorButtonSignal(std::tuple<int, int, int, int> color);
    void toolSelect(int tool);
    void saveFileSignal(QString fileName);
    void openFileSignal(QString fileName);
    void exportAsPNGSignal(QString fileName);
    void exportAsJPGSignal(QString fileName);
    void exportFrameAsGIFSignal(QString fileName);
    void newFrameSignal();
    void copyFrameSignal();

public slots:
       void displayErrorMessageSlot(QString title, QString details);
       void updateImageSlot(QImage image);
private slots:
       void on_resizeButton_clicked();
       void on_copyButton_clicked();
       void on_color_clicked();
       void on_eraseButton_clicked();
       void on_drawButton_clicked();
       void on_SaveTest_clicked();
       void on_bucketButton_clicked();
       void on_OpenTest_clicked();
       void on_NewFrame_clicked();
       void on_ExportAsPNG_clicked();
       void on_ExportFrameGIF_clicked();
       void on_ExportJPG_clicked();
       void on_saveButton_triggered();
       void on_actionLoad_triggered();
};

#endif // PIXAMAWINDOW_H
