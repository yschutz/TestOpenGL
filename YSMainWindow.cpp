// an openGL window

#include <QImage>
#include <QTimer>
#include <OpenGL/glu.h>

#include "YSMainWindow.h"
#include "YSObject.h"
#include "YSStar.h"

#include "YSParticle.h"

#include "YSAnnulus.h"
#include "YSPyramide.h"
#include "YSParallelogram.h"
#include "YSParallelepiped.h"
#include "YSPolygon.h"
#include "YSTriangle.h"
#include "YSCylinder.h"
#include "YSTube.h"
#include "YSVertex.h"

//=====================================================================================
YSMainWindow::YSMainWindow(QWidget *parent) :
    YSGLWidget(60, parent, QString("OpenGL main window")),
    mRotStepC(0.0), mRotStepS(0.0), mRotStepT(0.0)
{

//      mTriangle = new YSTriangle(4, 2, YSTriangle::ISOC);
//      mPyramide = new YSPyramide(4,2);
//    mParallelepiped = new YSParallelepiped(1.0, 1.0, 1.0, 90.0);
//    mParallelogram->AddColor(1.0, 0.0, 0.0);
//       mPolygon = new YSPolygon(5.0, 8, 360. /8. /2.);
    mAnnulus = new YSAnnulus(5.0, 3.68, 8, 360. /8. /2.);
//    mCylinder = new YSCylinder(5.0, 24 , 2.0, 360. /8. /2.);
    mTube  = new YSTube(5.0, 3.68, 8 , 10.0, 360. /8. /2.);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);
//      mPyramide->AddColor(0.1, 0.2, 0.9, 0.8);
//      mPyramide->AddColor(0.9, 0.2, 0.1, 0.8);
//      mPyramide->AddColor(0.1, 0.9, 0.2, 0.8);

    // Bright:  Red, Orange, Yellow, Green, Blue

//    mBoxCol[0][0] = 1.0; mBoxCol[0][1] = 0.0; mBoxCol[0][2] = 0.0;
//    mBoxCol[1][0] = 1.0; mBoxCol[1][1] = 0.5; mBoxCol[1][2] = 0.0;
//    mBoxCol[2][0] = 1.0; mBoxCol[2][1] = 1.0; mBoxCol[2][2] = 0.0;
//    mBoxCol[3][0] = 0.0; mBoxCol[3][1] = 1.0; mBoxCol[3][2] = 0.0;
//    mBoxCol[4][0] = 0.0; mBoxCol[4][1] = 1.0; mBoxCol[4][2] = 1.0;

//    // Dark:  Red, Orange, Yellow, Green, Blue

//    mTopCol[0][0] = 0.5; mTopCol[0][1] = 0.0 ; mTopCol[0][2] = 0.0;
//    mTopCol[1][0] = 0.5; mTopCol[1][1] = 0.25; mTopCol[1][2] = 0.0;
//    mTopCol[2][0] = 0.5; mTopCol[2][1] = 0.5 ; mTopCol[2][2] = 0.0;
//    mTopCol[3][0] = 0.0; mTopCol[3][1] = 0.5 ; mTopCol[3][2] = 0.0;
//    mTopCol[4][0] = 0.0; mTopCol[4][1] = 0.5 ; mTopCol[4][2] = 0.5;

//    mSlowDown = 10.0;
//    mZoom = -40.0;

//    mColors[0][0]  = 1.0f;  mColors[0][1]  = 0.5f;  mColors[0][2]  = 0.5f;
//    mColors[1][0]  = 1.0f;  mColors[1][1]  = 0.75f; mColors[1][2]  = 0.5f;
//    mColors[2][0]  = 1.0f;  mColors[2][1]  = 1.0f;  mColors[2][2]  = 0.5f;
//    mColors[3][0]  = 0.75f; mColors[3][1]  = 1.0f;  mColors[3][2]  = 0.5f;
//    mColors[4][0]  = 0.5f;  mColors[4][1]  = 1.0f;  mColors[4][2]  = 0.5f;
//    mColors[5][0]  = 0.5f;  mColors[5][1]  = 1.0f;  mColors[5][2]  = 0.75f;
//    mColors[6][0]  = 0.5f;  mColors[6][1]  = 1.0f;  mColors[6][2]  = 1.0f;
//    mColors[7][0]  = 1.0f;  mColors[7][1]  = 0.75f; mColors[7][2]  = 1.0f;
//    mColors[8][0]  = 0.5f;  mColors[8][1]  = 0.5f;  mColors[8][2]  = 1.0f;
//    mColors[9][0]  = 0.75f; mColors[9][1]  = 0.5f;  mColors[9][2]  = 1.0f;
//    mColors[10][0] = 1.0f;  mColors[10][1] = 0.5f;  mColors[10][2] = 1.0f;
//    mColors[11][0] = 1.0f;  mColors[11][1] = 0.5f;  mColors[11][2] = 0.75f;

//    mEnnemy = new YSObject[9];
//    mStep[0] = 1;
//    mStep[1] = 2;
//    mStep[2] = 4;
//    mStep[3] = 5;
//    mStep[4] = 10;
//    mStep[5] = 20;
//    mPlayer.Reset();
//    for (int index = 0; index < 9; index++) {
//        mEnnemy[index].SetPos( 5 + rand() % 6, rand() % 11);
//        mEnnemy[index].SetMov(mEnnemy[index].X() * 60, mEnnemy[index].Y() * 40);
//    }


}

//=====================================================================================
YSMainWindow::~YSMainWindow()
{
    // dtor
    delete mTriangle;
}

//=====================================================================================
void YSMainWindow::DrawCubeT()
{
    // Draw a cube with texture

//    glBindTexture(GL_TEXTURE_2D, mTexture[mTextureFilter]);

    glBegin(GL_QUADS);
    // front face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        // back face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        // up face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        // down face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        // right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        // left face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glEnd();
}

