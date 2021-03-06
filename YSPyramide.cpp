#include "YSPyramide.h"
#include "YSVertex.h"
#include "YSTriangle.h"

//=====================================================================================
YSPyramide::YSPyramide() : YSShape("Pyramide")
{
    //ctor
}

//=====================================================================================
YSPyramide::YSPyramide(double b, double h, double degrees, QObject *parent) :
    YSShape("Pyramide", degrees, parent), mB(b), mH(h)
{
    //ctor
    Create();
}

//=====================================================================================
void YSPyramide::Create()
{
    // calculate the vertices

    YSTriangle isoc(mB, mH, YSTriangle::ISOC);
    YSVertex *vt1 = isoc.Vertex(0);
    YSVertex *vt2 = isoc.Vertex(1);
    YSVertex *vt3 = isoc.Vertex(2);

    //front
    YSVertex *vp1 = new YSVertex(vt1->X(), vt1->Y(), vt1->Z() + 1, vt1->U(), vt1->V());
    YSVertex *vp2 = new YSVertex(vt2->X(), vt2->Y(), vt2->Z() + 1, vt2->U(), vt2->V());
    YSVertex *vp3 = new YSVertex(vt3->X(), vt3->Y(), vt3->Z(),     vt3->U(), vt3->V());
    mVertextList.append(vp1);
    mVertextList.append(vp2);
    mVertextList.append(vp3);
    vp1->Print(); vp2->Print();vp3->Print();
    //right
    YSVertex *vp4 = new YSVertex(vp2->X(), vp2->Y(), vp2->Z(),     vt1->U(), vt1->V());
    YSVertex *vp5 = new YSVertex(vp4->X(), vp4->Y(), vp4->Z() - 2, vt2->U(), vt2->V());
    YSVertex *vp6 = new YSVertex(vp3->X(), vp3->Y(), vp3->Z(),     vt3->U(), vt3->V());
    mVertextList.append(vp4);
    mVertextList.append(vp5);
    mVertextList.append(vp6);
    vp4->Print(); vp5->Print();vp6->Print();
    //back
    YSVertex *vp7 = new YSVertex(vp5->X(), vp5->Y(), vp5->Z(), vt1->U(), vt1->V());
    YSVertex *vp8 = new YSVertex(vp1->X(), vp7->Y(), vp7->Z(), vt2->U(), vt2->V());
    YSVertex *vp9 = new YSVertex(vp3->X(), vp3->Y(), vp3->Z(), vt3->U(), vt3->V());
    mVertextList.append(vp7);
    mVertextList.append(vp8);
    mVertextList.append(vp9);
    //left
    YSVertex *vp10 = new YSVertex(vp8->X(), vp8->Y(), vp8->Z(), vt1->U(), vt1->V());
    YSVertex *vp11 = new YSVertex(vp1->X(), vp1->Y(), vp1->Z(), vt2->U(), vt2->V());
    YSVertex *vp12 = new YSVertex(vp3->X(), vp3->Y(), vp3->Z(), vt3->U(), vt3->V());
    mVertextList.append(vp10);
    mVertextList.append(vp11);
    mVertextList.append(vp12);
    //bottom
    YSVertex *vp13 = new YSVertex(vp1->X(), vp1->Y(), vp1->Z(), vt1->U(), vt1->V());
    YSVertex *vp14 = new YSVertex(vp2->X(), vp2->Y(), vp2->Z(), vt2->U(), vt2->V());
    YSVertex *vp15 = new YSVertex(vp8->X(), vp8->Y(), vp8->Z(), vt3->U(), vt3->V());
    YSVertex *vp16 = new YSVertex(vp8->X(), vp8->Y(), vp8->Z(), vt1->U(), vt1->V());
    YSVertex *vp17 = new YSVertex(vp2->X(), vp2->Y(), vp2->Z(), vt2->U(), vt2->V());
    YSVertex *vp18 = new YSVertex(vp5->X(), vp5->Y(), vp5->Z(), vt3->U(), vt3->V());
    mVertextList.append(vp13);
    mVertextList.append(vp14);
    mVertextList.append(vp15);
    mVertextList.append(vp16);
    mVertextList.append(vp17);
    mVertextList.append(vp18);
}

