/* CS 3505 A7: Sprite Editor
 *
 * Purpose: This window class represents the view for the Sprite Editor
 * It's constructor creates a model and connects to it.
 * It then feeds all user actions to the model for processing through signals.
 *
 *
 * @author Zak Bastiani, Alex Fritz, Conner Soule, Ryan Outtrim, and Jonathan Wiggins
 * @version 11/11/18
 */


#include "pixamawindow.h"
#include "ui_pixamawindow.h"
#include <QtWidgets>
#include <iostream>
#include <QMessageBox>
#include <QTimer>

PixamaWindow::PixamaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PixamaWindow)
{
    ui->setupUi(this);

    graphic = new QGraphicsScene(this);
    previewGraphic = new QGraphicsScene(this);
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
                this, &PixamaWindow::exportFrameAsGIFSignal,
                &model, &PixamaModel::exportFrameAsGIFSlot);
    QObject::connect(
                this, &PixamaWindow::exportAsJPGSignal,
                &model, &PixamaModel::exportAsJPGSlot);
    QObject::connect(
                this, &PixamaWindow::exportAsPNGSignal,
                &model, &PixamaModel::exportAsPNGSlot);

    QObject::connect(
                this, &PixamaWindow::newFrameSignal,
                &model, &PixamaModel::newFrameSlot);
    QObject::connect(
                this, &PixamaWindow::selectFrameSignal,
                &model, &PixamaModel::selectFrameSlot);
    QObject::connect(
                this, &PixamaWindow::copyFrameSignal,
                &model, &PixamaModel::copyFrameSlot);

    QObject::connect(
                this, &PixamaWindow::colorButtonSignal,
                &model, &PixamaModel::colorChangeSlot);
    QObject::connect(
                this, &PixamaWindow::toolSelect,
                &model, &PixamaModel::toolSelectSlot);

    QObject::connect(
                this, &PixamaWindow::playSignal,
                &model, &PixamaModel::playSlot);


    //Connections from model -> view
    QObject::connect(
                &model, &PixamaModel::displayErrorMessageSignal,
                this, &PixamaWindow::displayErrorMessageSlot);
    QObject::connect(
                &model, &PixamaModel::imageSignal,
                this, &PixamaWindow::updateImageSlot);
    QObject::connect(
                &model, &PixamaModel::frameStateSignal,
                this, &PixamaWindow::updateFrameSelectSlot);
    QObject::connect(
                &model, &PixamaModel::playFrameSignal,
                this, &PixamaWindow::playFrameSlot);

}

PixamaWindow::~PixamaWindow()
{
    delete ui;
    delete graphic;
    delete previewGraphic;
}

void PixamaWindow::mousePressEvent(QMouseEvent *event)
{
    emit mouseClickSignal(static_cast<int>(event->localPos().x()-21), static_cast<int>(event->localPos().y()-63));
}

void PixamaWindow::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseClickSignal(static_cast<int>(event->localPos().x()-21), static_cast<int>(event->localPos().y()-63));
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
    int x = QInputDialog::getInt(this,
                                 tr("X Value"), "X Value:",
                                 100, 0, 100, 1);
    int y = QInputDialog::getInt(this,
                                 tr("Y Value"), "Y Value:",
                                 100, 0, 100, 1);
}


void PixamaWindow::on_copyButton_clicked()
{
    emit copyFrameSignal();
}

void PixamaWindow::updateImageSlot(QImage image)
{
    updateCanvas(image);
}

void PixamaWindow::playFrameSlot(QImage image)
{
    //Update preview
    previewGraphic->addPixmap((QPixmap::fromImage(image)));
    ui->preview->setScene(previewGraphic);
    ui->preview->show();

    int frameRate = ui->frameRateSpinBox->value();
    QTimer::singleShot(1000/frameRate, &model, SLOT(playSlot()));
}

void PixamaWindow::updateFrameSelectSlot(std::vector<int> frameState)
{
    ui->frameSelectSpinBox->setMaximum(frameState[0]);
    ui->frameSelectSpinBox->setValue(frameState[1]);
}

void PixamaWindow::updateCanvas(QImage image)
{
    graphic->addPixmap((QPixmap::fromImage(image)));
    ui->canvas->setScene(graphic);
    ui->canvas->show();
}

//When color button is clicked it takes the values from the sliders and sends it to the backing array as a color
void PixamaWindow::on_color_clicked()
{
    int red = ui->spinBoxR->value();
    int green = ui->spinBoxG->value();
    int blue = ui->spinBoxB->value();
    int alpha = ui->spinBoxA->value();
    std::tuple<int, int, int, int> color = std::make_tuple(red, green, blue, alpha);
    emit colorButtonSignal(color);
}

//When the erase button tool is clicked it
void PixamaWindow::on_eraseButton_clicked()
{
    std::tuple<int, int, int, int> empty = std::make_tuple(0, 0, 0, 0.0);
    emit colorButtonSignal(empty);
    emit toolSelect(0);
}

//The draw tool is selected
void PixamaWindow::on_drawButton_clicked()
{
    on_color_clicked();
    emit toolSelect(0);
}

void PixamaWindow::on_bucketButton_clicked()
{
    on_color_clicked();
    emit toolSelect(1);
}

void PixamaWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit saveFileSignal(fileName);
}

void PixamaWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Pixama Project"), "",
                                                    tr("Sprite Sheet Project (*.ssp)"));
    emit openFileSignal(fileName);
}

void PixamaWindow::on_newFrameButton_clicked()
{
    emit newFrameSignal();
}

void PixamaWindow::on_frameSelectSpinBox_valueChanged(int arg1)
{
    emit selectFrameSignal(arg1);
}

void PixamaWindow::on_actionGIF_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export Frame as GIF"), "",
                                                    tr("GIF(*.gif)"));
    emit exportFrameAsGIFSignal(fileName);
}

void PixamaWindow::on_actionPNG_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export Frame as PNG"), "",
                                                    tr("PNG (*.png)"));
    emit exportAsPNGSignal(fileName);
}

void PixamaWindow::on_actionJPG_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export Frame as JPG"), "",
                                                    tr("JPG(*.jpg)"));
    emit exportAsJPGSignal(fileName);
}

void PixamaWindow::on_playButton_clicked()
{
    emit playSignal();
}
