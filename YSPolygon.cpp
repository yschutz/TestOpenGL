#include <QDebug>
#include <qmath.h>
#include "YSPolygon.h"
#include "YSVertex.h"

//=====================================================================================
YSPolygon::YSPolygon() : YSShape("Polygon"), mRadius(0.0), mSeg(0)
{
    // default ctor
}

//=====================================================================================
YSPolygon::YSPolygon(double radius, int nseg, double degrees, QObject *parent) : YSShape("Polygon", degrees, parent),
    mRadius(radius), mSeg(nseg)
{
    // ctor
    CreateVertices();
}

//=====================================================================================
void YSPolygon::CreateVertices()
{
    // calculate vertices

    double angStep = qDegreesToRadians(360. / mSeg);
    double ang = 0.0;
    YSVertex* center = new YSVertex(0.0, 0.0, 0.0,  0.5, 0.5);
    for( int count = 0; count < mSeg; count++) {
        mVertextList.append(new YSVertex(mRadius * qCos(ang + mRot),           mRadius * qSin(ang + mRot),           0.0,  0.5 + 0.5 * qCos(ang + mRot),           0.5 + 0.5 * qSin(ang + mRot)));
        mVertextList.append(new YSVertex(mRadius * qCos(ang + angStep + mRot), mRadius * qSin(ang + angStep + mRot), 0.0,  0.5 + 0.5 * qCos(ang + angStep + mRot), 0.5 + 0.5 * qSin(ang + angStep + mRot)));
        mVertextList.append(center);
        ang += angStep;
    }
}
