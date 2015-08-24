#ifndef YSSPHERE_H
#define YSSPHERE_H


#include "YSShape.h"
class YSSphere : public YSShape
{
public:
    YSSphere(QObject *parent);
    YSSphere(double radius, int seg, double degrees = 0.0, QObject *parent = 0);
    ~YSSphere(){;}

    void CreateVertices();
    void SetShape(double radius, int segments) { mRadius = radius; mSeg = segments; CreateVertices();}

private:
    double mRadius; // radius of the sphere
    int    mSeg;    // number of polygonal segmentation
};

#endif // YSSPHERE_H
