// A generic OpenGL widget

#include <QEvent>
#include <QGestureEvent>
#include <QKeyEvent>
#include <qmath.h>
#include <QOpenGLDebugLogger>
#include <QString>
#include <QTimer>

#include "YSGLWidget.h"
#include "YSScene.h"

//=====================================================================================
YSGLWidget::YSGLWidget(int framePerSecond, QString name, QWidget *parent) : QOpenGLWidget(parent),
    mAspect(45.0), mMouseClicked(false), mFullScreen(false), mZoom(0.0)
{
    // ctor. Screen refresheing defined

    setWindowTitle(name);

    mScene = new YSScene(this);
    mDebugLogger = new QOpenGLDebugLogger(this);

    connect(mDebugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)), this, SLOT(PrintLog(QOpenGLDebugMessage)));

    int widgetWidth = 800, widgetHeight = 600;
    resize(widgetWidth, widgetHeight);

    mLastPosition = QPoint(widgetWidth / 2, widgetHeight / 2);

    mCameraPosition = QVector3D(0.5, 0.5, 3.0);
    mCameraFront    = QVector3D(0.0, 0.0, -1.0); // front is along z (back)
    mCameraUp       = QVector3D(0.0, 1.0, 0.0);  // vertical position is along y axis


    if (framePerSecond == 0)
        mTimer = NULL;
    else {
        int second = 1000; // 1 second = 1000 ms
        int timerInterval = second / framePerSecond; // interval between two images
        mTimer = new QTimer(this);
        connect(mTimer, SIGNAL(timeout()), this, SLOT(TimeOutSlot())); // connect to screen refresh actions
        mTimer->start(timerInterval);
    }
}

//=====================================================================================
YSGLWidget::~YSGLWidget()
{
}

//=====================================================================================
void YSGLWidget::Debugger(bool active)
{
    //activate/desactivate the debuuger
    if (active) {
        mDebugLogger->initialize();
        mDebugLogger->startLogging();
    } else {
        mDebugLogger->stopLogging();
    }
}

//=====================================================================================
//bool YSGLWidget::event(QEvent *event)
//{
//    // redefines event to include gestures
////    if (event->type() == QEvent::Gesture)
////        return GestureEvent(static_cast<QGestureEvent*>(event));
////    else
////        return QWidget::event(event);
//}

//=====================================================================================
void YSGLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    // define action in response to key board key pressed

    qDebug() << Q_FUNC_INFO;
    switch (keyEvent->key()) {
    case Qt::Key_Escape:
        close();
        break;
//    case Qt::Key_F1:
//        ToggleFullScreen();
//        break;
//    case Qt::Key_L:
//        mLight = !mLight;
//        if (mLight)
//            glEnable(GL_LIGHTING);
//        else
//            glDisable(GL_LIGHTING);
//        break;
//    case Qt::Key_F:
//        mTextureFilter +=1;
//        if (mTextureFilter > 2)
//            mTextureFilter = 0;
//        break;
//    case Qt::Key_G:
//        mFogFilter +=1;
//        if (mFogFilter > 2)
//            mFogFilter = 0;
//        glFogi(GL_FOG_MODE, mFogMode[mFogFilter]);
//        break;
//    case Qt::Key_M:
//        mMasking =! mMasking;
//        break;
//    case Qt::Key_Space:
//        MScene =! MScene;
//        break;
//    case Qt::Key_PageUp:
//        mCameraPosition.setZ(mCameraPosition.z() - 0.5);
//        break;
//    case Qt::Key_PageDown:
//        mCameraPosition.setZ(mCameraPosition.z() + 0.5);
//        break;
//    case Qt::Key_Up:
//        mCameraPosition.setY(mCameraPosition.y() + 10.0);
//        break;
//    case Qt::Key_Down:
//        mCameraPosition.setY(mCameraPosition.y() - 10.0);
//        break;
//    case Qt::Key_Right:
//        mCameraPosition.setX(mCameraPosition.x() + 10.0);
//        break;
//    case Qt::Key_Left:
//        mCameraPosition.setX(mCameraPosition.x() - 10.0);
//        break;
//    case Qt::Key_B:
//        mBlend = !mBlend;
//        if (mBlend) {
//            glEnable(GL_BLEND);
//            glDisable(GL_DEPTH_TEST);
//        } else {
//            glDisable(GL_BLEND);
//            glEnable(GL_DEPTH_TEST);
//        }
//        break;
//    case Qt::Key_T:
//        mTwinkle = !mTwinkle;
    default:
        break;
    }
}

//=====================================================================================
void YSGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    // action when mouse is moved
//    if (mMouseClicked) {
//        qreal w = (qreal)width();
//        qreal h = (qreal)height();

//        qreal newX = qAsin((event->pos().x() - w / 2.0) / w)   * 180. / M_PI;
//        qreal newY   = qAsin((event->pos().y()  - h / 2.0) / h)  * 180. / M_PI;

//        mCameraPosition.setX((mCameraPosition.x() - newX) * 0.8);
//        mCameraPosition.setY((mCameraPosition.y() - newY) * 0.8);
//    }
}

//=====================================================================================
void YSGLWidget::mousePressEvent(QMouseEvent */*event*/)
{
    mMouseClicked = !mMouseClicked;
}

//=====================================================================================
void YSGLWidget::GestureEvent(QGestureEvent *event)
{
    // action in case of gesture event

//    if ( QGesture *gesture = event->gesture(Qt::PinchGesture) ) {
//        QPinchGesture *pinch = (QPinchGesture*) gesture;
//        if(pinch->scaleFactor() > 1)
//            mCameraPosition.setZ(mCameraPosition.z() + 0.5);
//        else
//            mCameraPosition.setZ(mCameraPosition.z() - 0.5);
//    }
}

//=====================================================================================
void YSGLWidget::ToggleFullScreen()
{
    // toggle between full screen mode
//    if (mFullScreen) {
//        showNormal();
//        mFullScreen = false;
//    } else {
//        showFullScreen();
//        mFullScreen = true;
//    }
}

//=====================================================================================
void YSGLWidget::TimeOutSlot()
{
    // define what to do to refresh screen
//    update(); // will refresh the scene framePerSecond times
}

//=====================================================================================
//bool YSGLWidget::LoadTexture(QString textureName, int index)
//{
    // load the image for the texture
//    QImage imTexture;
//    QImage imTextureTemp;
//    bool rv = imTextureTemp.load(textureName);
//    if (!rv) {
//        qDebug() << Q_FUNC_INFO << " Error: " << textureName << " not found";
//    return false;
//    }
//    imTexture = QGLWidget::convertToGLFormat(imTextureTemp);
//    //    glGenTextures(5, &mTexture[0]); // prepare the array to receive the texture

//    // Create nearest filtered texture: quick but bad
//    glBindTexture(GL_TEXTURE_2D, mTexture[index]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, imTexture.width(), imTexture.height(), 0, GL_RGBA,GL_UNSIGNED_BYTE, imTexture.bits()); // defines the properties of the image

//    // Create linear filtered texture: not so fast but nicer
//    glBindTexture(GL_TEXTURE_2D, mTexture[1]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, imTexture.width(), imTexture.height(), 0, GL_RGBA,GL_UNSIGNED_BYTE, imTexture.bits()); // defines the properties of the image

//    // Create linear filtered texture: best for details when image becomes small
//    glBindTexture(GL_TEXTURE_2D, mTexture[2]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imTexture.width(), imTexture.height(), GL_RGBA, GL_UNSIGNED_BYTE, imTexture.bits());

//    return true;
//}