//=====================================================================================
void YSMainWindow::DrawCube()
{
    // Draw a cube
    glBegin(GL_QUADS);
    // top face
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
    // bottom face
        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
    // front face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
    // back face
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
    // left face
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
    // right face
        glVertex3f(1.0f,  1.0f, -1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
}

//=====================================================================================
void YSMainWindow::DrawPyramide()
{
    // Draw a pyramide

    glBegin(GL_TRIANGLES);
    //front face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f,  1.0f,  0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
    // right face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f,  1.0f,  0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        // back face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f,  1.0f,  0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        // left face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f,  1.0f,  0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
    glEnd();
}

//=====================================================================================
void YSMainWindow::DrawSquare()
{
    // draw a square
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f,  1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f( 1.0f, -1.0f, 0.0f);
        glVertex3f( 1.0f,  1.0f, 0.0f);
    glEnd();
}

//=====================================================================================
void YSMainWindow::DrawTriangle()
{
    // draw a triangle
//    glBegin(GL_TRIANGLES);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex3f( 0.0f,  1.0f, 0.0f);
//        glColor3f(0.0f, 1.0f, 0.0f);
//        glVertex3f(-1.0f, -1.0f, 0.0f);
//        glColor3f(0.0f, 0.0f, 1.0f);
//        glVertex3f( 1.0f, -1.0f, 0.0f);
//        glEnd();

        glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
            glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
            glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
            glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
        glEnd();
}

//=====================================================================================
void YSMainWindow::DrawSphere(double radius)
{
//    // Draw a sphere. Need to call CreateSphere first
//    //http://www.swiftless.com/tutorials/opengl/sphere.html
//    glScalef(0.0125 * radius, 0.0125 * radius, 0.0125 * radius);
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    glBegin(GL_TRIANGLE_STRIP);
//    for (int vertex = 0; vertex < mVertextList.size(); vertex++) {
//        glTexCoord2f(mVertextList.at(vertex)->U(), mVertextList.at(vertex)->V());
//        glVertex3f(mVertextList.at(vertex)->X(),
//                   mVertextList.at(vertex)->Y(),
//                   mVertextList.at(vertex)->Z());
//    }
//    glEnd();
//    mXRot +=0.4;
}

//=====================================================================================
void YSMainWindow::CreateSphere(double radius, double x0, double y0, double z0)
{


    //Create a sphere
    // http://www.swiftless.com/tutorials/opengl/sphere.html

//    const double kStep = M_PI / 20.;
//    mVertextList.clear();
//    YSVertex * vertex;
//    for (double phi = 0.0; phi < M_PI; phi += kStep) {
//        for (double theta = 0.0; theta < 2 * M_PI; theta += kStep) {
//            double x = radius * qCos(theta) * qSin(phi) + x0;
//            double y = radius * qSin(theta) * qSin(phi) + y0;
//            double z = radius               * qCos(phi) + z0;
//            double v = phi / M_PI;
//            double u = theta / ( 2 * M_PI);
//            vertex = new YSVertex(x, y, z, u, v);
//            mVertextList.append(vertex);
//            x = radius * qCos(theta) * qSin(phi + kStep) + x0;
//            y = radius * qSin(theta) * qSin(phi + kStep) + y0;
//            z = radius               * qCos(phi + kStep) + z0;
//            v = (phi + kStep) / M_PI;
//            u = theta / ( 2 * M_PI);
//            vertex = new YSVertex(x, y, z, u, v);
//            mVertextList.append(vertex);
//            x = radius * qCos(theta + kStep) * qSin(phi) + x0;
//            y = radius * qSin(theta + kStep) * qSin(phi) + y0;
//            z = radius                       * qCos(phi) + z0;
//            v = phi / M_PI;
//            u = (theta + kStep) / ( 2 * M_PI);
//            vertex = new YSVertex(x, y, z, u, v);
//            mVertextList.append(vertex);
//            x = radius * qCos(theta + kStep) * qSin(phi + kStep) + x0;
//            y = radius * qSin(theta + kStep) * qSin(phi + kStep) + y0;
//            z = radius                       * qCos(phi + kStep) + z0;
//            v = (phi + kStep) / M_PI;
//            u = (theta + kStep) / ( 2 * M_PI);
//            vertex = new YSVertex(x, y, z, u, v);
//            mVertextList.append(vertex);
//        }
//    }
}

//=====================================================================================
void YSMainWindow::DrawCylinder(double radius, double length)
{
    // Draw a cylinder. Need to call CreateSphere first
//    glScalef(0.0125 * radius, 0.0125 * radius, 0.0125 * length);
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    glBegin(GL_TRIANGLE_STRIP);
//    for (int vertex = 0; vertex < mVertextList.size(); vertex++) {
//        float x = mVertextList.at(vertex)->X();
//        float y = mVertextList.at(vertex)->Y();
//        float z = mVertextList.at(vertex)->Z();
//        glTexCoord2f(mVertextList.at(vertex)->U(), mVertextList.at(vertex)->V());
//        glVertex3f(x, y, z);
//    }
//    glEnd();


}

//=====================================================================================
void YSMainWindow::CreateCylinder(double radius, double length)
{
    //    http://www.pascalgamedevelopment.com/showthread.php?6617-drawing-3d-geometrical-shapes-using-opengl-but-without-glu
//    const int    kThetatSteps = 40.;
//    const double kStepTheta = 2 * M_PI / kThetatSteps;
//    const int    kLengthSteps = 1;
//    const double kStepLength = length / kLengthSteps;
//    mVertextList.clear();
//    YSVertex * vertex;
//    for (int indez = 0; indez < kLengthSteps; indez++) {
//        float z0 = 0.5 * length - indez * kStepLength;
//        float z1 = z0 - kStepLength;
//        for (int indexy = 0; indexy < kThetatSteps + 1; indexy++) {
//            double theta = indexy * kStepTheta;
//            double x = radius * qCos(theta);
//            double y = radius * qSin(theta);
//            double u = (float)indexy / (float)kThetatSteps;
//            double v = indez  / kLengthSteps;
//            vertex = new YSVertex(x, y, z0, u, v);
//            mVertextList.append(vertex);
//            v = (float)indez + 1.0 / (float)kLengthSteps;
//            vertex = new YSVertex(x, y, z1 , u, v);
//            mVertextList.append(vertex);
//        }
//    }
}

//=====================================================================================
void YSMainWindow::initializeGL()
{
    // initialization of OpenGL

    // Texture

//    glGenTextures(5, &mTexture[0]); // prepare the array to receive the texture
//    bool rv = true;
//    rv *= LoadTexture("/Users/schutz/group/Qt/TestOpenGL/images/Logo.bmp", 0);
//    rv *= LoadTexture("/Users/schutz/group/Qt/TestOpenGL/images/Mask1.bmp", 1);
//    rv *= LoadTexture("/Users/schutz/group/Qt/TestOpenGL/images/Image1.bmp", 2);
//    rv *= LoadTexture("/Users/schutz/group/Qt/TestOpenGL/images/Mask2.bmp", 3);
//    rv *= LoadTexture("/Users/schutz/group/Qt/TestOpenGL/images/Image2.bmp", 4);

//    mTube->AddTexture(":/textures/images/IronRed.jpg");
//    mCylinder->AddTexture(":/images/IronRed.jpg");*/
//    mAnnulus->AddTexture(":/textures/images/IronRed.jpg");


//    glGenTextures(1, &mTexture[0]); // prepare the array to receive the texture
//    bool rv = true;
//    rv *= LoadTexture("/Users/schutz/cernbox/group/Qt/TestOpenGL/images/Glass.bmp", 0);
//    rv *= LoadTexture("/Users/schutz/cernbox/group/Qt/TestOpenGL/images/alice", 1);
//    if ( !rv)
//       exit(1);

//    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);              // specify shading technique (FLAT or SMOOTH)
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // specify clear values for the color buffer
    glClearDepth(1.0f);                   // specify the clear value for the depth buffer
    glEnable(GL_DEPTH_TEST);              // do depth comparisons and update the depth buffer
    glDepthFunc(GL_LEQUAL);               // depth buffer comparison: passes if incoming depth <= stored depth value
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // specify implementation-specific hints

//    // Light
//    glLightfv(GL_LIGHT1, GL_AMBIENT, mLightAmbient);   // setup the ambient light
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, mLightDiffuse);   // setup the ambient light
//    glLightfv(GL_LIGHT1, GL_POSITION, mLightPosition); // setup the light position
//    glEnable(GL_LIGHT1);

////    glEnable(GL_COLOR_MATERIAL);

//    // setup blending
//    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // full brightness alpha = 50%
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE); // blending function for translucency
//    glEnable(GL_BLEND);

    //setup stars
