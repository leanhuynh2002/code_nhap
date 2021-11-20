#include "Point.h"
#include <cmath>
#include <sstream>
using namespace std;

const float Point::X() const
{
    return this->_x;
}

const float Point::Y() const
{
    return this->_y;
}

void Point::SetX(const float value)
{
    this->_x = value;
}

void Point::SetY(const float value)
{
    this->_y = value;
}

Point::Point()
{
    this->_x = this->_y = 0;
    ++this->InstanceCount;
}

Point::Point(const float value1, const float value2)
{
    this->_x = value1;
    this->_y = value2;
    ++this->InstanceCount;
}

Point::Point(const Point& Other)
{
    this->_x = Other._x;
    this->_y = Other._y;
    ++this->InstanceCount;
}

Point::~Point() {}

float Point::CalcDistanceTo(const Point* Other) const
{
    return sqrt(pow(this->_x - Other->_x, 2) + pow(this->_y - Other->_y, 2));
}

Point* Point::operator = (const Point* Other)
{
    this->_x = Other->_x;
    this->_y = Other->_y;
    return this;
}

string Point::toString()
{
    stringstream writer;
    writer << "(" << this->_x << "," << this->_y << ")";
    return writer.str();
}

float Point::CalcDistanceTo(const Point* Other1, const Point* Other2)
{
    return Other1->CalcDistanceTo(Other2);
}