#include "Hugeint.h"
#include <cctype>
#include <iostream>

using namespace std;


HugeInt::HugeInt(long value)
{
    // Get number of digits
    long temp = value;
    do
    {
        temp /= 10;
        ++digits;
    } while (temp != 0);

    integer = new short[digits];

    // Initialize to zero
    for (int i = 0; i < digits; ++i)
    {
        integer[i] = 0;
    }

    // Place digit into array
    for (int i = digits - 1; value != 0 && i >= 0; --i)
    {
        integer[i] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const string &number)
{
    // Get number of digits
    digits = number.size();

    integer = new short[digits];

    // Initialize to zero
    for (int i = 0; i < digits; ++i)
    {
        integer[i] = 0;
    }

    // Place digit into array
    for (int i = 0; i < digits; ++i)
    {
        if (isdigit(number[i]))
        {
            integer[i] = number[i] - '0';
        }
    }

    removeZero();
}

HugeInt::HugeInt(const HugeInt &op1)
{
    digits = op1.digits;
    integer = new short[digits];
    for (int i = 0; i < digits; ++i)
    {
        integer[i] = op1.integer[i];
    }
}

void HugeInt::operator=(const HugeInt &op1)
{
    delete[] integer;
    digits = op1.digits;
    integer = new short[digits];
    for (int i = 0; i < digits; ++i)
    {
        integer[i] = op1.integer[i];
    }
}

HugeInt::~HugeInt()
{
    delete[] integer;
}

void HugeInt::resize(const int &n)
{
    if (n == 0 || (-1 * n) == digits)
    {
        return;
    }
    HugeInt temp(*this);
    int oldDigits = digits;
    delete[] integer;
    digits += n;
    integer = new short[digits];

    // Initialize array to zero
    for (int i = 0; i < digits; ++i)
    {
        integer[i] = 0;
    }

    // Copy old array to new
    if (n > 0)
    {
        for (int i = n, j = 0; i < digits; ++i, ++j)
        {
            integer[i] = temp.integer[j];
        }
    }
    else
    {
        for (int i = 0, j = -1 * n; i < digits; ++i, ++j)
        {
            integer[i] = temp.integer[j];
        }
    }
}

void HugeInt::removeZero()
{
    int n = 0;
    while (integer[n] == 0 && n < digits)
    {
        ++n;
    }
    resize(-1 * n);
}

HugeInt HugeInt::operator+(const HugeInt &op2) const
{
    HugeInt temp;
    int carry = 0;
    int index = 0;
    if (digits > op2.digits)
    {
        // Extra 1 digit
        temp.resize(digits);

        index = digits - 1;
        for (int j = op2.digits - 1; j >= 0; --index, --j)
        {
            temp.integer[index + 1] = integer[index] + op2.integer[j] + carry;

            if (temp.integer[index + 1] > 9)
            {
                temp.integer[index + 1] %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        for (; index >= 0; --index)
        {
            temp.integer[index + 1] = integer[index] + carry;

            if (temp.integer[index + 1] > 9)
            {
                temp.integer[index + 1] %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
    }
    else
    {
        // Extra 1 digit
        temp.resize(op2.digits);

        index = op2.digits - 1;
        for (int j = digits - 1; j >= 0; --index, --j)
        {
            temp.integer[index + 1] = op2.integer[index] + integer[j] + carry;

            if (temp.integer[index + 1] > 9)
            {
                temp.integer[index + 1] %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }

        if (digits < op2.digits)
        {
            for (; index >= 0; --index)
            {
                temp.integer[index + 1] = op2.integer[index] + carry;

                if (temp.integer[index + 1] > 9)
                {
                    temp.integer[index + 1] %= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
            }
        }

    }
    // Most significant digit
    temp.integer[0] += carry;
    temp.removeZero();
    return temp;
}

bool HugeInt::operator<=(const HugeInt &op2) const
{
    if (digits < op2.digits)
    {
        return true;
    }
    else if (digits > op2.digits)
    {
        return false;
    }

    // Digits same
    for (int i = 0; i < digits; ++i)
    {
        if (integer[i] < op2.integer[i])
        {
            return true;
        }
        else if (integer[i] > op2.integer[i])
        {
            return false;
        }
    }

    // All digits same
    return true;
}

int HugeInt::getNumDigits() const
{
    return digits;
}

HugeInt HugeInt::operator++()
{
    *this = *this + 1;
    return *this;
}

HugeInt HugeInt::operator++(int)
{
    HugeInt temp = *this;
    *this = *this + 1;
    return temp;
}

std::ostream &operator<<(ostream &output, const HugeInt &num)
{
    int i;

    for (i = 0; (num.integer[i] == 0) && (i <= num.digits); ++i)
    {
        ;
    }

    if (i == num.digits)
    {
        output << 0;
    }
    else
    {
        for (; i < num.digits; ++i)
        {
            output << num.integer[i];
        }
    }
    output << '(' << num.digits << ')';

    return output;
}

HugeInt HugeInt::operator+(int op2) const
{
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const string &op2) const
{
    return *this + HugeInt(op2);
}

HugeInt operator+(int op1, const HugeInt &op2)
{
    return op2 + op1;
}

HugeInt operator+(const string &op1, const HugeInt &op2)
{
    return op2 + op1;
}

void HugeInt::operator+=(int op2)
{
    *this = *this + op2;
}

void HugeInt::operator+=(const HugeInt &op2)
{
    *this = *this + op2;
}

bool HugeInt::operator<=(const int &op2) const
{
    return *this <= HugeInt(op2);
}

bool HugeInt::operator<=(const string &op2) const
{
    return *this <= HugeInt(op2);
}

bool operator<=(const int &op1, const HugeInt &op2)
{
    return HugeInt(op1) <= HugeInt(op2);
}

bool operator<=(const string &op1, const HugeInt &op2)
{
    return HugeInt(op1) <= HugeInt(op2);
}

void HugeInt::operator=(const int &op2)
{
    *this = HugeInt(op2);
}

void HugeInt::operator=(const string &op2)
{
    *this = HugeInt(op2);
}