//    for (int index = 0; index < mTwinkleNumbers; index++) {
//        mTwinkleStars[index].SetAngle(0.0);
//        mTwinkleStars[index].SetDist(((float)index / mTwinkleNumbers) * 5.0);
//        mTwinkleStars[index].SetColor(rand()%256, rand()%256, rand()%256);
//    }
//    SetUpWorld();

//http://nehe.gamedev.net/tutorial/display_lists/16002/
//        mWiggleCount = 0;
//        glPolygonMode( GL_BACK, GL_FILL );          // Back Face Is Filled In
//    glPolygonMode( GL_FRONT, GL_LINE );         // Front Face Is Drawn With Lines

//        for (int x = 0; x < 45; x++) {
//            for (int y = 0; y < 45; y++) {
//                mPoints[x][y][0] = float((x / 5.) - 4.5);
//                mPoints[x][y][1] = float((y / 5.) - 4.5);
//                mPoints[x][y][2] = float(qSin((((x / 5.0) * 40.0) / 360.0) * M_PI * 2));
//                qDebug() << mPoints[x][y][0] << mPoints[x][y][1] << mPoints[x][y][2];
//            }
//        }
// http://nehe.gamedev.net/tutorial/display_lists/15003/
//    BuildLists();

    // http://nehe.gamedev.net/tutorial/cool_looking_fog/19001/

//    mFogColor[0] = 0.5f;
//    mFogColor[1] = 0.5f;
//    mFogColor[2] = 0.5f;
//    mFogColor[3] = 1.0f;

//    glFogi(GL_FOG_MODE, mFogMode[mFogFilter]);
//    glFogfv(GL_FOG_COLOR, mFogColor);
//    glFogf(GL_FOG_DENSITY, 0.35f);
//    glHint(GL_FOG_HINT, GL_NICEST);
//    glFogf(GL_FOG_START, 1.0f); //start depth
//    glFogf(GL_FOG_END, 5.0f);   // end depth
//    glEnable(GL_FOG);

    //http://www.cburch.com/cs/490/sched/feb8/index.html

//     glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//     glCullFace(GL_RED);
//     glFrontFace(GL_CCW);
//     glEnable(GL_CULL_FACE);
//     CreateSphere(30, 0, 0, 0);
//     mBox = glGenLists(2);
//     glNewList(mBox, GL_COMPILE);
//        DrawSphere(5);
//     glEndList();
//     CreateSphere(10, 15, 15, 15);
//     mTop = mBox + 1;
//     glNewList(mTop, GL_COMPILE);
//        DrawSphere(1);
//     glEndList();

    //http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
//    InitParticles();

//http://nehe.gamedev.net/tutorial/masking/15006/
//    mRoll = 0.0;
//    MScene = true;
//    mMasking = true;

    // http://nehe.gamedev.net/tutorial/lines,_antialiasing,_timing,_ortho_view_and_simple_sounds/17003/
//    BuildFont();
//    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//        glCullFace(GL_RED);
//         glFrontFace(GL_CCW);
//         glEnable(GL_CULL_FACE);
//         CreateCylinder(10, 10);
}

//=====================================================================================
void YSMainWindow::paintGL()
{
    // update the view


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // sets as specified by glClearColor(Depth)
    // draw a rotating triangle an squar
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -16.0f);

