#ifndef PIXAMAWINDOW_H
#define PIXAMAWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <pixamamodel.h>

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
    void saveButtonClicked();
    void openButtonClicked();
    void buttonDownScreenPos(QGraphicsSceneMouseEvent *event);

private:
    Ui::PixamaWindow *ui;
    PixamaModel model;

signals:
    void mouseClickSignal(int x, int y);
    void saveFileSignal(QString fileName);
    void openFileSignal(QString fileName);

public slots:
       void displayErrorMessageSlot(QString title, QString details);
};

#endif // PIXAMAWINDOW_H
