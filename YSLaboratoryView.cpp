#include <QOpenGLFunctions>
#include "YSAlice.h"
#include "YSCollision.h"
#include "YSShape.h"
#include "YSLaboratoryView.h"
#include "YSScene.h"

//=====================================================================================
YSLaboratoryView::YSLaboratoryView() : YSGLWidget(60, QString("P2 View")), mAlice(NULL)
{
    // ctor: prepare the lab view including ALICE

    
//        mAlice     = new YSAlice(this);
//        mAlice->Init();
        mCollision = new YSCollision(this);
}

//=====================================================================================
void YSLaboratoryView::initializeGL()
{
    // initiallisation (called once)

    Debugger(true);

    Scene()->SetContext(context());
    
    if (mAlice) {
    for (int index = 0; index < mAlice->Elements().size(); index++) {
        YSShape * shape = mAlice->Elements().at(index);
        Scene()->AddShape(shape);
    }
    }
    
    for (int index = 0; index < mCollision->FSParticles().size(); index++) {
        YSShape * shape = mCollision->FSParticles().at(index);
        Scene()->AddShape(shape);
    }
    
    Scene()->CreateShapes();
    context()->functions()->glViewport(0, 0, width(), height());
    
    
//    glShadeModel(GL_SMOOTH);              // specify shading technique (FLAT or SMOOTH)
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // specify clear values for the color buffer
//    glClearDepth(1.0f);                   // specify the clear value for the depth buffer
//    glEnable(GL_DEPTH_TEST);              // do depth comparisons and update the depth buffer
//    glDepthFunc(GL_LEQUAL);               // depth buffer comparison: passes if incoming depth <= stored depth value
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // specify implementation-specific hints

}

//=====================================================================================
void YSLaboratoryView::paintGL()
{
    // painting (called for each view update)

    Scene()->SetPerspective(Aspect(), (double)width() / (double)height(), 1, 100.0);
    Scene()->LookAt(CameraPosition(), CameraPosition() + CameraFront(), CameraUp());
    Scene()->Draw();
}

//=====================================================================================
void YSLaboratoryView::resizeGL(int width, int height)
{
    // resizes the viewing window

    context()->functions()->glViewport(0, 0, width, height);

}


