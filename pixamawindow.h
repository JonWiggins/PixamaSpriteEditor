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
    void mouseReleaseEvent(QMouseEvent *event) override;
    void saveButtonClicked();
    void openButtonClicked();
    void buttonDownScreenPos(QGraphicsSceneMouseEvent *event);
    void updateCanvas();

private:
    Ui::PixamaWindow *ui;
    PixamaModel model;
    QImage *image;
    QGraphicsScene *graphic;


signals:
    void mouseClickSignal(int x, int y);
    void colorButtonSignal(std::tuple<int, int, int, double> color);
    void toolSelect(int tool);
    void saveFileSignal(QString fileName);
    void openFileSignal(QString fileName);
    void copyFrameSignal(QImage *image);

public slots:
       void displayErrorMessageSlot(QString title, QString details);
private slots:
       void on_resizeButton_clicked();
       void on_copyButton_clicked();
       void on_color_clicked();
       void on_eraseButton_clicked();
       void on_drawButton_clicked();
};

#endif // PIXAMAWINDOW_H
