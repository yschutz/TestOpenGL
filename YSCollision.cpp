#include <QDebug>
#include <QImage>
#include <QTime>
#include "YSCollision.h"

//=====================================================================================
YSCollision::YSCollision(QObject *parent) : QObject(parent), mQuarks(0)
{
    // default ctor
    setObjectName("A collision");

    // add 3 quarks to the particle list

    QTime now = QTime::currentTime();
    qsrand(now.msec());
    qrand();
//    AddParticles(YSParticle::HADRON, 1);
    AddParticles(YSParticle::QUARK,  1);

    for (int index = 0; index < mFSParticles.size(); index++)
        mFSParticles.at(index)->Print();
}



//=====================================================================================
YSCollision::~YSCollision()
{
    // dtor

//    qDeleteAll(mFSParticles.begin(), mFSParticles.end());
//    mFSParticles.clear();
}

//=====================================================================================
////void YSCollision::Draw(qreal xcent, qreal ycent, qreal zcent) const
//{
//    // draw the collision

//    static qreal time = 0;

//    const char *textureName;
//    for(int index = 0; index < mFSParticles.size(); index++) {
//        YSParticle * part = mFSParticles.at(index);
//        switch (part->Color()) {
//        case YSParticle::RED:
//            textureName = ":/textures/images/RedQuark.png";
//            break;
//        case YSParticle::BLUE:
//            textureName = ":/textures/images/BlueQuark.png";
//            break;
//        case YSParticle::GREEN:
//            textureName = ":/textures/images/GreenQuark.png";
//            break;
//        case YSParticle::WHITE:
//            textureName = ":/textures/images/WhiteHadron.png";
//            break;
//        default:
//            break;
//        }
//        part->SetTexture(QImage(textureName));
//        part->Move(time);
//        glLoadIdentity();
//        glTranslatef(xcent + part->PosX(), ycent + part->PosY(), zcent + part->PosZ());
//        part->Draw();
//    }
////    time += 0.01;
//}

//=====================================================================================
void YSCollision::AddHadrons(int nHadrons)
{

    // add hadrons to the final state particles list

    for (int num = 0; num < nHadrons; num++) {
        YSParticle *part = new YSParticle(YSParticle::HADRON, this);
        part->SetColor(YSParticle::WHITE);
//        part->SetTexture(QImage(":/textures/images/WhiteHadron.png"));
        part->SetVelocity(0.6, 0.9);
        mFSParticles.append(part);
        mHadrons++;
    }
}

//=====================================================================================
void YSCollision::AddParticles(YSParticle::PARTICLETYPE type, int howMany)
{
    // adds the final state particles to the collisions
    switch (type) {
    case YSParticle::QUARK:
        AddQuarks(howMany);
        break;
    case YSParticle::HADRON:
        AddHadrons(howMany);
        break;
    default:
        break;
    }
}

//=====================================================================================
void YSCollision::AddQuarks(int nQuarks)
{
    // add a quark to the final state particles list
    // select randomly the color

    const char *textureName;
    for (int num = 0; num < nQuarks; num++) {
        YSParticle *part = new YSParticle(YSParticle::QUARK, this);
        int color = qrand() % ((YSParticle::GREEN + 1) - YSParticle::RED) + YSParticle::RED;
        switch (color) {
        case YSParticle::RED:
            part->SetColor(YSParticle::RED);
            textureName = ":/textures/images/RedQuark.png";            
            break;
        case YSParticle::BLUE:
            part->SetColor(YSParticle::BLUE);
            textureName = ":/textures/images/BlueQuark.png";            
            break;
        case YSParticle::GREEN:
            part->SetColor(YSParticle::GREEN);
            textureName = ":/textures/images/GreenQuark.png";
            break;
        default:
            break;
        }
        part->SetVelocity(0.6, 0.9);
        mFSParticles.append(part);
        mQuarks++;
    }
}
