#ifndef YSPARALLELOGRAM_H
#define YSPARALLELOGRAM_H

#include "YSShape.h"

class YSParallelogram : public YSShape
{
public:
    YSParallelogram();
    YSParallelogram(double width, double height, double angle = 90.0, double degrees = 0.0, QObject *parent = 0);
    ~YSParallelogram(){;}

    void Create();
    double Height() const { return mHeight; }
    double Slant() const { return mSlant; }
    double Width() const { return mWidth; }

private:
    double mAngle;  // angle for a parallelepiped
    double mHeight; // length along y
    double mSlant;  // slant
    double mWidth;  // length along x
};

#endif // YSPARALLELOGRAM_H
