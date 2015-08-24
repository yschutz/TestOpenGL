#include <QDebug>
#include <QImage>
#include <qmath.h>
#include <QString>
#include "YSParticle.h"

//=====================================================================================
YSParticle::YSParticle(PARTICLETYPE type, QObject *parent) : YSSphere(),
    mPosition(0.0, 0.0, 0.0), mType(type), mVelocity(0.0, 0.0, 0.0)
{
    setParent(parent);
    setObjectName(Name());

    mTextures[RED]   = ":/textures/images/RedQuark.png";
    mTextures[BLUE]  = ":/textures/images/BlueQuark.png";
    mTextures[GREEN] = ":/textures/images/GreenQuark.png";
    mTextures[WHITE] = ":/textures/images/WhiteHadron.png";
    double radius   = 0.0;
    int    segments = 20;
    switch (type) {
    case QUARK:
        radius = 0.5;
        break;
    case HADRON:
        radius = 1.0;
        break;
    default:
        break;
    }
    SetShape(radius, segments);
}

//=====================================================================================
YSParticle::~YSParticle()
{
}

//=====================================================================================
YSParticle::COLOR YSParticle::Color() const
{
 // return color charge
    COLOR rv;
    switch (mColor) {
    case RED:
        rv = RED;
        break;
    case BLUE:
        rv = BLUE;
        break;
    case GREEN:
        rv = GREEN;
        break;
    case WHITE:
        rv = WHITE;
        break;
    default:
        rv = NONE;
        break;
    }
    return rv;
}

//=====================================================================================
const char *YSParticle::ColorName() const
{
    // returns the color name
    const char * name;
    switch (mColor) {
    case RED:
        name = "RED";
        break;
    case BLUE:
        name = "BLUE";
        break;
    case GREEN:
        name = "GREEN";
        break;
    case WHITE:
        name = "WHITE";
        break;
    default:
        name = "WHITE";
        break;
    }
    return name;
}

//=====================================================================================
QString YSParticle::Name() const
{
    // return the name of the particle

    switch (mType) {
    case QUARK:
        return QString("Quark");
        break;
    case HADRON:
        return QString("Hadron");
        break;
    default:
        qDebug() << Q_FUNC_INFO << ": " << mType << "not a valid particle type";
        exit(1);
        break;
    }
}

//=====================================================================================
void YSParticle::Print() const
{
    // print info on the particle
    qDebug() << Q_FUNC_INFO << Name() << "color charge =" << ColorName();
}

//=====================================================================================
void YSParticle::SetColor(COLOR color)
{
    // set the color charge of the particle

    switch (mType) {
    case QUARK:
        mColor = color;
        break;
    case HADRON:
        mColor = WHITE;
    default:
        break;
    }
    mTextureImageName = mTextures[mColor];
}

//=====================================================================================
void YSParticle::Move(qreal time)
{
    // set the particle position at time t
    mPosition.setX(mPosition.x() + mVelocity.x() * time);
    mPosition.setY(mPosition.y() + mVelocity.y() * time);
    mPosition.setZ(mPosition.z() + mVelocity.z() * time);
}

//=====================================================================================
void YSParticle::SetVelocity(double betat, double betaz)
{
    // set the 3D velocity vector of particle: betat (transverse velocity), betaz (longitudinal velocity)

    int sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    sign = 1;
    mVelocity.setZ(betaz * sign);
    double x = (double)qrand() / ((double)RAND_MAX);
    sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    mVelocity.setX(betat * x * sign);
    double y =  qSqrt(1 - x*x);
    sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    mVelocity.setY(betat * y * sign);
}

