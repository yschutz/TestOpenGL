#include <QDebug>
#include "YSAnnulus.h"
#include "YSCylinder.h"
#include "YSTube.h"

//=====================================================================================
YSTube::YSTube() : YSShape("Tube"), mInRadius(0.0), mLength(0.0), mOuRadius(0.0), mSeg(0)
{
    // default ctor

}

//=====================================================================================
YSTube::YSTube(double outRadius, double inRadius, int seg, double length, double degrees, QObject *parent) :
    YSShape("Tube", degrees, parent),
    mInRadius(inRadius), mLength(length), mOuRadius(outRadius), mSeg(seg)
{
    // ctor
    mCyIn = new YSCylinder(mInRadius, mSeg, mLength, mDegrees, this);
    mCyOu = new YSCylinder(mOuRadius, mSeg, mLength, mDegrees, this);
    CreateVertices();
}

//=====================================================================================
YSTube::~YSTube()
{
    // dtor
}

//=====================================================================================
void YSTube::CreateVertices()
{
    for(int index = 0; index < mCyIn->Vertices(); index++) {
        mVertextList.append(mCyIn->Vertex(index));
    }
    for(int index = 0; index < mCyOu->Vertices(); index++) {
        mVertextList.append(mCyOu->Vertex(index));
    }
}

