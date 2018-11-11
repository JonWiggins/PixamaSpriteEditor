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
    MagicKIncludes/ImageMagick-7/Magick++/Blob.h \
    MagicKIncludes/ImageMagick-7/Magick++/CoderInfo.h \
    MagicKIncludes/ImageMagick-7/Magick++/Color.h \
    MagicKIncludes/ImageMagick-7/Magick++/Drawable.h \
    MagicKIncludes/ImageMagick-7/Magick++/Exception.h \
    MagicKIncludes/ImageMagick-7/Magick++/Functions.h \
    MagicKIncludes/ImageMagick-7/Magick++/Geometry.h \
    MagicKIncludes/ImageMagick-7/Magick++/Image.h \
    MagicKIncludes/ImageMagick-7/Magick++/Include.h \
    MagicKIncludes/ImageMagick-7/Magick++/Montage.h \
    MagicKIncludes/ImageMagick-7/Magick++/Pixels.h \
    MagicKIncludes/ImageMagick-7/Magick++/ResourceLimits.h \
    MagicKIncludes/ImageMagick-7/Magick++/SecurityPolicy.h \
    MagicKIncludes/ImageMagick-7/Magick++/Statistic.h \
    MagicKIncludes/ImageMagick-7/Magick++/STL.h \
    MagicKIncludes/ImageMagick-7/Magick++/TypeMetric.h \
    MagicKIncludes/ImageMagick-7/MagickCore/animate.h \
    MagicKIncludes/ImageMagick-7/MagickCore/annotate.h \
    MagicKIncludes/ImageMagick-7/MagickCore/artifact.h \
    MagicKIncludes/ImageMagick-7/MagickCore/attribute.h \
    MagicKIncludes/ImageMagick-7/MagickCore/blob.h \
    MagicKIncludes/ImageMagick-7/MagickCore/cache-view.h \
    MagicKIncludes/ImageMagick-7/MagickCore/cache.h \
    MagicKIncludes/ImageMagick-7/MagickCore/channel.h \
    MagicKIncludes/ImageMagick-7/MagickCore/cipher.h \
    MagicKIncludes/ImageMagick-7/MagickCore/client.h \
    MagicKIncludes/ImageMagick-7/MagickCore/coder.h \
    MagicKIncludes/ImageMagick-7/MagickCore/color.h \
    MagicKIncludes/ImageMagick-7/MagickCore/colormap.h \
    MagicKIncludes/ImageMagick-7/MagickCore/colorspace.h \
    MagicKIncludes/ImageMagick-7/MagickCore/compare.h \
    MagicKIncludes/ImageMagick-7/MagickCore/composite.h \
    MagicKIncludes/ImageMagick-7/MagickCore/compress.h \
    MagicKIncludes/ImageMagick-7/MagickCore/configure.h \
    MagicKIncludes/ImageMagick-7/MagickCore/constitute.h \
    MagicKIncludes/ImageMagick-7/MagickCore/decorate.h \
    MagicKIncludes/ImageMagick-7/MagickCore/delegate.h \
    MagicKIncludes/ImageMagick-7/MagickCore/deprecate.h \
    MagicKIncludes/ImageMagick-7/MagickCore/display.h \
    MagicKIncludes/ImageMagick-7/MagickCore/distort.h \
    MagicKIncludes/ImageMagick-7/MagickCore/distribute-cache.h \
    MagicKIncludes/ImageMagick-7/MagickCore/draw.h \
    MagicKIncludes/ImageMagick-7/MagickCore/effect.h \
    MagicKIncludes/ImageMagick-7/MagickCore/enhance.h \
    MagicKIncludes/ImageMagick-7/MagickCore/exception.h \
    MagicKIncludes/ImageMagick-7/MagickCore/feature.h \
    MagicKIncludes/ImageMagick-7/MagickCore/fourier.h \
    MagicKIncludes/ImageMagick-7/MagickCore/fx.h \
    MagicKIncludes/ImageMagick-7/MagickCore/gem.h \
    MagicKIncludes/ImageMagick-7/MagickCore/geometry.h \
    MagicKIncludes/ImageMagick-7/MagickCore/histogram.h \
    MagicKIncludes/ImageMagick-7/MagickCore/identify.h \
    MagicKIncludes/ImageMagick-7/MagickCore/image-view.h \
    MagicKIncludes/ImageMagick-7/MagickCore/image.h \
    MagicKIncludes/ImageMagick-7/MagickCore/layer.h \
    MagicKIncludes/ImageMagick-7/MagickCore/linked-list.h \
    MagicKIncludes/ImageMagick-7/MagickCore/list.h \
    MagicKIncludes/ImageMagick-7/MagickCore/locale_.h \
    MagicKIncludes/ImageMagick-7/MagickCore/log.h \
    MagicKIncludes/ImageMagick-7/MagickCore/magic.h \
    MagicKIncludes/ImageMagick-7/MagickCore/magick-baseconfig.h \
    MagicKIncludes/ImageMagick-7/MagickCore/magick-config.h \
    MagicKIncludes/ImageMagick-7/MagickCore/magick-type.h \
    MagicKIncludes/ImageMagick-7/MagickCore/magick.h \
    MagicKIncludes/ImageMagick-7/MagickCore/MagickCore.h \
    MagicKIncludes/ImageMagick-7/MagickCore/matrix.h \
    MagicKIncludes/ImageMagick-7/MagickCore/memory_.h \
    MagicKIncludes/ImageMagick-7/MagickCore/method-attribute.h \
    MagicKIncludes/ImageMagick-7/MagickCore/methods.h \
    MagicKIncludes/ImageMagick-7/MagickCore/mime.h \
    MagicKIncludes/ImageMagick-7/MagickCore/module.h \
    MagicKIncludes/ImageMagick-7/MagickCore/monitor.h \
    MagicKIncludes/ImageMagick-7/MagickCore/montage.h \
    MagicKIncludes/ImageMagick-7/MagickCore/morphology.h \
    MagicKIncludes/ImageMagick-7/MagickCore/nt-base.h \
    MagicKIncludes/ImageMagick-7/MagickCore/opencl.h \
    MagicKIncludes/ImageMagick-7/MagickCore/option.h \
    MagicKIncludes/ImageMagick-7/MagickCore/paint.h \
    MagicKIncludes/ImageMagick-7/MagickCore/pixel-accessor.h \
    MagicKIncludes/ImageMagick-7/MagickCore/pixel.h \
    MagicKIncludes/ImageMagick-7/MagickCore/policy.h \
    MagicKIncludes/ImageMagick-7/MagickCore/prepress.h \
    MagicKIncludes/ImageMagick-7/MagickCore/profile.h \
    MagicKIncludes/ImageMagick-7/MagickCore/property.h \
    MagicKIncludes/ImageMagick-7/MagickCore/quantize.h \
    MagicKIncludes/ImageMagick-7/MagickCore/quantum.h \
    MagicKIncludes/ImageMagick-7/MagickCore/random_.h \
    MagicKIncludes/ImageMagick-7/MagickCore/registry.h \
    MagicKIncludes/ImageMagick-7/MagickCore/resample.h \
    MagicKIncludes/ImageMagick-7/MagickCore/resize.h \
    MagicKIncludes/ImageMagick-7/MagickCore/resource_.h \
    MagicKIncludes/ImageMagick-7/MagickCore/segment.h \
    MagicKIncludes/ImageMagick-7/MagickCore/semaphore.h \
    MagicKIncludes/ImageMagick-7/MagickCore/shear.h \
    MagicKIncludes/ImageMagick-7/MagickCore/signature.h \
    MagicKIncludes/ImageMagick-7/MagickCore/splay-tree.h \
    MagicKIncludes/ImageMagick-7/MagickCore/static.h \
    MagicKIncludes/ImageMagick-7/MagickCore/statistic.h \
    MagicKIncludes/ImageMagick-7/MagickCore/stream.h \
    MagicKIncludes/ImageMagick-7/MagickCore/string_.h \
    MagicKIncludes/ImageMagick-7/MagickCore/studio.h \
    MagicKIncludes/ImageMagick-7/MagickCore/threshold.h \
    MagicKIncludes/ImageMagick-7/MagickCore/timer.h \
    MagicKIncludes/ImageMagick-7/MagickCore/token.h \
    MagicKIncludes/ImageMagick-7/MagickCore/transform.h \
    MagicKIncludes/ImageMagick-7/MagickCore/type.h \
    MagicKIncludes/ImageMagick-7/MagickCore/utility.h \
    MagicKIncludes/ImageMagick-7/MagickCore/version.h \
    MagicKIncludes/ImageMagick-7/MagickCore/vision.h \
    MagicKIncludes/ImageMagick-7/MagickCore/widget.h \
    MagicKIncludes/ImageMagick-7/MagickCore/xml-tree.h \
    MagicKIncludes/ImageMagick-7/MagickCore/xwindow.h \
    MagicKIncludes/ImageMagick-7/MagickWand/animate.h \
    MagicKIncludes/ImageMagick-7/MagickWand/compare.h \
    MagicKIncludes/ImageMagick-7/MagickWand/composite.h \
    MagicKIncludes/ImageMagick-7/MagickWand/conjure.h \
    MagicKIncludes/ImageMagick-7/MagickWand/convert.h \
    MagicKIncludes/ImageMagick-7/MagickWand/deprecate.h \
    MagicKIncludes/ImageMagick-7/MagickWand/display.h \
    MagicKIncludes/ImageMagick-7/MagickWand/drawing-wand.h \
    MagicKIncludes/ImageMagick-7/MagickWand/identify.h \
    MagicKIncludes/ImageMagick-7/MagickWand/import.h \
    MagicKIncludes/ImageMagick-7/MagickWand/magick-cli.h \
    MagicKIncludes/ImageMagick-7/MagickWand/magick-image.h \
    MagicKIncludes/ImageMagick-7/MagickWand/magick-property.h \
    MagicKIncludes/ImageMagick-7/MagickWand/MagickWand.h \
    MagicKIncludes/ImageMagick-7/MagickWand/method-attribute.h \
    MagicKIncludes/ImageMagick-7/MagickWand/mogrify.h \
    MagicKIncludes/ImageMagick-7/MagickWand/montage.h \
    MagicKIncludes/ImageMagick-7/MagickWand/operation.h \
    MagicKIncludes/ImageMagick-7/MagickWand/pixel-iterator.h \
    MagicKIncludes/ImageMagick-7/MagickWand/pixel-wand.h \
    MagicKIncludes/ImageMagick-7/MagickWand/stream.h \
    MagicKIncludes/ImageMagick-7/MagickWand/wand-view.h \
    MagicKIncludes/ImageMagick-7/MagickWand/wandcli.h \
    MagicKIncludes/ImageMagick-7/Magick++.h

FORMS += \
        pixamawindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagick++-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

unix:!macx: PRE_TARGETDEPS += $$PWD/MagicKLibs/libMagick++-7.Q16HDRI.a

unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagickCore-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

unix:!macx: PRE_TARGETDEPS += $$PWD/MagicKLibs/libMagickCore-7.Q16HDRI.a

unix:!macx: LIBS += -L$$PWD/MagicKLibs/ -lMagickWand-7.Q16HDRI

INCLUDEPATH += $$PWD/MagicKIncludes/ImageMagick-7
DEPENDPATH += $$PWD/MagicKIncludes/ImageMagick-7

unix:!macx: PRE_TARGETDEPS += $$PWD/MagicKLibs/libMagickWand-7.Q16HDRI.a

DISTFILES += \
    MagicKLibs/libMagick++-7.Q16HDRI.a \
    MagicKLibs/libMagickCore-7.Q16HDRI.a \
    MagicKLibs/libMagickWand-7.Q16HDRI.a \
    MagicKLibs/ImageMagick-7.0.8/config-Q16HDRI/configure.xml
