#ifndef YSVERTEX_H
#define YSVERTEX_H

#include <OpenGL.h>
#include <QObject>
class YSVertex
{
public:
    static const int PosStart = 0; // first position coordinate in data member
    static const int TexStart = 3; // first texture coordinate in data member

    explicit YSVertex();
    YSVertex(qreal x, qreal y, qreal z, qreal u, qreal v);
    YSVertex(const YSVertex& vertex);

    ~YSVertex();

    void Print() const;
    void SetAll(qreal x, qreal y, qreal z, qreal u, qreal v) {
        mX = x;
        mY = y;
        mZ = z;
        mU = u;
        mV = v;
    }
    void     SetX(qreal val) { mX = val; }
    void     SetY(qreal val) { mY = val; }
    void     SetZ(qreal val) { mZ = val; }
    void     SetU(qreal val) { mU = val; }
    void     SetV(qreal val) { mV = val; }
    float X() const { return mX; }
    float Y() const { return mY; }
    float Z() const { return mZ; }
    float U() const { return mU; }
    float V() const { return mV; }

private:
    float mX, mY, mZ; // 3D coordinates
    float mU, mV;     // Texture coordinates
};

#endif // YSVERTEX_H
