#include <iostream>
#include "Date.h"
#include "Employee.h"

int main()
{
    Date birth(3,24,1961);
    Date hire(4,12,1998);
    Date dismiss(2,28,2021);
    Date zero;

    if(zero.beforeDate(hire)){
        zero.print();
        cout <<" is before ";
        hire.print();
        cout << endl;
    }
    else if(zero.afterDate(hire)){
        zero.print();
        cout << " is after ";
        hire.print();
        cout << endl;
    }
    if(dismiss.afterDate(hire)){
        dismiss.print();
        cout << " is after ";
        hire.print();
        cout << endl;
    }
    else if(dismiss.beforeDate(hire)){
        dismiss.print();
        cout << " is before ";
        hire.print();
        cout << endl;
    }
    Employee manager1("Tom", "Crouse", birth, hire, 66000, zero);
    cout << endl;
    manager1.print();
    manager1.increaseSalary(2000).print();
    manager1.setRetiredDate(dismiss)->print();
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff(14,35,1994);
    cout << endl;
    Date birth1(1,1,1968);
    Date hire1(1,1,1994);
    Date dismiss1(3,28,1990);
    Employee E1("Mary", "Hunton", birth1, hire1, 45000, dismiss1);
    cout << endl;
    Date dismiss2(3,28,2000);
    E1.setRetiredDate(dismiss2)->print();
    E1.increaseSalary(-2000).print();
}
