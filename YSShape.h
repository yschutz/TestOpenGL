#ifndef YSSHAPE_H
#define YSSHAPE_H

#include <qmath.h>
#include <QMatrix4x4>
#include <QObject>
#include <OpenGL.h>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QVector>

class QOpenGLShaderProgram; 
class QOpenGLTexture; 

class YSrgba;
class YSVertex;
class YSShape : public QObject
{
    Q_OBJECT
public:
    explicit YSShape(const char * objName, double degrees = 0.0, QObject *parent = 0);
    ~YSShape();

    void                     AddColor(float r, float g, float b, float a = 1.0);
//    void                 AddTexture(QString textureName);
    void                     AddVertex(YSVertex *vertex) { mVertextList.append(vertex); }
    void                     Bind();
    void                     ClearColor() { mRGB.clear(); mColor = false; }
    int                      CountIndexes() const { return mIndexList.count(); }
    int                      CountVertices() const { return mVertextList.count(); }
    void                     Create();
    virtual void             CreateVertices(){;}
    const QVector<GLuint>    &IndexList() const { return mIndexList; }
    GLenum                   Mode() const { return mMode; }
    const QMatrix4x4         &Model() const { return mModel; }
    void                     NoColor() { mColor = false; }
    void                     Release();
    void                     ResetTransform() { mModel.setToIdentity(); }
    void                     Rotate(qreal angle, qreal x, qreal y, qreal z) { mModel.rotate(angle, x, y, z); }
    void                     Scale(qreal factor) { mModel.scale(factor);  }
    void                     SetShaders(const QString &vertexfile, const QString &fragmentFile);
    void                     SetDefaultShaders();
    void                     SetDepth(double z);
    void                     SetMode(GLenum mode) { mMode = mode; }
    void                     SetTexture(const QImage &image);
    void                     SetTextureImageName(QString name) { mTextureImageName = name; }
    QOpenGLShaderProgram     *Shaders() const { return mShaderProgram; }
    bool                     IsTexture() const { if (mTexture) return true; else return false; }
    QString                  TextureImageName() const { return mTextureImageName; }
    void                     Translate(qreal x, qreal y, qreal z) { mModel.translate(x, y, z); }
    YSVertex*                Vertex(int index);
    const QVector<YSVertex*> &VertexList() const { return mVertextList; }
    int                      Vertices() const { return mVertextList.size(); }

signals:

public slots:
protected:
    bool                     mColor;           // add color or not
    double                   mDegrees;         // rotation angle of the object
    double                   mDepth;           // depth (z axis of the shape)
    QOpenGLBuffer            mIndexBuffer;     // Open GL buffer that hold ??
    QVector<GLuint>          mIndexList;       // list of indexes to vertices
    GLenum                   mMode;            // specifies the primitive to render (GL_TRIANGLES)
    QMatrix4x4               mModel;           // transformation matrix
    QList <YSrgba*>          mRGB;             // colors
    double                   mRot;             // rotation angle of the shape
    QOpenGLShaderProgram     *mShaderProgram;  // the openGL steering program for shaders
    QOpenGLTexture           *mTexture;        // texture to be applied to shape
    QString                  mTextureImageName;// file name of the texture image
    GLuint                   *mTexArray;       // textures array
    QOpenGLVertexArrayObject mVAO;             // the array to store vertices of the shape
    QVector <YSVertex*>      mVertextList;     // list of vertices
    QOpenGLBuffer            mVertexBuffer;    // OpenGL buffer that holds the vertexes
};

#endif // YSSHAPE_H
