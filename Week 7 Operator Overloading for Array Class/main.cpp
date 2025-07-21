#include "Array.h"
#include <iostream>

int main()
{
    Array integers1(7);
    Array integers2;

    cout << "Size of Array integers1 is " << integers1.getSize() << "\nArray after initialization:\n" << integers1;
    cout << "\nSize of Array integers2 is " << integers2.getSize() << "\nArray after initialization:\n" << integers2;
    cout << "\nEnter 17 integers:\n";
    cin >> integers1 >> integers2;
    cout << "\nAfter input, the Arrays contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nEvaluating: integers1 != integers2\n";

    if (integers1 != integers2)
    {
        std::cout << "integers1 and integers2 are not equal\n";
    }
    Array integers3(integers1);
    cout << "\nSize of Array integers3 is " << integers3.getSize() << "\nArray after initialization:\n" << integers3;
    cout << "\nAssigning integers2 to integers1:\n";
    integers1 = integers2;
    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nEvaluating: integers1 == integers2\n";
    if (integers1 == integers2)
    {
        cout << "integers1 and integers2 are equal\n";
    }
    cout << "\nintegers1[5] is " << integers1[5];
    cout << "\n\nAssigning 1000 to integers1[5]\n";
    integers1[5] = 1000;
    cout << "integers1:\n" << integers1;

    cout << "integers2 :\n" << integers2 << '\n';
    cout << "integers3 :\n" << integers3 << '\n';
    Array C;
    C = integers1 + integers2 + integers3;
    cout << "Array C = integers1 + integers2 + integers3: \n" << C;
    int k = 30;
    C << k;
    cout << "\nShifting the elements of C to the left by " << k << " places:\n" << C << '\n';
    cout << "The sum of the elements in array C = " << +C << '\n';
    cout << "Array integers1 = 1+integers1+2 =\n" << 1+integers1+2 << '\n';

    cout << "\nAttempt to assign 1000 to integers1[15]\n";
    integers1[15] = 1000;
}
