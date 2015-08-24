#ifndef YSTUBE_H
#define YSTUBE_H

#include "YSShape.h"
class YSCylinder;

class YSTube : public YSShape
{
public:
    YSTube();
    YSTube(double outRadius, double inRadius, int seg, double length, double degrees = 0.0, QObject *parent = 0);
    ~YSTube();
    
    void   CreateVertices(); 
    double InRadius() const { return mInRadius; }
    double Length() const { return mLength; }
    double OuRadius() const { return mOuRadius; }
    
private: 
    YSCylinder *mCyIn;    // inner cylinder
    YSCylinder *mCyOu;    // outer cylinder
    double     mInRadius; // radius of inner cylinder
    double     mLength;   // length of cylinder
    double     mOuRadius; // radius of outer cylinder
    double     mSeg;      // nmber of sides of the base
};

#endif // YSTUBE_H