//    glScaled(mTube->InRadius(), mTube->InRadius(), 1); //mTriangle->Base() / width(), mTriangle->Height() / height() , 1.0);
    mRotStepC += 0.8;
    glRotatef(mRotStepC, 1.0f, 1.0f, 0.0f); // multiply the current matrix by a rotation matrix
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    mTube->Draw();
//    glScaled(mAnnulus->RadiusOut(), mAnnulus->RadiusOut(), 1); //mTriangle->Base() / width(), mTriangle->Height() / height() , 1.0);
//    mTube->Draw();
//    glTranslatef(0.0, 0.0, -mTube->Length() / 2.0);
//    mAnnulus->Draw();
//    glTranslatef(0.0, 0.0, mTube->Length() );
//    mAnnulus->Draw();
//    glLoadIdentity();
//    glTranslatef(1.5f, 0.0f, -6.0f);
//    glRotatef(mRotStepS, 0.0f, 1.0f, 0.0f); // multiply the current matrix by a rotation matrix
//    DrawSquare();

    // draw a rotation pyramide and cube
//    glLoadIdentity();
//    glTranslatef(-1.5f, 0.0, -6.0f);
//    glRotatef(mRotStepT, 0.0f, 1.0f, 0.0f);
//    mRotStepT += 0.2;
//    glLoadIdentity();
//    glTranslatef(1.5f, 0.0f, -7.0f);
//    DrawPyramide();
//    glRotatef(mRotStepS, 1.0f, 1.0f, 1.0f);
//    DrawCube();

    //draw a texture cube
//        glLoadIdentity();
//        glTranslatef(-1.5f, 0.0f, -6.0f);
//        glRotatef(mRotStepT, 0.0f, 1.0f, 0.0f); // multiply the current matrix by a rotation matrix
//    mRotStepT += 0.2;
//    mRotStepS += -0.15;

//    DrawCubeT();

    // draw another texture cube
//    glLoadIdentity();
//    glTranslatef(0.0f, 0.0f, mZDepth);
//    glRotatef(mXRot, 1.0f, 0.0f, 0.0f);
//    glRotatef(mYRot, 0.0f, 1.0f, 0.0f);
//    DrawCubeT();
//    mXRot += mXSpeed;
//    mYRot += mYSpeed;


    //http://nehe.gamedev.net/tutorial/moving_bitmaps_in_3d_kStep/17001/
    // draw twinking stars
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear svreen and depth buffer
//    glBindTexture(GL_TEXTURE_2D, mTexture[1]); // select the texture
//    for (int index = 0; index < mTwinkleNumbers; index++) {
//        glLoadIdentity();    // reset the view before to draw each star
//        glTranslatef(0.0f, 0.0f, mTwinkleZoom); // zoom into the screen
//        glRotatef(mTwinkleTilt, 1.0f, 0.0f, 0.0f);// tilt the view
//        glRotatef(mTwinkleStars[index].Angle(), 0.0f, 1.0f, 0.0f); // rotate to the current star angle
//        glTranslatef(mTwinkleStars[index].Dist(), 0.0f, 0.0f); // move forward on the x plane
//        glRotatef(-mTwinkleStars[index].Angle(), 0.0f, 1.0f, 0.0f); // cnacel the current star angle
//        glRotatef(-mTwinkleTilt, 1.0f, 0.0f, 0.0f);// cancel the screen tilt
//        if (mTwinkle) {
//            glColor4ub(mTwinkleStars[mTwinkleNumbers-index-1].Red(),
//                       mTwinkleStars[mTwinkleNumbers-index-1].Green(),
//                       mTwinkleStars[mTwinkleNumbers-index-1].Blue(), 255);
//            glBegin(GL_QUADS);
//                glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
//                glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f);
//                glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f);
//                glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f);
//            glEnd();
//            glRotatef(mTwinkleSpin, 0.0f, 0.0f, 1.0f); // rotate star on main axis
//            glColor4ub(mTwinkleStars[index].Red(),
//                       mTwinkleStars[index].Green(),
//                       mTwinkleStars[index].Blue(), 255);
//            glBegin(GL_QUADS);
//                glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
//                glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f);
//                glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f);
//                glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f);
//            glEnd();
//            mTwinkleSpin += 0.01;
//            mTwinkleStars[index].SetAngle(mTwinkleStars[index].Angle() + (float)index / (float)mTwinkleNumbers);
//            mTwinkleStars[index].SetDist(mTwinkleStars[index].Dist() - 0.01);
//            if (mTwinkleStars[index].Dist() < 0.0) {
//                mTwinkleStars[index].SetDist(5.0);
//                mTwinkleStars[index].SetColor( rand()%256, rand()%256, rand()%256);
//            }
//        }
//    }

//http://nehe.gamedev.net/tutorial/loading_and_moving_through_a_3d_world/22003/
//    glLoadIdentity();
//    float xm, ym, zm, um, vm;
//    float xtrans =- mXPos;
//    float ztrans =- mZPos;
//    float ytrans = -0.25;
//    float sceneroty = 360. - mYRot;

//    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
//    glRotatef(sceneroty, 0.0f, 0.0f, 0.0f);

//    glTranslatef(xtrans, ytrans, ztrans);
//    glBindTexture(GL_TEXTURE_2D, mTexture[1]);

