#ifndef YSSCENE_H
#define YSSCENE_H

// Manager class of the shapes to be drawn 
#include <QObject>
#include <QMatrix4x4>

class QOpenGLContext; 
class YSShape; 

class YSScene : public QObject
{
    Q_OBJECT
public:
    explicit YSScene(QObject *parent = 0);
    ~YSScene(); 
    
    void           AddShape(YSShape * shape) { mShapeList.append(shape); }     
    QOpenGLContext *Context() const { return mContext; }
    void           CreateShapes();
    void           Draw(); 
    void           LookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
    void           RemoveShape(YSShape * shape) { mShapeList.removeOne(shape); } 
    void           SetCamera(const QVector3D &eye, const QVector3D &center, const QVector3D &up); 
    void           SetContext(QOpenGLContext *context) { mContext = context; } 
    void           SetOrtho(qreal left, qreal right, qreal bottom, qreal top, qreal nearPlane, qreal farPlane); 
    void           SetPerspective(qreal vericalAngle, qreal aspectRatio, qreal nearPlane, qreal farPlane); 
    QList<YSShape*> Shapes() const { return mShapeList; }
    
private: 
    QList<YSShape*> mShapeList;  // list of shapes ntering the scene
    QOpenGLContext  *mContext;   // the context for OpenGL
    QMatrix4x4      mProjection; // the projection matrix
    QMatrix4x4      mView;       // the view matrix
    QMatrix4x4      mModel;      // the model matrix 
};

#endif // YSSCENE_H
