#ifndef YSPYRAMIDE_H
#define YSPYRAMIDE_H

#include "YSShape.h"
class YSPyramide : public YSShape
{
public:
    YSPyramide();
    YSPyramide(double b, double h, double degrees = 0.0, QObject *parent = 0);
    ~YSPyramide(){;}

    double Base() const { return mB; }
    void   Create();
    double Height() const { return mH; }
    void   Init() {}


private:
    double mB; // base
    double mH; // height
};

#endif // YSPYRAMIDE_H
