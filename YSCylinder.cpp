#include <QDebug>
#include <qmath.h>
#include "YSCylinder.h"
#include "YSVertex.h"

//=====================================================================================
YSCylinder::YSCylinder() : YSShape("Cylinder"),
    mLength(0.0), mRadius(0.0), mSeg(0)
{
    // default ctor
}

//=====================================================================================
YSCylinder::YSCylinder(double radius, int seg, double length, double degrees, QObject *parent) : YSShape("Cylinder", degrees, parent),
    mLength(length), mRadius(radius), mSeg(seg)
{
    // ctor
    CreateVertices();
}

//=====================================================================================
void YSCylinder::CreateVertices()
{
    // calculate vertices

    double angStep = qDegreesToRadians(360. / mSeg);
    double ang = 0.0;

    for(int count = 0; count < mSeg; count++) {
        mVertextList.append(new YSVertex(mRadius * qCos(ang           + mRot), mRadius * qSin(ang           + mRot),  mLength / 2.0, 0.0, (ang           ) / M_PI / 2)); //0
        mVertextList.append(new YSVertex(mRadius * qCos(ang           + mRot), mRadius * qSin(ang           + mRot), -mLength / 2.0, 1.0, (ang           ) / M_PI / 2)); //1
        mVertextList.append(new YSVertex(mRadius * qCos(ang + angStep + mRot), mRadius * qSin(ang + angStep + mRot),  mLength / 2.0, 0.0, (ang + angStep ) / M_PI / 2)); //2

        mVertextList.append(new YSVertex(mRadius * qCos(ang           + mRot), mRadius * qSin(ang           + mRot), -mLength / 2.0, 1.0, (ang           ) / M_PI / 2)); //3
        mVertextList.append(new YSVertex(mRadius * qCos(ang + angStep + mRot), mRadius * qSin(ang + angStep + mRot), -mLength / 2.0, 1.0, (ang + angStep ) / M_PI / 2)); //4
        mVertextList.append(new YSVertex(mRadius * qCos(ang + angStep + mRot), mRadius * qSin(ang + angStep + mRot),  mLength / 2.0, 0.0, (ang + angStep ) / M_PI / 2)); //5
        ang += angStep;
    }
}
