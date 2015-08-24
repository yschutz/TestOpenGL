// an openGL window

#ifndef YSMAINWINDOW_H
#define YSMAINWINDOW_H

#include "YSGLWidget.h"
#include "YSSector.h"
#include "YSObject.h"
class YSParticle;
class QTimer;

class YSAnnulus;
class YSPyramide;
class YSParallelogram;
class YSParallelepiped;
class YSPolygon;
class YSTriangle;
class YSCylinder;
class YSTube;

class YSMainWindow : public YSGLWidget
{
    Q_OBJECT
public:
    explicit YSMainWindow(QWidget *parent = 0);
    ~YSMainWindow();

    void DrawCube();
    void DrawCubeT();
    void DrawPyramide();
    void DrawSquare();
    void DrawTriangle();
    void DrawSphere(double radius);
    void CreateSphere(double radius, double x0, double y0, double z0);
    void DrawCylinder(double radius, double length);
    void CreateCylinder(double radius, double length);

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void SetUpWorld();
    void BuildLists();

    void InitParticles();
    void DrawParticles();

    void Tutorial20();

    void glPrint(GLint x, GLint y, int set, const char * fmt, ...);
    void BuildFont();

    void Tutorial21();

private:

    float  mRotStepC;   // rotation step for cube
    float  mRotStepS;   // rotation step for square
    float  mRotStepT;   // rotation step for triangle
    YSSector *mSector;
//    float   mPoints[45][45][3];
//    int     mWiggleCount;
//    float   mHold;

    int mBox;
    int mTop;
    float mBoxCol[5][3];
    float mTopCol[5][3];

    YSVertex *mSphereVertex;
    int      mNVertex;
    QList <YSVertex*> mVertextList;

    int   mFilter;
    float mFogColor[4];

    float mSlowDown;
    float mZoom;
    QList <YSParticle*> mParticles;
    float mColors[12][3];
    int   mCol;

    float  mRoll;

    YSObject mPlayer;
    YSObject * mEnnemy;
    YSObject mHourGlass;
    int      mStep[6];
    GLuint   mBase;
    QTimer   mTimer;

    YSAnnulus   *mAnnulus;
    YSPyramide  *mPyramide;
    YSParallelogram *mParallelogram;
    YSParallelepiped *mParallelepiped;
    YSPolygon *mPolygon;
    YSTriangle  *mTriangle;
    YSCylinder *mCylinder;
    YSTube *mTube;
};

#endif // YSMAINWINDOW_H
