#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "Object.h"
class Triangle : public Object
{
public:
    static int InstanceCount;
private:
    Point *_A, *_B, *_C;
public:
    Point A();
    Point B();
    Point C();
    bool setA(const Point* Other);
    bool setB(const Point* Other);
    bool setC(const Point* Other);
public:
    Triangle();
    Triangle(const Point& A, const Point& B, const Point& C);
    Triangle(const Triangle* Other);
    ~Triangle();
public:
    string toString();
    float CalcSquare();
    float CalcCV();
public:
    static bool testTriangle(const Point* A, const Point* B, const Point* C);
};
#endif