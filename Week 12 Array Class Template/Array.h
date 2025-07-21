#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
class Array
{
    template <typename U>
    friend ostream &operator<<(ostream &, const Array<U> &);
    template <typename U>
    friend istream &operator>>(istream &, Array<U> &);

public:
    Array(int arraySize = 10)
    {
        size = (arraySize > 0 ? arraySize : 10);
        ptr = new T[size];
    }
    Array(const Array<T> &arrayToCopy, int sizeIncr = 0)
        : size(arrayToCopy.size)
    {
        size += sizeIncr;
        ptr = new T[size];

        if (sizeIncr >= 0)
        {
            for (int i = 0; i < arrayToCopy.size; ++i)
            {
                ptr[i] = arrayToCopy.ptr[i];
            }
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                ptr[i] = arrayToCopy.ptr[i];
            }
        }
    }
    Array<T> &operator=(const Array<T> &right)
    {
        if (&right != this)
        {
            if (size != right.size)
            {
                delete[] ptr;
                size = right.size;
                ptr = new T[size];
            }

            for (int i = 0; i < size; ++i)
            {
                ptr[i] = right.ptr[i];
            }
        }
        return *this;
    }
    ~Array()
    {
        delete[] ptr;
    }

    int getSize() const
    {
        return size;
    }

    bool operator==(const Array<T> &right) const
    {
        if (typeid(T) != typeid(ptr[0]))
        {
            return false;
        }
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

    bool operator!=(const Array<T> &right) const
    {
        return !(*this == right);
    }

    T &operator[](int subscript)
    {
        if (subscript < 0 || subscript >= size)
        {
            cerr << "\nError: subcript " << subscript << " out of range\n";
            exit(1);
        }
        return ptr[subscript];
    }

    void insertA(T element, int index)
    {
        if (index > size || index < 0)
        {
            cout << "** Error: insertion fails, subscript " << index << " is out of range.\n";
            return;
        }
        Array<T> temp(*this, 1);

        for (int i = temp.size - 1; i > index; --i)
        {
            temp[i] = temp[i - 1];
        }
        temp[index] = element;
        *this = temp;
    }

    void deleteA(int index)
    {
        if (index > size || index < 0)
        {
            cout << "** Error: deletion fails, subscript " << index << " is out of range.\n";
            return;
        }
        for (int i = index; i < size - 1; ++i)
        {
            ptr[i] = ptr[i + 1];
        }
        Array<T> temp(*this, -1);
        *this = temp;
    }

private:
    int size;
    T *ptr;
};

template <typename U>
ostream &operator<<(ostream &left, const Array<U> &right)
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

template <typename U>
istream &operator>>(istream &left, Array<U> &right)
{
    for (int i = 0; i < right.size; ++i)
    {
        left >> right.ptr[i];
    }
    return left;
}
