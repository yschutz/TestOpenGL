#ifndef YSCOLLISION_H
#define YSCOLLISION_H

#include <QObject>

#include "YSParticle.h"

class YSCollision : public QObject
{
    Q_OBJECT
public:
   explicit YSCollision(QObject *parent = 0);
   ~YSCollision();

//    void Draw(qreal xcent, qreal ycent, qreal zcent) const;

    QList<YSParticle*> FSParticles() const { return mFSParticles; }
    
private:

    void AddHadrons(int nHadrons);
    void AddParticles(YSParticle::PARTICLETYPE type, int howMany);
    void AddQuarks(int howMany);


    QList<YSParticle*> mFSParticles; // final state particles
    int                mHadrons;     // number of hadrons
    int                mQuarks;      // number of quarks
};

#endif // YSCOLLISION_H
