#include "pixamawindow.h"
#include "ui_pixamawindow.h"
#include <QtWidgets>
#include <iostream>
#include <QMessageBox>

PixamaWindow::PixamaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PixamaWindow)
{
    ui->setupUi(this);

    //Connections from view -> model
    QObject::connect(
                this, &PixamaWindow::mouseClickSignal,
                &model, &PixamaModel::mouseEventSlot);
    QObject::connect(
                this, &PixamaWindow::saveFileSignal,
                &model, &PixamaModel::saveFileSlot);
    QObject::connect(
                this, &PixamaWindow::openFileSignal,
                     &model, &PixamaModel::openFileSlot);

    //Connections from model -> view
    QObject::connect(
                &model, &PixamaModel::displayErrorMessageSignal,
                     this, &PixamaWindow::displayErrorMessageSlot);

}

PixamaWindow::~PixamaWindow()
{
    delete ui;
}

void PixamaWindow::mousePressEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal(static_cast<int>(event->localPos().x()), static_cast<int>(event->localPos().y()));
}

void PixamaWindow::mouseMoveEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal(static_cast<int>(event->localPos().x()), static_cast<int>(event->localPos().y()));

}

void PixamaWindow::mouseReleaseEvent(QMouseEvent *event)
{
    std::cout << "x " << event->localPos().x() - 100 << " y " << event->localPos().y() - 90 << std::endl;
    emit mouseClickSignal(static_cast<int>(event->localPos().x()), static_cast<int>(event->localPos().y()));

}


void PixamaWindow::saveButtonClicked(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit saveFileSignal(fileName);
}

void PixamaWindow::displayErrorMessageSlot(QString title, QString details){
    QMessageBox::information(this, tr(title.toStdString().c_str()), details);

}

void PixamaWindow::openButtonClicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit openFileSignal(fileName);
}

