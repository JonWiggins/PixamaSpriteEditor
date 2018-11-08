#ifndef PIXAMAWINDOW_H
#define PIXAMAWINDOW_H

#include <QMainWindow>
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
    PixamaModel model;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void saveButtonClicked();
    void openButtonClicked();

private:
    Ui::PixamaWindow *ui;

signals:
    void mouseClickSignal(int x, int y);
    void saveFileSignal(QString fileName);
    void openFileSignal(QString fileName);

public slots:
       void displayErrorMessageSlot(QString title, QString details);
private slots:
       void on_bucketButton_clicked();
       void on_drawButton_clicked();
       void on_eraseButton_clicked();
       void on_copyButton_clicked();
       void on_moveButton_clicked();
       void on_resizeButton_clicked();
       void on_sliderR_sliderMoved(int position);
       void on_sliderG_sliderMoved(int position);
       void on_sliderB_actionTriggered(int action);
       void on_frameRateSlider_sliderMoved(int position);
};
#endif // PIXAMAWINDOW_H
