#include <QDebug>
#include "YSParallelepiped.h"
#include "YSParallelogram.h"
#include "YSVertex.h"
//=====================================================================================
YSParallelepiped::YSParallelepiped() :  YSShape("Paralleliped"), mAngle(0.0), mDepth(0.0), mHeight(0.0), mWidth(0.0)
{
    // ctor
}

//=====================================================================================
YSParallelepiped::YSParallelepiped(double width, double height, double depth, double angle, double degrees, QObject *parent) :
    YSShape("Paralleliped", degrees, parent), mAngle(angle), mDepth(depth), mHeight(height), mWidth(width)
{
    // ctor
    CreateVertices();
}

//=====================================================================================
void YSParallelepiped::CreateVertices()
{
    // calculate vertices
    YSParallelogram para(mWidth, mHeight, mAngle);
//    YSVertex *vp1 = para.Vertex(0);
//    YSVertex *vp2 = para.Vertex(1);
//    YSVertex *vp3 = para.Vertex(2);

    //front
    YSVertex *vb1 = new YSVertex(para.Vertex(0)->X(), para.Vertex(0)->Y(), para.Vertex(0)->Z() + 1, 0, 0);
    YSVertex *vb2 = new YSVertex(para.Vertex(1)->X(), para.Vertex(1)->Y(), para.Vertex(1)->Z() + 1, 1, 0);
    YSVertex *vb3 = new YSVertex(para.Vertex(2)->X(), para.Vertex(2)->Y(), para.Vertex(2)->Z() + 1, 0, 1);
    YSVertex *vb4 = new YSVertex(para.Vertex(3)->X(), para.Vertex(3)->Y(), para.Vertex(3)->Z() + 1, 1, 0);
    YSVertex *vb5 = new YSVertex(para.Vertex(4)->X(), para.Vertex(4)->Y(), para.Vertex(4)->Z() + 1, 1, 1);
    YSVertex *vb6 = new YSVertex(para.Vertex(5)->X(), para.Vertex(5)->Y(), para.Vertex(5)->Z() + 1, 0, 1);

    mVertextList.append(vb1);
    mVertextList.append(vb2);
    mVertextList.append(vb3);
    mVertextList.append(vb4);
    mVertextList.append(vb5);
    mVertextList.append(vb6);
    qDebug() << "front";
    vb1->Print();    vb2->Print();    vb3->Print();    vb4->Print();    vb5->Print();    vb6->Print();

    // right
    YSVertex *vb7  = new YSVertex(vb4->X(),  vb4->Y(),        vb4->Z(),        0, 0);
    YSVertex *vb8  = new YSVertex(vb7->X(),  vb7->Y(),        vb7->Z() - 2.0,  1, 0);
    YSVertex *vb9  = new YSVertex(vb5->X(),  vb5->Y(),        vb5->Z(),        0, 1);
    YSVertex *vb10 = new YSVertex(vb8->X(),  vb8->Y(),        vb8->Z(),        1, 0);
    YSVertex *vb11 = new YSVertex(vb10->X() + para.Slant(), vb10->Y() + 2.0, vb10->Z(),       1, 1);
    YSVertex *vb12 = new YSVertex(vb9->X(),  vb9->Y(),        vb9->Z(),        0, 1);

    mVertextList.append(vb7);
    mVertextList.append(vb8);
    mVertextList.append(vb9);
    mVertextList.append(vb10);
    mVertextList.append(vb11);
    mVertextList.append(vb12);

    // back
    YSVertex *vb13  = new YSVertex(vb10->X(),        vb10->Y(),       vb10->Z(),      0, 0);
    YSVertex *vb14  = new YSVertex(vb13->X() - 2.0,  vb13->Y(),       vb13->Z(),      1, 0);
    YSVertex *vb15  = new YSVertex(vb14->X() + para.Slant(),        vb14->Y() + 2.0, vb14->Z(),       1, 1);
    YSVertex *vb16  = new YSVertex(vb15->X(),        vb15->Y(),       vb15->Z(),      1, 1);
    YSVertex *vb17  = new YSVertex(vb11->X(),        vb11->Y(),       vb11->Z(),      0, 1);
    YSVertex *vb18  = new YSVertex(vb13->X(),        vb13->Y(),       vb13->Z(),      0, 0);

    mVertextList.append(vb13);
    mVertextList.append(vb14);
    mVertextList.append(vb15);
    mVertextList.append(vb16);
    mVertextList.append(vb17);
    mVertextList.append(vb18);

    // left
    YSVertex *vb19  = new YSVertex(vb14->X(),        vb14->Y(),       vb14->Z(),      0, 0);
    YSVertex *vb20  = new YSVertex(vb1->X(),         vb1->Y(),        vb1->Z(),       1, 0);
    YSVertex *vb21  = new YSVertex(vb6->X(),         vb6->Y(),        vb6->Z(),       1, 1);
    YSVertex *vb22  = new YSVertex(vb21->X(),        vb21->Y(),       vb21->Z(),      1, 1);
    YSVertex *vb23  = new YSVertex(vb16->X(),        vb16->Y(),       vb16->Z(),      0, 1);
    YSVertex *vb24  = new YSVertex(vb19->X(),        vb19->Y(),       vb19->Z(),      0, 0);

    mVertextList.append(vb19);
    mVertextList.append(vb20);
    mVertextList.append(vb21);
    mVertextList.append(vb22);
    mVertextList.append(vb23);
    mVertextList.append(vb24);

    // top
    YSVertex *vb25  = new YSVertex(vb22->X(),        vb22->Y(),       vb22->Z(),      0, 0);
    YSVertex *vb26  = new YSVertex(vb12->X(),        vb12->Y(),       vb12->Z(),      1, 0);
    YSVertex *vb27  = new YSVertex(vb23->X(),        vb23->Y(),       vb23->Z(),      0, 1);
    YSVertex *vb28  = new YSVertex(vb26->X(),        vb26->Y(),       vb26->Z(),      1, 0);
    YSVertex *vb29  = new YSVertex(vb17->X(),        vb17->Y(),       vb17->Z(),      1, 1);
    YSVertex *vb30  = new YSVertex(vb27->X(),        vb27->Y(),       vb27->Z(),      0, 1);

    mVertextList.append(vb26);
    mVertextList.append(vb25);
    mVertextList.append(vb27);
    mVertextList.append(vb28);
    mVertextList.append(vb29);
    mVertextList.append(vb30);

    // bottom
    YSVertex *vb31  = new YSVertex(vb24->X(),        vb24->Y(),       vb24->Z(),      0, 0);
    YSVertex *vb32  = new YSVertex(vb18->X(),        vb18->Y(),       vb18->Z(),      1, 0);
    YSVertex *vb33  = new YSVertex(vb7->X(),         vb7->Y(),        vb7->Z(),       1, 1);
    YSVertex *vb34  = new YSVertex(vb33->X(),        vb33->Y(),       vb33->Z(),      1, 1);
    YSVertex *vb35  = new YSVertex(vb20->X(),        vb20->Y(),       vb20->Z(),      0, 1);
    YSVertex *vb36  = new YSVertex(vb31->X(),        vb31->Y(),       vb31->Z(),      0, 0);

    mVertextList.append(vb31);
    mVertextList.append(vb32);
    mVertextList.append(vb33);
    mVertextList.append(vb34);
    mVertextList.append(vb35);
    mVertextList.append(vb36);

}

