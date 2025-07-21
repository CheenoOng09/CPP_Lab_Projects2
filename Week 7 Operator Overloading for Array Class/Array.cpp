#include "Array.h"
#include <iomanip>

using namespace std;

Array::Array(int arraySize) //contructor
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        ptr[i] = 0;
    }
}

Array::Array(const Array &arrayToCopy)
    : size(arrayToCopy.size)
{
    ptr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
    cout << "Call copy constructor!\n";
}

Array::~Array()
{
    delete [] ptr;
}

int Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete [] ptr;
            size = right.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; ++i)
        {
            ptr[i] = right.ptr[i];
        }
    }
    return *this;
}

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
    {
        return false;
    }
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] != right.ptr[i])
        {
            return false;
        }
    }
    return true;
}

int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: subcript " << subscript << " out of range\n";
        exit(1);
    }
    return ptr[subscript];
}

Array operator+(const int &left, const Array &right) // 1+integers1+2 adding the integer value to each element in an array
{
    Array temp(right.size);
    for (int i = 0; i < right.size; ++i)
    {
        temp.ptr[i] = right.ptr[i] + left;
    }
    return temp;
}

Array Array::operator+(const Array &right) // for combining two arrays using + operator
{
    Array temp(this->getSize() + right.getSize());
    int a = -1;
    for (int i = 0; i < this->getSize(); ++i)
    {
        temp.ptr[i] = this->ptr[i]; // 10, 0 / 11, 1 / 12, 2
        a++; // 0, 1, 2
    }
    a++;
    for (int i = a, j = 0; j < right.getSize(); ++i, ++j)
    {
        temp.ptr[i] = right.ptr[j];
    }
    return temp;
}

void Array::operator<<(const int &right) // for shifting the elements to the left
{
    Array temp(size);
    for (int i = 0; i < size; ++i)
    {
        temp[i] = ptr[i];
    }
    int a = 0;
    int b = size;
    for (int i = 0; i < size; ++i)
    {
        a = i - right;
        ptr[(b + (a % b)) % b] = temp[i];
    }
}

int Array::operator+() // finding the sum of all elements in an array
{
    int temp = 0;
    for (int i = 0; i < size; ++i)
    {
        temp += ptr[i];
    }
    return temp;
}

Array Array::operator+(const int &right) // 1+integers1+2 adding the integer value to each element in an array
{
    Array temp(size);
    for (int i = 0; i < size; ++i)
    {
        temp.ptr[i] = ptr[i] + right;
    }
    return temp;
}

ostream &operator<<(ostream &left, const Array &right)
{
    for (int i = 0; i < right.size; ++i)
    {
        if (i % 4 == 0 && i != 0)
        {
            left << '\n';
        }
        left << setw(12) << right.ptr[i];
    }
    left << '\n';
    return left;
}

istream &operator>>(istream &left, Array &right)
{
    for (int i = 0; i < right.size; ++i)
    {
        left >> right.ptr[i];
    }
    return left;
}