//    for (int indexT = 0; indexT < mSector->NumberOfTriangles(); indexT++) {
//        glBegin(GL_TRIANGLES);
//            xm = mSector->Triangle(indexT)->Vertex(0)->X();
//            ym = mSector->Triangle(indexT)->Vertex(0)->Y();
//            zm = mSector->Triangle(indexT)->Vertex(0)->Z();
//            um = mSector->Triangle(indexT)->Vertex(0)->U();
//            vm = mSector->Triangle(indexT)->Vertex(0)->V();
//            glTexCoord2f(um, vm); glVertex3f(xm, ym, zm);
//            xm = mSector->Triangle(indexT)->Vertex(1)->X();
//            ym = mSector->Triangle(indexT)->Vertex(1)->Y();
//            zm = mSector->Triangle(indexT)->Vertex(1)->Z();
//            um = mSector->Triangle(indexT)->Vertex(1)->U();
//            vm = mSector->Triangle(indexT)->Vertex(1)->V();
//            glTexCoord2f(um, vm); glVertex3f(xm, ym, zm);
//            xm = mSector->Triangle(indexT)->Vertex(2)->X();
//            ym = mSector->Triangle(indexT)->Vertex(2)->Y();
//            zm = mSector->Triangle(indexT)->Vertex(2)->Z();
//            um = mSector->Triangle(indexT)->Vertex(2)->U();
//            vm = mSector->Triangle(indexT)->Vertex(2)->V();
//            glTexCoord2f(um, vm); glVertex3f(xm, ym, zm);
//        glEnd();
//    }
//http://nehe.gamedev.net/tutorial/flag_effect_waving_texture/16002/
//    float fx, fy, fxb, fyb;
//    glLoadIdentity();
//    glTranslatef(0.0f, 0.0f, -12.0f);

//    glRotatef(mXRot, 1.0f, 0.0f, 0.0f);
//    glRotatef(mYRot, 0.0f, 1.0f, 0.0f);
//    glRotatef(mZRot, 0.0f, 0.0f, 1.0f);

//    glBindTexture(GL_TEXTURE_2D, mTexture[1]);

//    glBegin(GL_QUADS);
//        for (int x = 0; x < 44; x++) {
//            for(int y = 0; y < 44; y++) {
//                fx  = float(x) / 44.0;
//                fy  = float(y) / 44.0;
//                fxb = float(x + 1) / 44.0;
//                fyb = float(y + 1) / 44.0;
//                glTexCoord2f( fx, fy);    // First Texture Coordinate (Bottom Left)
//                glVertex3f( mPoints[x][y][0], mPoints[x][y][1], mPoints[x][y][2] );
//                glTexCoord2f( fx, fyb );  // Second Texture Coordinate (Top Left)
//                glVertex3f( mPoints[x][y+1][0], mPoints[x][y+1][1], mPoints[x][y+1][2] );
//                glTexCoord2f( fxb, fyb ); // Third Texture Coordinate (Top Right)
//                glVertex3f( mPoints[x+1][y+1][0], mPoints[x+1][y+1][1], mPoints[x+1][y+1][2] );
//                glTexCoord2f( fxb, fy );  // Fourth Texture Coordinate (Bottom Right)
//                glVertex3f( mPoints[x+1][y][0], mPoints[x+1][y][1], mPoints[x+1][y][2] );
//            }
//        }
//    glEnd();
//    if (mWiggleCount == 2) {
//        for (int y = 0; y < 45; y++) {
//            mHold = mPoints[0][y][2];
//            for (int x = 0; x < 44; x++) {
//                mPoints[x][y][2] = mPoints[x + 1][y][2];
//            }
//            mPoints[44][y][2] = mHold;
//        }
//        mWiggleCount = 0;
//    }
//    mWiggleCount++;
//    mXRot += 0.3;
//    mYRot += 0.2;
//    mZRot += 0.4;

// http://nehe.gamedev.net/tutorial/display_lists/15003/
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    for (int indey = 0; indey < 6; indey++) {
//        for (int index = 0; index < indey; index++) {
//            glLoadIdentity();
//            glTranslatef(1.3f + (float(index) * 2.8f) - (float(indey) * 1.4f),
//                         ((6.0f - float(indey)) * 2.4f) -7.0f,
//                          -20.0f);
//            glRotatef(45.0f - (2.0f * indey) + mXRot, 1.0f, 0.0f, 0.0f);
//            glRotatef(45.0f + mYRot, 0.0f, 1.0f, 0.0f);
//            glColor3fv(mBoxCol[indey -1]);
//            glCallList(mBox);
//            glColor3fv(mTopCol[indey -1]);
//            glCallList(mTop);
//        }
//    }

//http://www.cburch.com/cs/490/sched/feb8/index.html
//    glLoadIdentity();
//    glTranslatef(-1.5f, 0.0f, -6.0f);
//    glRotatef(90+mXRot, 1, 0, 0);
//    glCallList(mBox);

//    glLoadIdentity();
//    glTranslatef(-1.0f, 0.5f, -12.0f);
//    glRotatef(90+mXRot, 1, 0, 0);
//    glCallList(mTop);

//    mXRot +=0.4;

//http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
//    DrawParticles();

//http://nehe.gamedev.net/tutorial/masking/15006/
//    Tutorial20();

    // http://nehe.gamedev.net/tutorial/lines,_antialiasing,_timing,_ortho_view_and_simple_sounds/17003/
//    Tutorial21();

//    mTriangle->Draw();

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glTranslatef(0.0, 0.0, -5.0);
//    glEnable(GL_CULL_FACE);
//    glEnable(GL_DEPTH_TEST);
//    glRotatef(mXRot, 0.2, 0.3, 0.1);
//    DrawCylinder(5.0, 10.0);
//    mXRot +=0.4;
}

//=====================================================================================
void YSMainWindow::resizeGL(int width, int height)
{
    if (height == 0)
        height = 1;
    glViewport(0, 0, width, height); // set the view port x, y of lower left corner. with, height
    glMatrixMode(GL_PROJECTION);    // specifies the current matrix; applies subsequent matrix operation to the projection matricx stack
    glLoadIdentity();               // replace the current matrix with the identity matrix
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f); //setup a perspective projection matrix
//    glOrtho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);           // specify current matrix applies subsequent matrix operation to the model view matrix
    glLoadIdentity();
}

