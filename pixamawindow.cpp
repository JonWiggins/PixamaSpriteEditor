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

    image = new QImage(500, 500, QImage::Format_RGB32);
    image->setDotsPerMeterX(1000);
    image->setDotsPerMeterY(1000);


    for(int i = 0; i<500; i++)
    {
        for(int j = 0; j<500; j++)
        {
            image->setPixel(i, j, qRgba(255, 255, 255, 1.0));
        }
    }

    graphic = new QGraphicsScene(this);
    graphic->addPixmap((QPixmap::fromImage(*image)));
    ui->canvas->setScene(graphic);

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
    QObject::connect(
                this, &PixamaWindow::copyFrameSignal,
                &model, &PixamaModel::copyFrameSlot);
    QObject::connect(
                this, &PixamaWindow::colorButtonSignal,
                &model, &PixamaModel::colorChangeSlot);
    QObject::connect(
                this, &PixamaWindow::toolSelect,
                &model, &PixamaModel::toolSelectSlot);


    //Connections from model -> view
    QObject::connect(
                &model, &PixamaModel::displayErrorMessageSignal,
                this, &PixamaWindow::displayErrorMessageSlot);

}

PixamaWindow::~PixamaWindow()
{
    delete ui;
    delete graphic;
}

void PixamaWindow::mousePressEvent(QMouseEvent *event)
{
    emit mouseClickSignal(static_cast<int>(event->localPos().x()-15), static_cast<int>(event->localPos().y()-50), image);
    updateCanvas();
}

void PixamaWindow::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseClickSignal(static_cast<int>(event->localPos().x()-15), static_cast<int>(event->localPos().y()-50), image);
    updateCanvas();
}

void PixamaWindow::mouseReleaseEvent(QMouseEvent *event)
{
    emit mouseClickSignal(static_cast<int>(event->localPos().x()-15), static_cast<int>(event->localPos().y()-50), image);
    updateCanvas();
}



void PixamaWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit saveFileSignal(fileName);
}

void PixamaWindow::displayErrorMessageSlot(QString title, QString details)
{
    QMessageBox::information(this, tr(title.toStdString().c_str()), details);

}

void PixamaWindow::openButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit openFileSignal(fileName);
}


void PixamaWindow::on_resizeButton_clicked()
{

}

void PixamaWindow::on_copyButton_clicked()
{
    emit copyFrameSignal(image);
    updateCanvas();
}

void PixamaWindow::updateCanvas()
{
    graphic->addPixmap((QPixmap::fromImage(*image)));
    ui->canvas->setScene(graphic);
    ui->canvas->show();
}

//When color button is clicked it takes the values from the sliders and sends it to the backing array as a color
void PixamaWindow::on_color_clicked()
{
    int red = ui->spinBoxR->value();
    int green = ui->spinBoxG->value();
    int blue = ui->spinBoxB->value();
    double alpha = ui->spinBoxA->value();
    std::tuple<int, int, int, double> color = std::make_tuple(red, green, blue, alpha);
    emit colorButtonSignal(color);
}

//When the erase button tool is clicked it
void PixamaWindow::on_eraseButton_clicked()
{
    std::tuple<int, int, int, double> empty = std::make_tuple(0, 0, 0, 0.0);
    emit colorButtonSignal(empty);
    emit toolSelect(0);
}

//The draw tool is selected
void PixamaWindow::on_drawButton_clicked()
{
    on_color_clicked();
    emit toolSelect(0);
}


void PixamaWindow::on_SaveTest_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit saveFileSignal(fileName);
}
