#include "pixamawindow.h"
#include "ui_pixamawindow.h"

PixamaWindow::PixamaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PixamaWindow)
{
    ui->setupUi(this);
}

PixamaWindow::~PixamaWindow()
{
    delete ui;
}
