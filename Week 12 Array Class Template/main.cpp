#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Array<int> integers1(7);
    Array<int> integers2;

    cout << "Enter 17 integers: " << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
        << "integers1: \n" << integers1
        << "integers2: \n" << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
    {
        cout << "integers1 and integers2 are not equal" << endl;
    }
    cout << "\n\nAssigning 1001 to integers2[8]" << endl;
    integers2[8] = 1001;
    cout << "integers2:\n" << integers2 << endl;
    integers2.insertA(111, 20);
    integers2.insertA(1111, 10);
    cout << "After insertion and deletion: integers2:\n" << integers2 << endl;
    integers2.deleteA(9);
    integers2.deleteA(9);
    cout << "After insertion and deletion: integers2:\n" << integers2 << endl;
    Array<double> double1(12);
    cout << "\nEnter 12 double precision numbers:" << endl;
    cin >> double1;
    cout << "\nCreate double2 initialized with double1: " << endl;
    Array<double> double2(double1);
    cout << "double1: \n" << double1 << "double2: \n" << double2;
    // use overloaded equality (==) operator
    cout << "\nEvaluating: double1 == double2" << endl;
    if (double1 == double2)
    {
        cout << "double1 and double2 are equal" << endl;
    }
    cout << "\n\nAssigning 100.01 to double1[6]" << endl;
    double1[6] = 100.01;
    cout << "double1:\n" << double1 << endl;
    double1.insertA(111.1, 0);
    double1.deleteA(9);
    cout << "After insertion and deletion: double1:\n" << double1 << endl;

    Array<string> strA(5);
    cout << "\nEnter 5 strings:" << endl;
    cin >> strA;
    strA.insertA("Programming", 5);
    strA.insertA("C++", 6);
    strA.deleteA(1);
    cout << "After insertion and deletion: strA:\n" << strA << endl;
    // attempt to use out-of-range subscript
    cout << "\nAttempt to assign \"abcd\" to strA[7]" << endl;
    strA[7] = "abcd";
    return 0;
}