//=====================================================================================
void YSMainWindow::SetUpWorld()
{
    // set up the world
    //http://nehe.gamedev.net/tutorial/loading_and_moving_through_a_3d_world/22003/
//    const int kNumberOfTriangles = 36;
//    const float kData[kNumberOfTriangles * 5 * 6] = {
//        // Floor 1
//        -3.0, 0.0,-3.0,0.0,6.0,
//        -3.0, 0.0, 3.0,0.0,0.0,
//         3.0, 0.0, 3.0,6.0,0.0,
//        -3.0, 0.0,-3.0,0.0,6.0,
//         3.0, 0.0,-3.0,6.0,6.0,
//         3.0, 0.0, 3.0,6.0,0.0,
//        // Ceiling 1
//        -3.0, 1.0,-3.0,0.0,6.0,
//        -3.0, 1.0, 3.0,0.0,0.0,
//         3.0, 1.0, 3.0,6.0,0.0,
//        -3.0, 1.0,-3.0,0.0,6.0,
//         3.0, 1.0,-3.0,6.0,6.0,
//         3.0, 1.0, 3.0,6.0,0.0,
//        // A1
//        -2.0, 1.0, -2.0,0.0,1.0,
//        -2.0, 0.0, -2.0,0.0,0.0,
//        -0.5, 0.0, -2.0,1.5,0.0,
//        -2.0, 1.0, -2.0,0.0,1.0,
//        -0.5, 1.0, -2.0,1.5,1.0,
//        -0.5, 0.0, -2.0,1.5,0.0,
//        // A2
//         2.0, 1.0, -2.0,2.0,1.0,
//         2.0, 0.0, -2.0,2.0,0.0,
//         0.5, 0.0, -2.0,0.5,0.0,
//         2.0, 1.0, -2.0,2.0,1.0,
//         0.5, 1.0, -2.0,0.5,1.0,
//         0.5, 0.0, -2.0,0.5,0.0,
//        // B1
//        -2.0, 1.0, 2.0,2.0,1.0,
//        -2.0, 0.0, 2.0,2.0,0.0,
//        -0.5, 0.0, 2.0,0.5,0.0,
//        -2.0, 1.0, 2.0,2.0,1.0,
//        -0.5, 1.0, 2.0,0.5,1.0,
//        -0.5, 0.0, 2.0,0.5,0.0,
//        // B2
//         2.0, 1.0, 2.0,2.0,1.0,
//         2.0, 0.0, 2.0,2.0,0.0,
//         0.5, 0.0, 2.0,0.5,0.0,
//         2.0, 1.0, 2.0,2.0,1.0,
//         0.5, 1.0, 2.0,0.5,1.0,
//         0.5, 0.0, 2.0,0.5,0.0,
//        // C1
//        -2.0, 1.0, -2.0,0.0,1.0,
//        -2.0, 0.0, -2.0,0.0,0.0,
//        -2.0, 0.0, -0.5,1.5,0.0,
//        -2.0, 1.0, -2.0,0.0,1.0,
//        -2.0, 1.0, -0.5,1.5,1.0,
//        -2.0, 0.0, -0.5,1.5,0.0,
//        // C2
//        -2.0, 1.0, 2.0,2.0,1.0,
//        -2.0, 0.0, 2.0,2.0,0.0,
//        -2.0, 0.0, 0.5,0.5,0.0,
//        -2.0, 1.0, 2.0,2.0,1.0,
//        -2.0, 1.0, 0.5,0.5,1.0,
//        -2.0, 0.0, 0.5,0.5,0.0,
//        // D1
//        2.0, 1.0, -2.0,0.0,1.0,
//        2.0, 0.0, -2.0,0.0,0.0,
//        2.0, 0.0, -0.5,1.5,0.0,
//        2.0, 1.0, -2.0,0.0,1.0,
//        2.0, 1.0, -0.5,1.5,1.0,
//        2.0, 0.0, -0.5,1.5,0.0,
//        // D2
//        2.0, 1.0, 2.0,2.0,1.0,
//        2.0, 0.0, 2.0,2.0,0.0,
//        2.0, 0.0, 0.5,0.5,0.0,
//        2.0, 1.0, 2.0,2.0,1.0,
//        2.0, 1.0, 0.5,0.5,1.0,
//        2.0, 0.0, 0.5,0.5,0.0,
//        // Upper hallway - L
//        -0.5, 1.0, -3.0,0.0,1.0,
//        -0.5, 0.0, -3.0,0.0,0.0,
//        -0.5, 0.0, -2.0,1.0,0.0,
//        -0.5, 1.0, -3.0,0.0,1.0,
//        -0.5, 1.0, -2.0,1.0,1.0,
//        -0.5, 0.0, -2.0,1.0,0.0,
//        // Upper hallway - R
//        0.5, 1.0, -3.0,0.0,1.0,
//        0.5, 0.0, -3.0,0.0,0.0,
//        0.5, 0.0, -2.0,1.0,0.0,
//        0.5, 1.0, -3.0,0.0,1.0,
//        0.5, 1.0, -2.0,1.0,1.0,
//        0.5, 0.0, -2.0,1.0,0.0,
//        // Lower hallway - L
//        -0.5, 1.0, 3.0,0.0,1.0,
//        -0.5, 0.0, 3.0,0.0,0.0,
//        -0.5, 0.0, 2.0,1.0,0.0,
//        -0.5, 1.0, 3.0,0.0,1.0,
//        -0.5, 1.0, 2.0,1.0,1.0,
//        -0.5, 0.0, 2.0,1.0,0.0,
//        // Lower hallway - R
//        0.5, 1.0, 3.0,0.0,1.0,
//        0.5, 0.0, 3.0,0.0,0.0,
//        0.5, 0.0, 2.0,1.0,0.0,
//        0.5, 1.0, 3.0,0.0,1.0,
//        0.5, 1.0, 2.0,1.0,1.0,
//        0.5, 0.0, 2.0,1.0,0.0,
//        // Left hallway - Lw
//        -3.0, 1.0, 0.5, 1.0,1.0,
//        -3.0, 0.0, 0.5, 1.0,0.0,
//        -2.0, 0.0, 0.5, 0.0,0.0,
//        -3.0, 1.0, 0.5, 1.0,1.0,
//        -2.0, 1.0, 0.5, 0.0,1.0,
//        -2.0, 0.0, 0.5, 0.0,0.0,
//        // Left hallway - Hi
//        -3.0, 1.0, -0.5, 1.0,1.0,
//        -3.0, 0.0, -0.5, 1.0,0.0,
//        -2.0, 0.0, -0.5, 0.0,0.0,
//        -3.0, 1.0, -0.5, 1.0,1.0,
//        -2.0, 1.0, -0.5, 0.0,1.0,
//        -2.0, 0.0, -0.5, 0.0,0.0,
//        // Right hallway - Lw
//        3.0, 1.0, 0.5, 1.0,1.0,
//        3.0, 0.0, 0.5, 1.0,0.0,
//        2.0, 0.0, 0.5, 0.0,0.0,
//        3.0, 1.0, 0.5, 1.0,1.0,
//        2.0, 1.0, 0.5, 0.0,1.0,
//        2.0, 0.0, 0.5, 0.0,0.0,
//        // Right hallway - Hi
//        3.0, 1.0, -0.5, 1.0,1.0,
//        3.0, 0.0, -0.5, 1.0,0.0,
//        2.0, 0.0, -0.5, 0.0,0.0,
//        3.0, 1.0, -0.5, 1.0,1.0,
//        2.0, 1.0, -0.5, 0.0,1.0,
//        2.0, 0.0, -0.5, 0.0,0.0
//    };

//    mSector = new YSSector(kNumberOfTriangles);
//    int offset = -15;
//    for (int indexT = 0; indexT < mSector->NumberOfTriangles(); indexT++) {
//        offset +=15;
//        for (int indexV = 0; indexV < 3; indexV++) {
//            mSector->Triangle(indexT)->SetVertex(indexV, kData[offset + indexV * 5],
//                                                        kData[offset + indexV * 5 + 1],
//                                                        kData[offset + indexV * 5 + 2],
//                                                        kData[offset + indexV * 5 + 3],
//                                                        kData[offset + indexV * 5 + 4]);
//        }
//        mSector->Triangle(indexT)->Print();
//    }

}

