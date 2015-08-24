#ifndef YSPARALLELEPIPED_H
#define YSPARALLELEPIPED_H

#include "YSShape.h"

class YSParallelepiped : public YSShape
{
public:
    YSParallelepiped();
    YSParallelepiped(double width, double height, double depth, double angle = 90.0, double degrees = 0.0, QObject *parent = 0);
    ~YSParallelepiped(){;}

    void   CreateVertices();
    double Depth() const { return mDepth; }
    double Height() const { return mHeight; }
    double Width() const { return mWidth; }

private:
    double mAngle;   //slanting angle (= 90 for rectangular Parallelepiped)
    double mDepth;   //dim along z
    double mHeight;  //dim along y
    double mWidth;   //dim along x
};

#endif // YSPARALLELEPIPED_H
