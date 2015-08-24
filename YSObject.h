#ifndef YSOBJECT_H
#define YSOBJECT_H

#include <QObject>

class YSObject : public QObject
{
    Q_OBJECT
public:
    explicit YSObject(QObject *parent = 0);
    ~YSObject();

    void Reset() { mPosX = 0; mPosY = 0; mMovX = 0; mMovY = 0; }
    void SetPos(int x, int y) { mPosX = x; mPosY = y; }
    void SetMov(int x, int y) { mMovX = x; mMovY = y; }
    void SetSpin(float s) { mSpin = s; }
    float Spin() const { return mSpin; }
    void Set(int x, int y, int fx, int fy) { SetPos(x, y); SetMov(fx, fy); }
    int X() const { return mPosX; }
    int Y() const { return mPosY; }
    int FX() const { return mMovX; }
    int FY() const { return mMovY; }


private:
   int mPosX, mPosY;
   int mMovX, mMovY;
   float mSpin;

};

#endif // YSOBJECT_H
