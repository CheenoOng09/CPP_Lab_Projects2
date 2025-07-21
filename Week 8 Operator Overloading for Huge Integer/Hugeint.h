#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>

using namespace std;

class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);

    friend HugeInt operator+(int, const HugeInt &);
    friend HugeInt operator+(const string & , const HugeInt &);
    friend bool operator<=(const int &, const HugeInt &);
    friend bool operator<=(const string &, const HugeInt &);
public:
    HugeInt(long = 0); // default constructor
    HugeInt(const string &); // string conversion
    HugeInt(const HugeInt &); // Copy Constructor

    HugeInt operator+(const HugeInt &) const; // addition operation for 2 Hugeint obj
    HugeInt operator+(int) const; // addition for HugeInt + int
    HugeInt operator+(const string &op2) const; // addition for HugeInt + String (digit type string)

    // added
    int getNumDigits() const;

    void operator+=(int); // hugeint += int
    void operator+=(const HugeInt &); // hugeint += hugeint

    HugeInt operator++(); // hugeint++
    HugeInt operator++(int); //

    bool operator<=(const HugeInt &) const;
    bool operator<=(const int &) const;
    bool operator<=(const string &) const;

    void operator=(const HugeInt &);
    void operator=(const int &);
    void operator=(const string &);

    ~HugeInt();
private:
    short *integer;
    int digits = 0;

    // Added
    void resize(const int &);
    void removeZero();
};
#endif // HUGEINT_H

