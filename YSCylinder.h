#ifndef YSCYLINDER_H
#define YSCYLINDER_H

#include "YSShape.h"
class YSCylinder : public YSShape
{
public:
    YSCylinder();
    YSCylinder(double radius, int seg, double length, double degrees = 0.0, QObject *parent = 0);
    ~YSCylinder(){;}

    void   CreateVertices();
    double Length() const { return mLength; }
    double Radius() const { return mRadius; }


private:
    double mLength;    // length of the cylinder (z direction)
    double mRadius;    // radius cercle circonscrit
    double mSeg;       // number of sides of the base
};

#endif // YSCYLINDER_H
