#include <QtMath>
#include <QDebug>
#include "YSParallelogram.h"
#include "YSTriangle.h"
#include "YSVertex.h"

//=====================================================================================
YSParallelogram::YSParallelogram() : YSShape("Parallelogram"),
    mHeight(0.0), mSlant(0.0), mWidth(0.0)
{
    // ctor
}

//=====================================================================================
YSParallelogram::YSParallelogram(double width, double height, double angle, double degrees, QObject *parent) :
    YSShape("Parallelogram", degrees, parent), mAngle(angle), mHeight(height),  mWidth(width)
{
    // ctor
    mSlant =  qTan(qDegreesToRadians(90.0 -mAngle));
    Create();
}

//=====================================================================================
void YSParallelogram::Create()
{
    // calculates vertices

    YSTriangle rect(mWidth, mHeight, YSTriangle::GEN, -1 + mSlant);
    YSVertex *vt1 = rect.Vertex(0);
    YSVertex *vt2 = rect.Vertex(1);
    YSVertex *vt3 = rect.Vertex(2);

    YSVertex *vr1 = new YSVertex(vt1->X(), vt1->Y(), vt1->Z(), 0, 0);
    YSVertex *vr2 = new YSVertex(vt2->X(), vt2->Y(), vt2->Z(), 1, 0);
    YSVertex *vr3 = new YSVertex(vt3->X(), vt3->Y(), vt3->Z(), 0, 1);
    mVertextList.append(vr1);
    mVertextList.append(vr2);
    mVertextList.append(vr3);
    YSVertex *vr4 = new YSVertex(vr2->X(),          vr2->Y(), vr2->Z(), 1, 0);
    YSVertex *vr5 = new YSVertex(vr2->X() + mSlant, vr3->Y(), vr1->Z(), 1, 1);
    YSVertex *vr6 = new YSVertex(vr3->X(),          vr3->Y(), vr1->Z(), 0, 1);
    mVertextList.append(vr4);
    mVertextList.append(vr5);
    mVertextList.append(vr6);
}

