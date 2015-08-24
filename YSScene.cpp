#include <QDebug>
#include <QImage>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShader>


#include "YSScene.h"
#include "YSShape.h"

//=====================================================================================
YSScene::YSScene(QObject *parent) : QObject(parent), mContext(NULL)
{
    // ctor
}

//=====================================================================================
YSScene::~YSScene()
{
    // dtor
    qDeleteAll(mShapeList.begin(), mShapeList.end()); 
    mShapeList.clear();
}

//=====================================================================================
void YSScene::CreateShapes()
{
    // create all the shapes if the OpenGL context is defined
    
    if ( !mContext) {
        qDebug() << Q_FUNC_INFO << "No context attached to the scene"; 
        exit(1); 
    } else {
        foreach (YSShape *shape, mShapeList) {
            shape->SetDefaultShaders();
            shape->Create();
        }
    }   
}

//=====================================================================================
void YSScene::Draw()
{
    // draw all the shapes belonging to the scene
    
    if ( !mContext) {
        qDebug() << Q_FUNC_INFO << "No context attached to the scene"; 
        exit(1); 
    }
    Context()->functions()->glEnable(GL_DEPTH_TEST);
    Context()->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    foreach (YSShape *shape, mShapeList) {
        qDebug() << Q_FUNC_INFO << shape->objectName();
        if (shape->IsTexture())
            shape->SetTexture(QImage(shape->TextureImageName()));
        shape->Bind();
        QMatrix4x4 all = mProjection * mView * shape->Model();   
        shape->Shaders()->setUniformValueArray("all", &all, 1);
        if (shape->IndexList().isEmpty())
            Context()->functions()->glDrawArrays(shape->Mode(), 0, shape->CountVertices());
        else
            Context()->functions()->glDrawElements(shape->Mode(), shape->CountIndexes(), GL_UNSIGNED_INT, 0);
        shape->Release();
    }    

}

//=====================================================================================
void YSScene::LookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up)
{
    // position the camera

    mView.setToIdentity();
    mView.lookAt(eye, center, up);
}

//=====================================================================================
void YSScene::SetOrtho(qreal left, qreal right, qreal bottom, qreal top, qreal nearPlane, qreal farPlane)
{
    mProjection.setToIdentity();
    mProjection.ortho(left, right, bottom, top, nearPlane, farPlane);
}

//=====================================================================================
void YSScene::SetPerspective(qreal vericalAngle, qreal aspectRatio, qreal nearPlane, qreal farPlane)
{
    mProjection.setToIdentity();
    mProjection.perspective(vericalAngle, aspectRatio, nearPlane, farPlane);
}

