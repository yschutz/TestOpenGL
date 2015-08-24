#include <QDebug>
#include "YSSphere.h"
#include "YSVertex.h"
//=====================================================================================
YSSphere::YSSphere(QObject *parent) : YSShape("Sphere", 0, parent), mRadius(0.0), mSeg(0)
{
    // default ctor
}

//=====================================================================================
YSSphere::YSSphere(double radius, int seg, double degrees, QObject *parent) : YSShape("Sphere", degrees, parent),
    mRadius(radius), mSeg(seg)
{
    // ctor
    CreateVertices();
}

//=====================================================================================
void YSSphere::CreateVertices()
{
    // calculate vertices

    const double kStep = M_PI / (double)mSeg;
    mVertextList.clear();
    for (double phi = 0.0; phi < M_PI; phi += kStep) {
        for (double theta = 0.0; theta < 2 * M_PI; theta += kStep) {
            double x = mRadius * qCos(theta) * qSin(phi); //1
            double y = mRadius * qSin(theta) * qSin(phi);
            double z = mRadius               * qCos(phi);
            double v = phi / M_PI;
            double u = theta / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
            x = mRadius * qCos(theta + kStep) * qSin(phi); //2
            y = mRadius * qSin(theta + kStep) * qSin(phi);
            z = mRadius               * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
            x = mRadius * qCos(theta) * qSin(phi + kStep); //3
            y = mRadius * qSin(theta) * qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
            x = mRadius * qCos(theta + kStep) * qSin(phi); //2
            y = mRadius * qSin(theta + kStep) * qSin(phi);
            z = mRadius               * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
            x = mRadius * qCos(theta + kStep) * qSin(phi + kStep); //4
            y = mRadius * qSin(theta + kStep) * qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
            x = mRadius * qCos(theta) * qSin(phi + kStep); //3
            y = mRadius * qSin(theta) * qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);
            mVertextList.append(new YSVertex(x, y, z, u, v));
        }
    }
}
