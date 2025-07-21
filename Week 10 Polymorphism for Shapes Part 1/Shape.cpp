#include "Shape.h"
#include <iostream>
#include <cmath>


using namespace std;

Triangle::Triangle(const Pt &pt1, const Pt &pt2, const Pt &pt3)
    : a(pt1),
      b(pt2),
      c(pt3)
{
}

double Triangle::area() const
{
    double x1 = a.getX();
    double y1 = a.getY();
    double x2 = b.getX();
    double y2 = b.getY();
    double x3 = c.getX();
    double y3 = c.getY();

    return 0.5 * (((x1 - x2)*(y1 - y3)) - ((x1 - x3)*(y1 - y2)));
}

bool Triangle::inside(const Pt &point) const
{
    double minimumX;
    double maximumX;
    double minimumY;
    double maximumY;

    // FINDING MINIMUM & MAXIMUM X
    if(a.getX() > b.getX() && a.getX() > c.getX()){
        maximumX = a.getX();
        if(b.getX() < c.getX()){
            minimumX = b.getX();
        }
        else
            minimumX = c.getX();
    }
    else if(b.getX() > a.getX() && b.getX() > c.getX()){
        maximumX = b.getX();
        if(a.getX() < c.getX()){
            minimumX = a.getX();
        }
        else
            minimumX = c.getX();
    }
    else if(c.getX() > a.getX() && c.getX() > b.getX()){
        maximumX = c.getX();
        if(b.getX() < a.getX()){
            minimumX = b.getX();
        }
        else
            minimumX = a.getX();
    }
    // FINDING MINIMUM & MAXIMUM Y
    if(a.getY() > b.getY() && a.getY() > c.getY()){
        maximumY = a.getY();
        if(b.getY() < c.getY()){
            minimumY = b.getY();
        }
        else
            minimumY = c.getY();
    }
    else if(b.getY() > a.getY() && b.getY() > c.getY()){
        maximumY = b.getY();
        if(a.getY() < c.getY()){
            minimumY = a.getY();
        }
        else
            minimumY = c.getY();
    }
    else if(c.getY() > a.getY() && c.getY() > b.getY()){
        maximumY = c.getY();
        if(b.getY() < a.getY()){
            minimumY = b.getY();
        }
        else
            minimumY = a.getY();
    }

    if(point.getX() >= minimumX && point.getX() <= maximumX){
        if(point.getY() >= minimumY && point.getY() <= maximumY){
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

double Triangle::perimeter() const
{
    double x1 = a.getX();
    double y1 = a.getY();
    double x2 = b.getX();
    double y2 = b.getY();
    double x3 = c.getX();
    double y3 = c.getY();

    double lineA = sqrt( pow((x1 - x2),2) + pow((y1 - y2),2) );  // XY
    double lineB = sqrt( pow((x2 - x3),2) + pow((y2 - y3),2) );  // YZ
    double lineC = sqrt( pow((x3 - x1),2) + pow((y3 - y1),2) ); // ZX

    if (degenerate())
    {
        if (lineA > lineB)
        {
            if (lineA > lineC)
            {
                return lineA;
            }
        }
        else
        {
            if (lineB > lineC)
            {
                return lineB;
            }
        }
        return lineC;
    }
    return lineA + lineB + lineC;
}

bool Triangle::degenerate() const
{
    if (area() == 0)
    {
        return true;
    }
    return false;
}

void Triangle::print() const
{
    cout << endl << "Triangle: (" << a.getX() << ", " << a.getY() << ") (" << b.getX() << ", " << b.getY() << ") (" << c.getX() << ", " << c.getY() << ")" << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    if (degenerate())
    {
        cout << "This shape is degenerated." << endl;
    }
}

Rectangle::Rectangle(const Pt &pt1, const Pt &pt2)
    :a(pt1), b(pt2)
{
    length = abs(a.getX() - b.getX());
    width = abs(a.getY() - b.getY());
}

double Rectangle::area() const
{
    return length * width;
}

bool Rectangle::inside(const Pt &point) const
{
    double minimumX;
    double maximumX;
    double minimumY;
    double maximumY;
    if(a.getX() > b.getX())
    {
        maximumX = a.getX();
        minimumX = b.getX();
    }
    else if(b.getX() > a.getX())
    {
        maximumX = b.getX();
        minimumX = a.getX();
    }
    if(a.getY() > b.getY())
    {
        maximumY = a.getY();
        minimumY = b.getY();
    }
    else if(b.getY() > a.getY())
    {
        maximumY = b.getY();
        minimumY = a.getY();
    }

    if(point.getX() <= maximumX && point.getX() >= minimumX)
    {
        if(point.getY() <= maximumY && point.getY() >= minimumY)
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

double Rectangle::perimeter() const
{
    return (2 * (length + width));
}

bool Rectangle::degenerate() const
{
    if(area() == 0)
    {
        return true;
    }
    return false;
}

void Rectangle::print() const
{
    cout << endl << "Rectangle: (" << a.getX() << ", " << a.getY() << ") (" << b.getX() << ", " << b.getY() << ")" << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    if (degenerate())
    {
        cout << "This shape is degenerated." << endl;
    }
}

Circle::Circle(const Pt &point, const double &radiusA)
    :center(point), radius(radiusA)
{
}

double Circle::getPi() const
{
    return piii;
}

double Circle::area() const
{
    return (getPi() * (pow(radius,2)));
}

bool Circle::inside(const Pt &point)const
{
    double x = point.getX();
    double y = point.getY();
    if ((pow(x - center.getX(), 2) + pow(y - center.getY(), 2)) < radius * radius)
    {
        return true;
    }
    return false;
}

double Circle::perimeter()const
{
    return 2 * getPi() * radius;
}

bool Circle::degenerate() const
{
    if(area() == 0)
    {
        return true;
    }
    return false;
}

void Circle::print() const
{
    cout << endl << "Circle: " << radius << " (" << center.getX() << ", " << center.getY() << ")" << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    if (degenerate())
    {
        cout << "This shape is degenerated." << endl;
    }
}
