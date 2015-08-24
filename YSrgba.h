#ifndef YSRGBA_H
#define YSRGBA_H

class YSrgba
{
public:
    explicit YSrgba();
    YSrgba(double r, double g, double b, double a = 0.0) { mR = r; mG = g; mB = b; mA = a; }
    ~YSrgba();

    void Set(double r, double g, double b, double a = 0.0) { mR = r; mG = g; mB = b; mA = a; }
    double R() const { return mR; }
    double G() const { return mG; }
    double B() const { return mB; }
    double A() const { return mA; }

private:
    double mR; // red
    double mG; // green
    double mB; // blue
    double mA; // alpha
};

#endif // YSRGBA_H
