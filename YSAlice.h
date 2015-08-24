#ifndef YSALICE_H
#define YSALICE_H

#include <QObject>

#include "YSShape.h"

class YSShape;

class YSAlice : public QObject
{
    Q_OBJECT
public:
    explicit YSAlice(QObject *parent = 0);
    ~YSAlice();

//    void            Draw();
    void            Init();
    double          Length() const { return 14.1; }
    QList<YSShape*> Elements() const { return mElements; }
    
private:
    void Create();
    void CreateL3();

signals:

public slots:

private:
    QList<YSShape*> mElements; // list of YSShape elements needed to build ALICE
};

#endif // YSALICE_H
