/********************************************************************************
** Form generated from reading UI file 'pixamawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXAMAWINDOW_H
#define UI_PIXAMAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PixamaWindow
{
public:
    QAction *saveButton;
    QAction *actionLoad;
    QAction *actionClose;
    QAction *actionExport;
    QWidget *centralWidget;
    QGraphicsView *canvas;
    QPushButton *drawButton;
    QPushButton *eraseButton;
    QGraphicsView *preview;
    QPushButton *copyButton;
    QPushButton *moveButton;
    QPushButton *resizeButton;
    QSlider *frameRateSlider;
    QLabel *frameRateLabel;
    QPushButton *bucketButton;
    QLabel *labelR;
    QLabel *labelG;
    QLabel *labelB;
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;
    QLabel *labelA;
    QSlider *sliderA;
    QSpinBox *spinBoxR;
    QSpinBox *spinBoxG;
    QSpinBox *spinBoxB;
    QSpinBox *frameRateSpinBox;
    QPushButton *color;
    QPushButton *SaveTest;
    QSpinBox *spinBoxA;
    QPushButton *OpenTest;
    QPushButton *NewFrame;
    QPushButton *ExportAsPNG;
    QPushButton *ExportFrameGIF;
    QPushButton *ExportJPG;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PixamaWindow)
    {
        if (PixamaWindow->objectName().isEmpty())
            PixamaWindow->setObjectName(QStringLiteral("PixamaWindow"));
        PixamaWindow->resize(886, 629);
        saveButton = new QAction(PixamaWindow);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        actionLoad = new QAction(PixamaWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionClose = new QAction(PixamaWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionExport = new QAction(PixamaWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(PixamaWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        canvas = new QGraphicsView(centralWidget);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setEnabled(false);
        canvas->setGeometry(QRect(20, 20, 500, 500));
        canvas->setAutoFillBackground(false);
        canvas->setInteractive(true);
        canvas->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        drawButton = new QPushButton(centralWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(550, 410, 90, 25));
        eraseButton = new QPushButton(centralWidget);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(655, 410, 90, 25));
        preview = new QGraphicsView(centralWidget);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setEnabled(false);
        preview->setGeometry(QRect(540, 20, 320, 320));
        preview->setInteractive(true);
        copyButton = new QPushButton(centralWidget);
        copyButton->setObjectName(QStringLiteral("copyButton"));
        copyButton->setGeometry(QRect(552, 370, 90, 25));
        moveButton = new QPushButton(centralWidget);
        moveButton->setObjectName(QStringLiteral("moveButton"));
        moveButton->setGeometry(QRect(655, 370, 90, 25));
        resizeButton = new QPushButton(centralWidget);
        resizeButton->setObjectName(QStringLiteral("resizeButton"));
        resizeButton->setGeometry(QRect(758, 370, 90, 25));
        frameRateSlider = new QSlider(centralWidget);
        frameRateSlider->setObjectName(QStringLiteral("frameRateSlider"));
        frameRateSlider->setGeometry(QRect(630, 340, 201, 25));
        frameRateSlider->setMinimum(1);
        frameRateSlider->setMaximum(30);
        frameRateSlider->setValue(30);
        frameRateSlider->setOrientation(Qt::Horizontal);
        frameRateLabel = new QLabel(centralWidget);
        frameRateLabel->setObjectName(QStringLiteral("frameRateLabel"));
        frameRateLabel->setGeometry(QRect(540, 340, 80, 25));
        bucketButton = new QPushButton(centralWidget);
        bucketButton->setObjectName(QStringLiteral("bucketButton"));
        bucketButton->setGeometry(QRect(758, 410, 90, 25));
        labelR = new QLabel(centralWidget);
        labelR->setObjectName(QStringLiteral("labelR"));
        labelR->setGeometry(QRect(540, 440, 20, 20));
        labelG = new QLabel(centralWidget);
        labelG->setObjectName(QStringLiteral("labelG"));
        labelG->setGeometry(QRect(540, 465, 20, 20));
        labelB = new QLabel(centralWidget);
        labelB->setObjectName(QStringLiteral("labelB"));
        labelB->setGeometry(QRect(540, 490, 20, 20));
        sliderR = new QSlider(centralWidget);
        sliderR->setObjectName(QStringLiteral("sliderR"));
        sliderR->setGeometry(QRect(560, 440, 251, 23));
        sliderR->setMinimum(0);
        sliderR->setMaximum(255);
        sliderR->setValue(0);
        sliderR->setOrientation(Qt::Horizontal);
        sliderG = new QSlider(centralWidget);
        sliderG->setObjectName(QStringLiteral("sliderG"));
        sliderG->setGeometry(QRect(560, 465, 251, 23));
        sliderG->setMinimum(0);
        sliderG->setMaximum(255);
        sliderG->setValue(0);
        sliderG->setOrientation(Qt::Horizontal);
        sliderB = new QSlider(centralWidget);
        sliderB->setObjectName(QStringLiteral("sliderB"));
        sliderB->setGeometry(QRect(560, 490, 251, 23));
        sliderB->setMinimum(0);
        sliderB->setMaximum(255);
        sliderB->setValue(0);
        sliderB->setOrientation(Qt::Horizontal);
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QStringLiteral("labelA"));
        labelA->setGeometry(QRect(540, 515, 20, 20));
        sliderA = new QSlider(centralWidget);
        sliderA->setObjectName(QStringLiteral("sliderA"));
        sliderA->setGeometry(QRect(560, 515, 251, 23));
        sliderA->setMinimum(0);
        sliderA->setMaximum(255);
        sliderA->setSingleStep(1);
        sliderA->setValue(0);
        sliderA->setOrientation(Qt::Horizontal);
        spinBoxR = new QSpinBox(centralWidget);
        spinBoxR->setObjectName(QStringLiteral("spinBoxR"));
        spinBoxR->setGeometry(QRect(822, 442, 57, 21));
        spinBoxR->setMaximum(255);
        spinBoxG = new QSpinBox(centralWidget);
        spinBoxG->setObjectName(QStringLiteral("spinBoxG"));
        spinBoxG->setGeometry(QRect(822, 465, 57, 21));
        spinBoxG->setMaximum(255);
        spinBoxB = new QSpinBox(centralWidget);
        spinBoxB->setObjectName(QStringLiteral("spinBoxB"));
        spinBoxB->setGeometry(QRect(822, 490, 57, 21));
        spinBoxB->setMaximum(255);
        frameRateSpinBox = new QSpinBox(centralWidget);
        frameRateSpinBox->setObjectName(QStringLiteral("frameRateSpinBox"));
        frameRateSpinBox->setGeometry(QRect(840, 340, 42, 22));
        frameRateSpinBox->setMaximum(30);
        frameRateSpinBox->setValue(30);
        color = new QPushButton(centralWidget);
        color->setObjectName(QStringLiteral("color"));
        color->setGeometry(QRect(640, 540, 111, 25));
        SaveTest = new QPushButton(centralWidget);
        SaveTest->setObjectName(QStringLiteral("SaveTest"));
        SaveTest->setGeometry(QRect(10, 540, 89, 25));
        spinBoxA = new QSpinBox(centralWidget);
        spinBoxA->setObjectName(QStringLiteral("spinBoxA"));
        spinBoxA->setGeometry(QRect(822, 515, 57, 21));
        spinBoxA->setMaximum(255);
        OpenTest = new QPushButton(centralWidget);
        OpenTest->setObjectName(QStringLiteral("OpenTest"));
        OpenTest->setGeometry(QRect(110, 540, 89, 25));
        NewFrame = new QPushButton(centralWidget);
        NewFrame->setObjectName(QStringLiteral("NewFrame"));
        NewFrame->setGeometry(QRect(530, 540, 89, 25));
        ExportAsPNG = new QPushButton(centralWidget);
        ExportAsPNG->setObjectName(QStringLiteral("ExportAsPNG"));
        ExportAsPNG->setGeometry(QRect(330, 540, 89, 25));
        ExportFrameGIF = new QPushButton(centralWidget);
        ExportFrameGIF->setObjectName(QStringLiteral("ExportFrameGIF"));
        ExportFrameGIF->setGeometry(QRect(210, 540, 111, 25));
        ExportJPG = new QPushButton(centralWidget);
        ExportJPG->setObjectName(QStringLiteral("ExportJPG"));
        ExportJPG->setGeometry(QRect(430, 540, 89, 25));
        PixamaWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PixamaWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        PixamaWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PixamaWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PixamaWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PixamaWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PixamaWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(saveButton);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionClose);

        retranslateUi(PixamaWindow);
        QObject::connect(sliderR, SIGNAL(valueChanged(int)), spinBoxR, SLOT(setValue(int)));
        QObject::connect(sliderG, SIGNAL(valueChanged(int)), spinBoxG, SLOT(setValue(int)));
        QObject::connect(sliderB, SIGNAL(valueChanged(int)), spinBoxB, SLOT(setValue(int)));
        QObject::connect(spinBoxB, SIGNAL(valueChanged(int)), sliderB, SLOT(setValue(int)));
        QObject::connect(spinBoxG, SIGNAL(valueChanged(int)), sliderG, SLOT(setValue(int)));
        QObject::connect(spinBoxR, SIGNAL(valueChanged(int)), sliderR, SLOT(setValue(int)));
        QObject::connect(frameRateSlider, SIGNAL(valueChanged(int)), frameRateSpinBox, SLOT(setValue(int)));
        QObject::connect(frameRateSpinBox, SIGNAL(valueChanged(int)), frameRateSlider, SLOT(setValue(int)));
        QObject::connect(spinBoxA, SIGNAL(valueChanged(int)), sliderA, SLOT(setValue(int)));
        QObject::connect(sliderA, SIGNAL(valueChanged(int)), spinBoxA, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(PixamaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PixamaWindow)
    {
        PixamaWindow->setWindowTitle(QApplication::translate("PixamaWindow", "PixamaWindow", nullptr));
        saveButton->setText(QApplication::translate("PixamaWindow", "Save", nullptr));
        actionLoad->setText(QApplication::translate("PixamaWindow", "Load", nullptr));
        actionClose->setText(QApplication::translate("PixamaWindow", "Close", nullptr));
        actionExport->setText(QApplication::translate("PixamaWindow", "Export", nullptr));
        drawButton->setText(QApplication::translate("PixamaWindow", "Draw", nullptr));
        eraseButton->setText(QApplication::translate("PixamaWindow", "Erase", nullptr));
        copyButton->setText(QApplication::translate("PixamaWindow", "Copy", nullptr));
        moveButton->setText(QApplication::translate("PixamaWindow", "Move", nullptr));
        resizeButton->setText(QApplication::translate("PixamaWindow", "Resize", nullptr));
        frameRateLabel->setText(QApplication::translate("PixamaWindow", "Frame Rate:", nullptr));
        bucketButton->setText(QApplication::translate("PixamaWindow", "Bucket", nullptr));
        labelR->setText(QApplication::translate("PixamaWindow", "R:", nullptr));
        labelG->setText(QApplication::translate("PixamaWindow", "G:", nullptr));
        labelB->setText(QApplication::translate("PixamaWindow", "B:", nullptr));
        labelA->setText(QApplication::translate("PixamaWindow", "A:", nullptr));
        color->setText(QApplication::translate("PixamaWindow", "Select Color", nullptr));
        SaveTest->setText(QApplication::translate("PixamaWindow", "Save Test", nullptr));
        OpenTest->setText(QApplication::translate("PixamaWindow", "OpenTest", nullptr));
        NewFrame->setText(QApplication::translate("PixamaWindow", "New Frame", nullptr));
        ExportAsPNG->setText(QApplication::translate("PixamaWindow", "Export PNG", nullptr));
        ExportFrameGIF->setText(QApplication::translate("PixamaWindow", "Export Frame", nullptr));
        ExportJPG->setText(QApplication::translate("PixamaWindow", "Export JPG", nullptr));
        menuFile->setTitle(QApplication::translate("PixamaWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PixamaWindow: public Ui_PixamaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXAMAWINDOW_H