//=====================================================================================
void YSMainWindow::BuildLists()
{
    // build lists
//    mBox = glGenLists(2);
//    glNewList(mBox, GL_COMPILE);
//        glBegin(GL_QUADS);
//        // Bottom Face
//            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
//            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
//            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
//            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
//            // Front Face
//            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
//            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
//            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
//            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
//            // Back Face
//            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
//            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
//            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//            // Right face
//            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
//            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
//            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
//            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
//            // Left Face
//            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
//            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
//            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
//            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
//        glEnd();
//    glEndList();

//    mTop = mBox + 1;
//    glNewList(mTop, GL_COMPILE);
//        glBegin(GL_QUADS);
//        // Top Face
//            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
//            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
//            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
//            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
//        glEnd();
//        glEndList();
}

//=====================================================================================
void YSMainWindow::InitParticles()
{
//    http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
//    mParticles.clear();
//    for (int index = 0; index < 100; index++) {
//        YSParticle *part = new YSParticle();
//        mParticles.append(part);
//    }
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    for (int index = 0; index < mParticles.size(); index++) {
//        mParticles.at(index)->SetActive();
//        mParticles.at(index)->SetLife(10.0);
//        mParticles.at(index)->SetFade(float(rand()%100) / 1000.0 + 0.003);
//        mCol = index * ( 12.0 / mParticles.size());
//        mParticles.at(index)->SetColor(mColors[mCol][0], mColors[mCol][1], mColors[mCol][2]);
//        float valx  = float((rand() % 50) - 26.0) * 10.0;
//        float valyz = float((rand() % 50) - 25.0) * 10.0;
//        mParticles.at(index)->SetDirection(valx, valyz, valyz);
//        mParticles.at(index)->SetGravity(0.0, -0.8, 0.0);
//        mParticles.at(index)->SetPos(0.0, 0.0, 0.0);
//    }

}

//=====================================================================================
void YSMainWindow::DrawParticles()
{
//    glLoadIdentity();
//    for (int index = 0; index < mParticles.size(); index++) {
//        if(mParticles.at(index)->IsActive()) {
//            float x = mParticles.at(index)->X();
//            float y = mParticles.at(index)->Y();
//            float z = mParticles.at(index)->Z() + mZoom;
//            glColor4f(mParticles.at(index)->R(), mParticles.at(index)->G(), mParticles.at(index)->B(), mParticles.at(index)->Life());
//            glBegin(GL_TRIANGLE_STRIP);
//                glTexCoord2d(1,1); glVertex3f(x + 0.5f, y + 0.5f, z);
//                glTexCoord2d(0,1); glVertex3f(x - 0.5f, y + 0.5f, z);
//                glTexCoord2d(1,0); glVertex3f(x + 0.5f, y - 0.5f, z);
//                glTexCoord2d(0,0); glVertex3f(x - 0.5f, y - 0.5f, z);
//            glEnd();
//            x = mParticles.at(index)->X() + mParticles.at(index)->XD() / (mSlowDown * 1000.);
//            y = mParticles.at(index)->Y() + mParticles.at(index)->YD() / (mSlowDown * 1000.);
//            z = mParticles.at(index)->Z() + mParticles.at(index)->ZD() / (mSlowDown * 1000.);
//            mParticles.at(index)->SetPos(x, y, z);
//            x = mParticles.at(index)->XD() + mParticles.at(index)->XG();
//            y = mParticles.at(index)->YD() + mParticles.at(index)->YG();
//            z = mParticles.at(index)->ZD() + mParticles.at(index)->ZG();
//            mParticles.at(index)->SetDirection(x, y, z);
//            mParticles.at(index)->SetLife(mParticles.at(index)->Life() - mParticles.at(index)->Fade());
////            if (mParticles.at(index)->Life() < 0.0) {
//                mParticles.at(index)->SetLife(1.0);
//                mParticles.at(index)->SetFade(float(rand() % 100) / 1000.0 + 0.003);
//                mParticles.at(index)->SetPos(0.0, 0.0, 0.0);
//                float valx  = float((rand() % 50) - 26.0);
//                float valyz = float((rand() % 50) - 25.0);
//                mParticles.at(index)->SetDirection( valx, valyz, valyz);
//                mCol = index * ( 12.0 / mParticles.size());
//                mParticles.at(index)->SetColor(mColors[mCol][0], mColors[mCol][1], mColors[mCol][2]);
//            }
//        }
//    }
}

//=====================================================================================
void YSMainWindow::Tutorial20()
{
    //http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);              // do depth comparisons and update the depth buffer
//    glLoadIdentity();
//    glTranslatef(0.0f, 0.0f, -2.0f);
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    glBegin(GL_QUADS);
//        glTexCoord2f(0.0f, -mRoll + 0.0f); glVertex3f(-1.1f, -1.1f, 0.0f);
//        glTexCoord2f(3.0f, -mRoll + 0.0f); glVertex3f( 1.1f, -1.1f, 0.0f);
//        glTexCoord2f(3.0f, -mRoll + 3.0f); glVertex3f( 1.1f,  1.1f, 0.0f);
//        glTexCoord2f(0.0f, -mRoll + 3.0f); glVertex3f(-1.1f,  1.1f, 0.0f);
//    glEnd();
//    glEnable(GL_BLEND);
//    glDisable(GL_DEPTH_TEST);
//    if (mMasking) {
//        glBlendFunc(GL_DST_COLOR, GL_ZERO); // Blend Screen Color With Zero (Black)
//    }
//    if (MScene) {
//        glTranslatef(0.0f, 0.0f, -1.0f);
//        glRotatef(mRoll * 360, 0.0f, 0.0f, 1.0f);
//        if (mMasking) {
//            glBindTexture(GL_TEXTURE_2D, mTexture[3]);
//            glBegin(GL_QUADS);
//            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.1f, -1.1f, 0.0f);
//            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.1f, -1.1f, 0.0f);
//            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.1f,  1.1f, 0.0f);
//            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.1f,  1.1f, 0.0f);
//            glEnd();

//        }
//        glBlendFunc(GL_ONE, GL_ONE); // Copy Image 2 Color To The Screen
//        glBindTexture(GL_TEXTURE_2D, mTexture[4]);
//        glBegin(GL_QUADS);
//            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.1f, -1.1f, 0.0f);
//            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.1f, -1.1f, 0.0f);
//            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.1f,  1.1f, 0.0f);
//            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.1f,  1.1f, 0.0f);
//        glEnd();
//    } else {
//        if (mMasking) {
//            glBindTexture(GL_TEXTURE_2D, mTexture[1]);
//            glBegin(GL_QUADS);
//                glTexCoord2f(mRoll + 0.0f, 0.0f); glVertex3f(-1.1f, -1.1f, 0.0f);
//                glTexCoord2f(mRoll + 4.0f, 0.0f); glVertex3f( 1.1f, -1.1f, 0.0f);
//                glTexCoord2f(mRoll + 4.0f, 4.0f); glVertex3f( 1.1f,  1.1f, 0.0f);
//                glTexCoord2f(mRoll + 0.0f, 4.0f); glVertex3f(-1.1f,  1.1f, 0.0f);
//            glEnd();
//        }
//        glBlendFunc(GL_ONE, GL_ONE);
//        glBindTexture(GL_TEXTURE_2D, mTexture[2]);
//        glBegin(GL_QUADS);
//            glTexCoord2f(mRoll + 0.0f, 0.0f); glVertex3f(-1.1f, -1.1f, 0.0f);
//            glTexCoord2f(mRoll + 4.0f, 0.0f); glVertex3f( 1.1f, -1.1f, 0.0f);
//            glTexCoord2f(mRoll + 4.0f, 4.0f); glVertex3f( 1.1f,  1.1f, 0.0f);
//            glTexCoord2f(mRoll + 0.0f, 4.0f); glVertex3f(-1.1f,  1.1f, 0.0f);
//        glEnd();
//    }
//    glEnable(GL_DEPTH_TEST);
//    glDisable(GL_BLEND);
//    mRoll += 0.002f;
//    if (mRoll > 1.0f)
//        mRoll -= 1.0f;

}

//=====================================================================================
void YSMainWindow::glPrint(GLint x, GLint y, int set, const char *fmt, ...)
{
    char text[256];
    if (fmt == NULL)
        return;
    va_list ap;
    va_start(ap, fmt);
        vsprintf(text, fmt, ap);
    va_end(ap);
    if (set > 1)
        set = 1;
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
    glTranslated(x, y, 0);
    glListBase(mBase - 32 + (128 * set));
    if (set == 0)
        glScalef(1.5f, 2.0f, 1.0f);
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
    glDisable(GL_TEXTURE_2D);
}

//=====================================================================================
void YSMainWindow::BuildFont()
{
    // http://nehe.gamedev.net/tutorial/lines,_antialiasing,_timing,_ortho_view_and_simple_sounds/17003/
//       mBase = glGenLists(256);
//       glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//       for (int index = 0; index < 256; index++) {
//           float cx = float(index % 16) / 16.0;
//           float cy = float(index / 16.0) / 16.0;
//           glNewList(mBase + index, GL_COMPILE);
//               glBegin(GL_QUADS);
//               glTexCoord2f(cx,          1.0 - cy - 0.0625); glVertex2i(0,  16);
//               glTexCoord2f(cx + 0.0625, 1.0 - cy - 0.0625); glVertex2i(16, 16);
//               glTexCoord2f(cx + 0.0625, 1.0 - cy         ); glVertex2i(16,  0);
//               glTexCoord2f(cx,          1.0 - cy         ); glVertex2i(0,   0);
//               glEnd();
//               glTranslated(15, 0, 0);
//           glEndList();
//       }
}

//=====================================================================================
void YSMainWindow::Tutorial21()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glBindTexture(GL_TEXTURE_2D, mTexture[0]);
//    glColor3f(1.0f, 0.5f, 1.0f);
//    glPrint(207, 24, 0, "GRID CRAZY");
//    glColor3f(1.0f, 1.0f, 0.0f);
//    glPrint(20, 20, 1, "Level:%2i", 1);
//    glPrint(20, 40, 1, "Stage:%2i", 10);
}
