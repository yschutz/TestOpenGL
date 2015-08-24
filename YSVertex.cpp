#include <QDebug>
#include "YSVertex.h"

//=====================================================================================
YSVertex::YSVertex(QObject *parent) : QObject(parent)
{
    SetAll(0.0, 0.0, 0.0, 0.0, 0.0);
}

//=====================================================================================
YSVertex::YSVertex(double x, double y, double z, double u, double v, QObject *parent) : QObject(parent)
{
    SetAll(x, y, z, u, v);
}

//=====================================================================================
YSVertex::YSVertex(const YSVertex &vertex) : mX(vertex.mX), mY(vertex.mY), mZ(vertex.mZ), mU(vertex.mU), mV(vertex.mV)
{
    //copy ctor
}

//=====================================================================================
YSVertex::~YSVertex()
{

}

//=====================================================================================
void YSVertex::Print() const
{
    // Print
    qDebug() << mX << mY << mZ << mU << mV;
}

