#include <QDebug>
#include "YSSector.h"

//=====================================================================================
YSSector::YSSector(QObject *parent) : QObject(parent)
{

}

//=====================================================================================
YSSector::YSSector(unsigned int number) :
    mNumberOfTriangles(number)
{
    mTriangles = new YSTriangle[mNumberOfTriangles];
}

//=====================================================================================
YSSector::~YSSector()
{
    delete [] mTriangles;
}

//=====================================================================================
void YSSector::Print() const
{
    // Print

    for (unsigned int index = 0; index < mNumberOfTriangles; index++) {
        qDebug() << "Triang 1";
//        mTriangles[index].Print();
    }
}

