#include "pixamawindow.h"
#include "ui_pixamawindow.h"
#include <QtWidgets>
#include <iostream>

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

void PixamaWindow::mousePressEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal((int) event->localPos().x(), (int)event->localPos().y());
}

void PixamaWindow::mouseMoveEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal((int) event->localPos().x(), (int)event->localPos().y());

}

void PixamaWindow::mouseReleaseEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal((int) event->localPos().x(), (int)event->localPos().y());

}
