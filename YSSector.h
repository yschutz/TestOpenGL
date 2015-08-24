#ifndef YSSECTOR_H
#define YSSECTOR_H

#include <QObject>

#include "YSTriangle.h"

class YSSector : public QObject
{
    Q_OBJECT
public:
    explicit YSSector(QObject *parent = 0);
    YSSector(unsigned int number);
    ~YSSector();

   int         NumberOfTriangles() const { return mNumberOfTriangles; }
   YSTriangle* Triangle(int index) const { return &mTriangles[index]; }
   void        Print() const;
   void        SetTriangles(int num)  { mNumberOfTriangles = num; }


private:
    unsigned int mNumberOfTriangles;
    YSTriangle   *mTriangles;
};

#endif // YSSECTOR_H
