#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T15:11:54
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        YSGLWidget.cpp \
    YSStar.cpp \
    YSVertex.cpp \
    YSTriangle.cpp \
    YSParticle.cpp \
    YSObject.cpp \
    YSTimer.cpp \
    YSShape.cpp \
    YSrgba.cpp \
    YSPyramide.cpp \
    YSParallelogram.cpp \
    YSParallelepiped.cpp \
    YSPolygon.cpp \
    YSAnnulus.cpp \
    YSCylinder.cpp \
    YSTube.cpp \
    YSLaboratoryView.cpp \
    YSAlice.cpp \
    YSSphere.cpp \
    YSCollision.cpp \
    YSScene.cpp

HEADERS  += YSGLWidget.h \
    YSStar.h \
    YSVertex.h \
    YSTriangle.h \
    YSParticle.h \
    YSObject.h \
    YSTimer.h \
    YSShape.h \
    YSrgba.h \
    YSPyramide.h \
    YSParallelogram.h \
    YSParallelepiped.h \
    YSPolygon.h \
    YSAnnulus.h \
    YSCylinder.h \
    YSTube.h \
    YSLaboratoryView.h \
    YSAlice.h \
    YSSphere.h \
    YSCollision.h \
    YSScene.h

RESOURCES += \
    images.qrc \
    shaders.qrc

DISTFILES +=
