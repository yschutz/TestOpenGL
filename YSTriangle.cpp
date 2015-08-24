#include <QDebug>

#include "YSrgba.h"
#include "YSTriangle.h"
#include "YSVertex.h"

//=====================================================================================
YSTriangle::YSTriangle() : YSShape("Triangle"),  mB(0.0), mH(0.0), mXc(0.0)
{
    //ctor
}

//=====================================================================================
YSTriangle::YSTriangle(double b, double h, TriangleType type, double xc, double degrees, QObject *parent) :
    YSShape("Triangle", degrees, parent), mB(b), mH(h), mType(type), mXc(xc)
{
 // define a triangle with base width = b and height =h

    Cdg();
    CreateVertices();
}

//=====================================================================================
void YSTriangle::CreateVertices()
{
    // Calculate the vertices for the triangle: centered at (0,0)
    YSVertex *v1, *v2, *v3;
    v1 = new YSVertex(-1, -1, 0.0, 0.0, 0.0);
    v2 = new YSVertex( 1, -1, 0.0, 1.0, 0.0);
    switch (mType) {
    case ISOC:
        v3 = new YSVertex(0.0,        1, 0.0, 0.5, 1.0);
        break;
    case RECT:
        v3 = new YSVertex(-1,  1, 0.0, 0.5, 1.0);
        break;
    case GEN:
        v3 = new YSVertex( mXc,       1, 0.0, 0.5, 1.0);
        break;
    default:
        break;
    }
    mVertextList.append(v1);
    mVertextList.append(v2);
    mVertextList.append(v3);

}

//=====================================================================================
void YSTriangle::Cdg()
{
    // calculates center of gravity
    double num =  2 * mH / mB / (mXc - mB / 2.0) - mB * mH / (mXc - 2.0 * mB);
    double den = mH / (mXc - mB / 2.0) - mH / (mXc - 2.0 * mB);
    mXg = num / den;
    mYg = mH * mXg / (mXc - 2.0 * mB) - mB * mH / (mXc - 2.0 * mB);
}

