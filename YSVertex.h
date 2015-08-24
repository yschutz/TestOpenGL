#ifndef YSVERTEX_H
#define YSVERTEX_H

#include <OpenGL/gl.h>
#include <QObject>
class YSVertex : public QObject
{
    Q_OBJECT
public:
    static const int PosStart = 0; // first position coordinate in data member
    static const int TexStart = 3; // first texture coordinate in data member

    explicit YSVertex(QObject *parent = 0);
    YSVertex(qreal x, qreal y, qreal z, qreal u, qreal v, QObject *parent = 0);
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
    qreal X() const { return mX; }
    qreal Y() const { return mY; }
    qreal Z() const { return mZ; }
    qreal U() const { return mU; }
    qreal V() const { return mV; }

private:
    float mX, mY, mZ; // 3D coordinates
    float mU, mV;     // Texture coordinates
};

#endif // YSVERTEX_H
