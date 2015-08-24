#ifndef YSANNULUS_H
#define YSANNULUS_H


#include "YSShape.h"

class YSPolygon;

class YSAnnulus : public YSShape
{
public:
    YSAnnulus();
    YSAnnulus(double rout, double rin, int nseg, double degrees = 0.0, QObject *parent = 0);
    ~YSAnnulus();

    void   CreateVertices();
    double RadiusOut() const { return mROu; }
    double Radiusin()  const { return mRIn; }

private:
    YSPolygon *mPolIn;    // inner polygon
    YSPolygon *mPolOu;    // outer polygon
    double    mROu;       // outer radius
    double    mRIn;       // inner radius
    int       mSeg;       // number of sides
};

#endif // YSANNULUS_H
