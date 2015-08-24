#ifndef YSSTAR_H
#define YSSTAR_H

#include <QObject>

class YSStar : public QObject
{
    Q_OBJECT
public:
    explicit YSStar(QObject *parent = 0);
    ~YSStar();

    float Angle() const { return mAngle; }
    float Dist() const { return mDist; }
    int   Blue() const { return mBlue; }
    int   Green() const { return mGreen; }
    int   Red() const { return mRed; }
    void  SetAngle(float angle) { mAngle = angle; }
    void  SetDist(float dist) { mDist = dist; }
    void  SetColor(float r, float g, float b) { mRed = r; mGreen = g; mBlue = b; }

private:
    float mAngle;               // star current angle
    float mDist;                // star distance from center
    int   mRed, mGreen, mBlue;  // star color
};

#endif // YSSTAR_H
