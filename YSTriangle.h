#ifndef YSTRIANGLE_H
#define YSTRIANGLE_H

#include "YSShape.h"

class YSTriangle : public YSShape
{
 public:
    enum TriangleType { ISOC, RECT, GEN };

    explicit YSTriangle();
    YSTriangle(double b, double h, TriangleType type, double xc = 0.0, double degrees = 0.0, QObject *parent = 0);
    ~YSTriangle(){;}

    double  Base() const { return mB; }
    void    CreateVertices();
    double  Height() const { return mH; }

private:
    void    Cdg();

    double mB;          // Base width
    double mH;          // Height
    TriangleType mType; // Type of tiangle
    double mXc;         // x coordinate of apex (in case of general triangle)
    double mXg, mYg;    // coordinates of center of gravity
};

#endif // YSTRIANGLE_H
