// base class of a shape that can be drawn with OpenGL
#include <qmath.h>
#include <QDebug>
#include <QImage>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QVector>

#include "YSrgba.h"
#include "YSShape.h"
#include "YSVertex.h"

//=====================================================================================
YSShape::YSShape(const char *objName, double degrees, QObject *parent) : QObject(parent), 
    mColor(false), mDegrees(degrees), mMode(GL_TRIANGLES), mTexture(NULL), mTextureImageName("")
{
    // ctor
    setObjectName(QString(objName));
    mShaderProgram = new QOpenGLShaderProgram(this); 
    mVertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer); 
    mIndexBuffer  = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

    ResetTransform();

    mRot = qDegreesToRadians(degrees);
    mRGB.clear();
}

//=====================================================================================
YSShape::~YSShape()
{
    // dtor
    mIndexBuffer.destroy();
    mVertexBuffer.destroy();
    mVAO.destroy();
}

//=====================================================================================
void YSShape::AddColor(float r, float g, float b, float a)
{
    // add a lolor to the color list
    mRGB.append(new YSrgba(r, g, b, a));
    mColor = true;
}

//=====================================================================================
//void YSShape::AddTexture(QString textureName)
//{
//    // add textures to the shape
//    mTexture = true;
//    mTexArray = new GLuint[1];
//    glGenTextures(1, &mTexArray[0]); // prepare the array to receive the texture
//    // load the image for the texture
//    QImage imTexture;
//    QImage imTextureTemp;
//    bool rv = imTextureTemp.load(textureName);
//    if (!rv) {
//        qDebug() << Q_FUNC_INFO << " Error: " << textureName << " not found";
//        exit(1);
//    }
//    imTexture = QGLWidget::convertToGLFormat(imTextureTemp);

//    // Create nearest filtered texture: quick but bad
////    glBindTexture(GL_TEXTURE_2D, mTexArray[0]);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////    glTexImage2D(GL_TEXTURE_2D, 0, 3, imTexture.width(), imTexture.height(), 0, GL_RGBA,GL_UNSIGNED_BYTE, imTexture.bits()); // defines the properties of the image

////    // Create linear filtered texture: not so fast but nicer
////    glBindTexture(GL_TEXTURE_2D, mTexArray[0]);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////    glTexImage2D(GL_TEXTURE_2D, 0, 3, imTexture.width(), imTexture.height(), 0, GL_RGBA,GL_UNSIGNED_BYTE, imTexture.bits()); // defines the properties of the image

//    // Create linear filtered texture: best for details when image becomes small
//    glBindTexture(GL_TEXTURE_2D, mTexArray[0]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imTexture.width(), imTexture.height(), GL_RGBA, GL_UNSIGNED_BYTE, imTexture.bits());

//    glEnable(GL_TEXTURE_2D);
//}

//=====================================================================================
void YSShape::Bind()
{
    // bind the VBO and texture
    
   Shaders()->bind(); 
   if (mTexture) {
       mTexture->bind();
       Shaders()->setUniformValue("textureEnabled", true);
   } else {
       Shaders()->setUniformValue("textureDisabled", false);
   }
   mVAO.bind();
}

//=====================================================================================
void YSShape::Create()
{
    if (mVertextList.size() == 0) {
        qDebug() << Q_FUNC_INFO << "no vertices defined for shape" << objectName(); 
        exit(1); 
    }
    SetDefaultShaders();
    mVertexBuffer.create();
    mVertexBuffer.bind();
    mVertexBuffer.allocate(mVertextList.data(), mVertextList.count() * sizeof(YSVertex));
    mVertexBuffer.release();

    if (mIndexList.count()) {
        mIndexBuffer.create();
        mIndexBuffer.bind();
        mIndexBuffer.allocate(mIndexList.data(), mIndexList.count() * sizeof(GLuint));
        mIndexBuffer.release();
    }

    mVAO.create();
    mVAO.bind();

    mIndexBuffer.bind();
    mVertexBuffer.bind();

    Shaders()->bind();

    // position coordinates: first 3 32 bits data members of YSVertex (see also :/shaders/default_vertex.vsh)
    Shaders()->enableAttributeArray("PosCoord");
    Shaders()->setAttributeBuffer("PosCoord", GL_FLOAT, YSVertex::PosStart, 3, sizeof(YSVertex));
    
    // texture coordinates: Next 2 32 bits data members of YSVertex (see also :/shaders/default_vertex.vsh)
    Shaders()->enableAttributeArray("TexCoord");
    Shaders()->setAttributeBuffer("TexCoord", GL_FLOAT, YSVertex::TexStart * sizeof(GL_FLOAT), 2, sizeof(YSVertex));

    mVAO.release();
    qDebug() << Q_FUNC_INFO << "Shape has been created";
    
}

//=====================================================================================
void YSShape::Release()
{
    // releases all the buffers
    
    mVAO.release();
    if (mTexture)
        mTexture->release();
    Shaders()->release();
}

//=====================================================================================
//void YSShape::Draw()
//{
//    // Draw the shape
//    if (mTexture)
//        glBindTexture(GL_TEXTURE_2D, mTexArray[0]);
//    glBegin(GL_TRIANGLES);
//    int cindex ;
//    for (int index = 0; index < mVertextList.size(); index++) {
////        if (mColor) {
////               if (cindex >= mRGB.size())
////                   cindex = 0;
////               qDebug() << Q_FUNC_INFO << cindex << mRGB.size();
////               glColor4d(mRGB.at(cindex)->R(), mRGB.at(cindex)->G(), mRGB.at(cindex)->B(), mRGB.at(cindex)->A());
////               cindex++;
////        }
//        if (IsTexture())
//            glTexCoord2d(mVertextList.at(index)->U(), mVertextList.at(index)->V());
//        glVertex3d(mVertextList.at(index)->X(),
//                   mVertextList.at(index)->Y(),
//                   mVertextList.at(index)->Z());
//    }
//    glEnd();
//}

//=====================================================================================
void YSShape::SetShaders(const QString &vertexfile, const QString &fragmentFile)
{
    // set the shaders from files 
    
    mShaderProgram->removeAllShaders();
    mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexfile); 
    mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile); 
    mShaderProgram->link(); 
}

//=====================================================================================
void YSShape::SetDefaultShaders()
{
    // set default shaders
    
    SetShaders(":/shaders/default_vertex.vsh", ":/shaders/default_fragment.fsh");
}

//=====================================================================================
void YSShape::SetDepth(double z)
{
    // set the depth of the shape
    for (int index = 0; index < mVertextList.size(); index++)
        mVertextList.at(index)->SetZ(mVertextList.at(index)->Z() + z);
}

//=====================================================================================
void YSShape::SetTexture(const QImage &image)
{
    // associate texture to shape 
    qDebug() << Q_FUNC_INFO << mTexture;
    if (mTexture != NULL)
        delete mTexture; 
    mTexture = new QOpenGLTexture(image); 
    mTexture->create(); 
}

//=====================================================================================
YSVertex *YSShape::Vertex(int index)
{
    // return vertex number index

    if (index >= mVertextList.size()) {
        qDebug() << Q_FUNC_INFO << "Error: there is no" << index << "vertex";
        exit(1);
    } else {
        return mVertextList.at(index);
    }
}

