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
    ~PixamaWindow();

private:
    Ui::PixamaWindow *ui;
};

#endif // PIXAMAWINDOW_H
