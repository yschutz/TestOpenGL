// A generic OpenGL window

#ifndef YSGLWIDGET_H
#define YSGLWIDGET_H

#include <QOpenGLDebugLogger>
#include <QOpenGLWidget>
#include <QVector3D>

class QGestureEvent;

class YSScene; 


class YSGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit YSGLWidget(int framePerSecond = 0, QString name = "", QWidget *parent = 0);
    ~YSGLWidget();

    virtual void initializeGL() = 0;
    virtual void paintGL()      = 0;
    virtual void resizeGL(int width, int height) = 0;

public slots:
    void         Debugger(bool active);
    virtual void TimeOutSlot();

protected slots:
    void         PrintLog(const QOpenGLDebugMessage &msg) { qDebug() << Q_FUNC_INFO << msg.id() << msg.message(); } 

protected:
    void           keyPressEvent(QKeyEvent *keyEvent);
    void           mouseMoveEvent(QMouseEvent *event);
    void           mousePressEvent(QMouseEvent *event);

    qreal          Aspect() const { return mAspect; }
    QVector3D      CameraFront() const { return mCameraFront; }
    QVector3D      CameraPosition() const { return mCameraPosition; }
    QVector3D      CameraUp() const { return mCameraUp; }
    YSScene *      Scene() const { return mScene; }
//    qreal        CameraTheta() const { return mCamera.x(); }
//    qreal        CameraPhi()   const { return mCamera.y(); }
//    qreal        CameraZoom()  const { return mCamera.z(); }
//    void         SetCamera(qreal thetaDegrees, qreal phiDegrees, qreal zoom) { mCamera.setX(thetaDegrees); mCamera.setY(phiDegrees); mCamera.setZ(zoom); }

//    float        *mLightAmbient; // ambient light lits the scene
//    float        *mLightDiffuse; // diffuse light reflected from objects
//    float        *mLightPosition;// position of the light source
//    float        mXSpeed;     // X rotation speed
//    float        mYSpeed;     // Y rotation speed
//    bool         mTwinkle;       // control twinkle effect
//    YSStar       *mTwinkleStars; // array of stars
//    int          mTwinkleNumbers;// number of stars to draw
//    float        mTwinkleTilt;   // tilt the view
//    float        mTwinkleZoom;   // viewing distance away from stars
//    float        mTwinkleSpin;   //spin twinkling stars
//    float  mXRot;       // X rotation
//    float  mYRot;       // Y rotation
//    float  mZRot;       // Z rotation
//    double  mXPos;
//    float  mZPos;
//    int mFogFilter;
//    int mFogMode[3];

//    bool mMasking;
//    bool MScene;


    QOpenGLDebugLogger *mDebugLogger;         // debugging information

private:
    void GestureEvent(QGestureEvent *event);
    void ToggleFullScreen();

    qreal              mAspect;               // ??
    QVector3D          mCameraFront;          // defines the front end of the camera
    QVector3D          mCameraPosition;       // coordinateds of the camera position
    QVector3D          mCameraUp;             // defines the vertical position of the camera
    bool               mMouseClicked;         // toggle mous click
    bool               mFullScreen;           // control full screen mode
    QPoint             mLastPosition;         // last cursor position
    QPoint             mMousePressedPosition; // position of the cursor when mouse cliked
    YSScene            *mScene;               // the scene that contains the objects to be displayed          
    QTimer             *mTimer;               // control the number of images per second at which opengl refreshes the screen
    double             mZoom;                 // depth into the screen

    //    bool      mBlend;              // control blending
    //    bool      mLight;              // lighting on/off
    
};

#endif // YSGLWIDGET_H
