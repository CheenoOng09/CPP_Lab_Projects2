#include "Hugeint.h"
#include <iostream>

using namespace std;

int main()
{
    HugeInt n1(87654321);
    HugeInt n3("9999999999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5(n4);
    cout << "n1 is " << n1 << "\nn3 is " << n3 << "\nn4 is " << n4
    << "\nn5 is " << n5 << "\n\n";
    cout << "n3 is " << n3 << '\n';
    HugeInt n6;
    cout << "n6 = " << n6 << '\n';
    cout << "n6 = n3 + n4 = " << n3 << " + " << n4 << " = " << n3 + n4 << "\n\n";
    cout << "9 + n1 = " << 9 + n1 << " " << "9" + n1 << " " << n1 + 9 << '\n';
    cout << "n4+100+900+n5= " << n4 + 100 + "900" + n5 << '\n';

    cout << "n3++ = " << n3++ << '\n';
    cout << "n3 = " << n3 << '\n';
    cout << "++n3 = " << ++n3 << '\n';
    cout << "n3 = " << n3 << '\n';
    n3 += 119;
    cout << "n3=+119: " << n3 << '\n';
    HugeInt n7, n8, n9;
    n7 = 1000000001;
    n8 = "1000000000000000000000000000000000000000000000009";
    n9 = n6 + n4;
    cout << "n7 = " << n7 << " n8 = " << n8 << " n9 = " << n9 << '\n';
    cout << "\nn7+n8+n9 = " << n7 + n8 + n9 << '\n';
    cout << "\nTotal number of digits = " << n1.getNumDigits() + n3.getNumDigits() + n4.getNumDigits()
    + n5.getNumDigits() + n6.getNumDigits() + n7.getNumDigits() + n8.getNumDigits() + n9.getNumDigits() << '\n';
    if (n3 <= n1)
    {
        cout << "\nyes-1" << '\n';
    }
    else
    {
        cout << "\nno-1" << '\n';
    }
    if (n3 <= 100)
    {
        cout << "yes-2" << '\n';
    }
    else
    {
        cout << "no-2" << '\n';
    }
    if (100 <= n3)
    {
        cout << "yes-3" << '\n';
    }
    else
    {
        cout << "no-3" << '\n';
    }
    if (n3 <= "100")
    {
        cout << "yes-4" << '\n';
    }
    else
    {
        cout << "no-4" << '\n';
    }
    if ("100" <= n3)
    {
        cout << "yes-5" << '\n';
    }
    else
    {
        cout << "no-5" << '\n';
    }
    if (n3 <= n3)
    {
        cout << "yes-6" << '\n';
    }
    else
    {
        cout << "no-6" << '\n';
    }
    return 0;
}
