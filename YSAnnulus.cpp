#include <QDebug>
#include "YSAnnulus.h"
#include "YSPolygon.h"
#include "YSVertex.h"

//=====================================================================================
YSAnnulus::YSAnnulus() : YSShape("Annulus"),
    mROu(0.0), mRIn(0.0), mSeg(0.0)
{
    // default ctor
}

//=====================================================================================
YSAnnulus::YSAnnulus(double rout, double rin, int nseg, double degrees, QObject *parent): YSShape("Annulus", degrees, parent),
    mROu(rout), mRIn(rin), mSeg(nseg)
{
    // ctor
    mPolOu = new YSPolygon(mROu, mSeg, mDegrees, this);
    mPolIn = new YSPolygon(mRIn, mSeg, mDegrees, this);
    CreateVertices();

}

//=====================================================================================
YSAnnulus::~YSAnnulus()
{
 // dtor
}

//=====================================================================================
void YSAnnulus::CreateVertices()
{
    // calculates vertices

    double angStep = qDegreesToRadians(360. / mSeg);
    double ang = 0.0;

    int index = 0;

    for (int count = 0; count < mPolOu->Vertices() / 3; count++) {
        mVertextList.append(mPolOu->Vertex(index));
        mVertextList.append(mPolOu->Vertex(index+1));
        mPolIn->Vertex(index)->SetU(         0.5 + mRIn/mROu * 0.5 * qCos(ang + mRot));
        mPolIn->Vertex(index)->SetV(         0.5 + mRIn/mROu * 0.5 * qSin(ang + mRot));
        mVertextList.append(mPolIn->Vertex(index));

        mVertextList.append(mPolOu->Vertex(index+1));
        mPolIn->Vertex(index+1)->SetU(         0.5 + mRIn/mROu * 0.5 * qCos(ang + angStep + mRot));
        mPolIn->Vertex(index+1)->SetV(         0.5 + mRIn/mROu * 0.5 * qSin(ang + angStep + mRot));
        mVertextList.append(mPolIn->Vertex(index+1));
        mVertextList.append(mPolIn->Vertex(index));
        index +=3;
        ang += angStep;
    }
}

