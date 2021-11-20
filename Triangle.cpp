#include "Triangle.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Point Triangle::A()
{
    return *(this->_A);
}

Point Triangle::B()
{
    return *(this->_B);
}

Point Triangle::C()
{
    return *(this->_C);
}

bool Triangle::setA(const Point* Other)
{
    if (Triangle::testTriangle(this->_B, this->_C, Other)) {
        *(this->_A) = *Other;
        ++this->InstanceCount;

        return true;
    }

    return false;
}

bool Triangle::setB(const Point* Other)
{
    if (Triangle::testTriangle(this->_A, this->_C, Other)) {
        *(this->_B) = *Other;
        ++this->InstanceCount;

        return true;
    }

    return false;
}

bool Triangle::setC(const Point* Other)
{
    if (Triangle::testTriangle(this->_A, this->_B, Other)) {
        *(this->_C) = *Other;
        ++this->InstanceCount; 
     
        return true;
    }
    
    return false;
}

Triangle::Triangle()
{
    this->_A = new Point{0, 1};
    this->_B = new Point{1, 0};
    this->_C = new Point{0, 0};

    ++this->InstanceCount;
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C)
{
    if (this->testTriangle(&A, &B, &C)) {
        this->_A = new Point(A);
        this->_B = new Point(B);
        this->_C = new Point(C);
    }
    else {
        this->_A = new Point{0, 1};
        this->_B = new Point{1, 0};
        this->_C = new Point{0, 0};
    }

    ++this->InstanceCount;
}

Triangle::Triangle(const Triangle* Other)
{
    this->_A = new Point (*(Other->_A));
    this->_B = new Point (*(Other->_A));
    this->_C = new Point (*(Other->_A));

    ++this->InstanceCount;
}

Triangle::~Triangle()
{
    if (this->_A != NULL)
        delete this->_A;
    if (this->_B != NULL)
        delete this->_B;
    if (this->_C != NULL)
        delete this->_C;
}

string Triangle::toString()
{
    stringstream writer;
    writer << "{" << this->_A->toString() << "," << this->_B->toString() << "," << this->_C->toString() << "}";
    return writer.str();
}

float Triangle::CalcCV()
{
    float AB = this->_A->CalcDistanceTo(this->_B);
    float AC = this->_A->CalcDistanceTo(this->_B);
    float BC = this->_B->CalcDistanceTo(this->_C);

    return AB + AC + BC;
}

float Triangle::CalcSquare()
{
    float AB = this->_A->CalcDistanceTo(this->_B);
    float AC = this->_A->CalcDistanceTo(this->_B);
    float BC = this->_B->CalcDistanceTo(this->_C);
    float p = (AB + AC + BC) / 2;

    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

bool Triangle::testTriangle(const Point* A, const Point* B, const Point* C)
{
    float AB = A->CalcDistanceTo(B);
    float AC = A->CalcDistanceTo(C);
    float BC = B->CalcDistanceTo(C);

    if (AB + AC > BC && AB + BC > AC && BC + AC > AB)
        return true;
    else
        return false;
}