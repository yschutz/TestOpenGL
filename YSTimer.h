#ifndef YSTIMER_H
#define YSTIMER_H

#include <QObject>

class YSTimer : public QObject
{
    Q_OBJECT
public:
    explicit YSTimer(QObject *parent = 0);
    ~YSTimer();

    void Init() ;

private:
    qint64        mFrequency;
    float         mResolution;
    unsigned long mStart;
    unsigned long mElapsed;
    bool          mPerformance;
    qint64        mPerformanceStart;
    qint64        mPerformanceElapsed;
};

#endif // YSTIMER_H
