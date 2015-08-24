#ifndef YSPARTICLE_H
#define YSPARTICLE_H

#include <QDebug>
#include <QVector3D>
#include "YSSphere.h"

class YSParticle : public YSSphere
{
    Q_OBJECT
    Q_ENUMS(PARTICLETYPE)
    Q_ENUMS(COLOR)

public:

    enum PARTICLETYPE {
        QUARK, HADRON
    };

    enum COLOR { RED, BLUE, GREEN, WHITE, NONE} ;

    explicit YSParticle(PARTICLETYPE type, QObject *parent = 0);
    ~YSParticle();

    COLOR          Color() const;
    const char*    ColorName() const;
    void           Move(qreal time);
    QString        Name() const;
    double         PosX() const { return mPosition.x(); }
    double         PosY() const { return mPosition.y(); }
    double         PosZ() const { return mPosition.z(); }
    void           Print() const;
    void           SetColor(COLOR color);
    void           SetPosition(double xpos, double ypos, double zpos, double t = 0.0);
    void           SetVelocity(double betat, double betaz);
    PARTICLETYPE   Type() const { return mType; }

    bool IsActive() const { return mActive; }
//    float R() const { return mRed; }
//    float G() const { return mGreen; }
//    float B() const { return mBlue; }
    float Life() const { return mLife; }
    float Fade() const { return mFade; }
    void SetActive() { mActive = true; }
    void UnsetActive() { mActive = false; }
    void SetLife(float val) { mLife = val; }
    void SetFade(float val) { mFade = val; }
//    void SetColor(float c1, float c2, float c3) { mRed = c1; mGreen = c2; mBlue = c3; }
    void SetDirection( float x, float y, float z) {mXDirection = x; mYDirection = y; mZDirection = z; }
    void SetGravity(float x, float y, float z) {mXGravity = x; mYGravity = y; mZGravity = z; }
    void SetPos(float x, float y, float z) { mX = x; mY = y; mZ = z; }
    float X() const { return mX; }
    float Y() const { return mY; }
    float Z() const { return mZ; }
    float XD() const { return mXDirection; }
    float YD() const { return mYDirection; }
    float ZD() const { return mZDirection; }
    float XG() const { return mXGravity; }
    float YG() const { return mYGravity; }
    float ZG() const { return mZGravity; }

private:

    int                 mColor;         // color charge of the particle
    QVector3D           mPosition;      // particle's position in lab frame
    PARTICLETYPE        mType;          // kind of particle
    QVector3D           mVelocity;      // velocity vector relative to velocity of light
    QString             mTextures[NONE];// liste of texture files name
    bool  mActive;
    float mLife;
    float mFade;
//    float mRed;
//    float mGreen;
//    float mBlue;
    float mX;
    float mY;
    float mZ;
    float mXDirection;
    float mYDirection;
    float mZDirection;
    float mXGravity;
    float mYGravity;
    float mZGravity;
};

#endif // YSPARTICLE_H
