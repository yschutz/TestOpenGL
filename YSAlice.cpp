#include <QDebug>
#include <QImage>
#include <QList>

#include "YSAlice.h"
#include "YSAnnulus.h"
#include "YSTube.h"

//=====================================================================================
YSAlice::YSAlice(QObject *parent) : QObject(parent)
{
    // decfault ctor: defines the shapes making ALICE

    setObjectName("ALICE");
    Create();
    if (mElements.isEmpty()) {
        qDebug() <<  Q_FUNC_INFO << ": ALICE elements have not been created";
        exit(1);
    }
}

//=====================================================================================
YSAlice::~YSAlice()
{
    // dtor
}

//=====================================================================================
void YSAlice::Create()
{
    // Create all elements of ALICE

    CreateL3();

    for(int index = 0; index < mElements.size(); index++)
        qDebug() << Q_FUNC_INFO<< mElements.at(index)->objectName();

}

//=====================================================================================
void YSAlice::CreateL3()
{
    // create the L3 magnet

    const double kInnerRadius =   5.930; //meters
    const double kOuterRadius =   7.900; //meters
    const double kLength      =  Length(); //meters
    const int    kSides       =   8;      //it's an octogone
    const double kRotate      = 180. / kSides;

    YSAnnulus *l3B = new YSAnnulus(kOuterRadius, kInnerRadius, kSides, kRotate);       // back of L3
    l3B->setObjectName(QString("L3B"));
    mElements.append(l3B);
    YSAnnulus *l3F = new YSAnnulus(kOuterRadius, kInnerRadius, kSides, kRotate);       // front of L3
    l3F->setObjectName(QString("L3F"));
    mElements.append(l3F);
    YSTube *l3Body = new YSTube(kOuterRadius, kInnerRadius, kSides, kLength, kRotate); // the body of L3
    l3Body->setObjectName(QString("L3Body"));
    mElements.append(l3Body);
}

//=====================================================================================
//void YSAlice::Draw()
//{
//    // draw ALICE (called by paintGL)

//    // the L3 magnet

//    YSTube *body    = dynamic_cast<YSTube*>(*std::find_if(mElements.begin(), mElements.end(), [] (YSShape* s) {return s->objectName() == "L3Body";}));
//    YSAnnulus *back = dynamic_cast<YSAnnulus*>(*std::find_if(mElements.begin(), mElements.end(), [] (YSShape* s) {return s->objectName() == "L3BF";}));
//    body->Draw();
//    glTranslated(0.0, 0.0, -body->Length() / 2.0);
//    back->Draw();
//    glTranslated(0.0, 0.0,  body->Length());
//    back->Draw();

//}

//=====================================================================================
void YSAlice::Init()
{
    // add the texture
    YSTube *body     = dynamic_cast<YSTube*>(*std::find_if(mElements.begin(), mElements.end(), [] (YSShape* s) {return s->objectName() == "L3Body";}));
    YSAnnulus *back  = dynamic_cast<YSAnnulus*>(*std::find_if(mElements.begin(), mElements.end(), [] (YSShape* s) {return s->objectName() == "L3B";}));
    YSAnnulus *front = dynamic_cast<YSAnnulus*>(*std::find_if(mElements.begin(), mElements.end(), [] (YSShape* s) {return s->objectName() == "L3F";}));
    body->SetTextureImageName(QString(":/textures/images/IronRed.jpg"));
    back->SetTextureImageName(QString(":/textures/images/IronRed.jpg"));
//    back->Translate(0.0, 0.0, -body->Length() / 2.0);
    front->SetTextureImageName(QString(":/textures/images/IronRed.jpg"));
//    front->Translate(0.0, 0.0, body->Length() / 2.0);
}

