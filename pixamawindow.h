#ifndef PIXAMAWINDOW_H
#define PIXAMAWINDOW_H

#include <QMainWindow>

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

private:
    Ui::PixamaWindow *ui;

signals:
    void mouseClickSignal(int x, int y);
    void saveFileSignal(QString fileName);
    void openFileSignal(QString fileName);

public slots:
       void displayErrorMessageSlot(QString title, QString details);
};

#endif // PIXAMAWINDOW_H
