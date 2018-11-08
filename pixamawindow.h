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
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
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
    void copyFrameSignal();

public slots:
       void displayErrorMessageSlot(QString title, QString details);
private slots:
       void on_resizeButton_clicked();
       void on_copyButton_clicked();
};

#endif // PIXAMAWINDOW_H
