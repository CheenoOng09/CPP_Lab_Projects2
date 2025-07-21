#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Pt
{
private:
    double x;
    double y;
public:
    Pt(const double &x1 = 0, const double &y1 = 0)
        :x(x1), y(y1)
    {
    }
    ~Pt(){}
    double getX() const {return x;}
    double getY() const {return y;}
    void print()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class Line ////////////////////////////////////////////////////////////////////////
{
private:
    Pt x;
    Pt y;
public:
    Line(const double &x1 = 0, const double &y1 = 0)
        :x(x1), y(y1)
    {
    }
    ~Line(){}
    double getx() const {return x;}
    double gety() const {return y;}
};

class Shape
{
public:
    Shape() {}
    virtual double area() const = 0;
    virtual bool inside(const Pt &) const = 0;
    virtual double perimeter() const = 0;
    virtual bool degenerate() const = 0;
    virtual void print() const = 0;
    virtual bool intersection(const Shape*) const = 0; //////////////////////////////////////////////
};
////////////////////////////////

class Triangle : public Shape
{
private:
    Pt a;
    Pt b;
    Pt c;
public:
    Triangle(const Pt & = 0.0, const Pt & = 0.0, const Pt & = 0.0);
    ~Triangle(){};
    double area() const;
    bool inside(const Pt& ) const;
    double perimeter() const;
    bool degenerate() const;
    void print() const;
    bool intersection(const Shape*) const; /////////////////////////////////////////

};

class Rectangle : public Shape
{
private:
    Pt a;
    Pt b;
    double length;
    double width;
public:
    Rectangle(const Pt & = 0.0, const Pt & = 0.0);
    ~Rectangle() {};
    double area() const;
    bool inside( const Pt& ) const;
    double perimeter() const;
    bool degenerate() const;
    void print() const;
    bool intersection(const Shape*) const; //////////////////////////////////////////
};

class Circle : public Shape
{
private:
    Pt center;
    double radius;
    const long double piii = 3.14159265358979323846;
public:
    Circle(const Pt &, const double &);
    ~Circle(){};
    double area() const;
    bool inside( const Pt& ) const;
    double perimeter() const;
    bool degenerate() const;
    void print() const;
    double getPi() const;
    bool intersection(const Shape*) const; ///////////////////////////////////////

};

#endif // SHAPE_H

