#ifndef YSPOLYGON_H
#define YSPOLYGON_H

#include "YSShape.h"
class YSPolygon : public YSShape
{
public:
    YSPolygon();
    YSPolygon(double radius, int nseg, double degrees = 0.0, QObject *parent = 0);
    ~YSPolygon(){;}

    void   CreateVertices();
    double Radius() const { return mRadius; }

private:
    double mRadius; // radius cercle circonscrit
    int    mSeg;    // number of sides
};

#endif // YSPOLYGON_H
