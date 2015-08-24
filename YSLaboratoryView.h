#ifndef YSLABORATORYVIEW_H
#define YSLABORATORYVIEW_H

#include "YSGLWidget.h"

class YSAlice;
class YSCollision;

class YSLaboratoryView : public YSGLWidget
{
    Q_OBJECT
public:
    explicit YSLaboratoryView();
    ~YSLaboratoryView() {;}

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    YSAlice      *mAlice; // the alice detector
    YSCollision  *mCollision; // the collision
};

#endif // YSLABORATORYVIEW_H
