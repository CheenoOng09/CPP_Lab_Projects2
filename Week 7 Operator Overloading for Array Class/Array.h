#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);
    friend Array operator+(const int &left, const Array &right);
public:
    Array(int = 10); // default constructor
    Array(const Array &);
    ~Array();
    int getSize() const;

    const Array &operator=(const Array &);
    bool operator==(const Array &) const;
    bool operator!=(const Array &right) const
    {
        return !(*this == right);
    }
    int &operator[](int);
    int operator[](int) const;

    Array operator+(const Array &right);
    void operator<<(const int &right);
    int operator+();
    Array operator+(const int &right);
private:
    int size;
    int *ptr;
};

#endif
