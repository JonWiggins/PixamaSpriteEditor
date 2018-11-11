#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T10:02:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pixama
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        pixamawindow.cpp \
    frame.cpp \
    pixamamodel.cpp \
    magickhandler.cpp

HEADERS += \
        pixamawindow.h \
    frame.h \
    pixamamodel.h \
    magickhandler.h \

FORMS += \
        pixamawindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagick++-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagickCore-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagickWand-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKLibs/ImageMagick-7.0.8
DEPENDPATH += $$PWD/MagicKLibs/ImageMagick-7.0.8

unix:!macx: PRE_TARGETDEPS += $$PWD/MagicKLibs/libMagickWand-7.Q16HDRI.a
