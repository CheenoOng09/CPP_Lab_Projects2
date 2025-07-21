#include <iostream>
#include "Employee.h"

using namespace std;

//void print(Employee);

int main()
{
    // no objects exist; use class name and binary scope resolution
    // operator to access static member function getCount
    cout << "Number of employees before instantation of any object is " << Employee::getCount() << endl; // use class name

    // the following scope creates and destroys
    // Employee objects before main terminates
    {
        Employee e4("Jhon", "Reid", 'P');
        Employee e5("Maria", "Vinci", 'C');
        Employee e6("Vincent", "Url", 'F');
        Employee e7("RB", "Lin", 'P');
        Employee e1("Susan", "Baker", 'P');
        Employee e2("Robert", "Jones", 'P');
        Employee e3("Emily", "Willow", 'C');
        // two objects exist; call static member function getCount again
        // using the class name and the binary scope resolution operator
        cout << "Total number of employees after object are instantiated: " << Employee::getCount() << endl;
        print(e3);
        cout << "\n\nEmployee 1: " << e1.getFirstName() << " " << e1.getLastName()
        << "\nEmployee 2: " << e2.getFirstName() << " " << e2.getLastName() << "\n\n";
        Employee e8("Thomas", "Hwang", 'P');
        Employee e9("James", "Wang", 'P');
        cout << "Total number of employees after objects are instantiated: \n";
        Employee::printAllCount();

        cout << "\n\nEmployee 3: ";
        e3.printFirstName()->printLastName();
        cout << "\nEmployee 3: ";
        e3.printLastName().printFirstName();
        cout << "\nEmployee 4: ";
        e4.printFirstName()->printLastName();
        cout << "\nEmployee 4: ";
        e4.printLastName().printFirstName();
        cout << endl << endl;;
    }

    // no onbjects exist, so call static member function getCount again
    // using the class name and the binary scope resolution operator
    cout << "\nAfter objects are deleted, " << "Total number of employees= " << Employee::getpCount() + Employee::getcCount() << "  Permanent employees= " << Employee::getpCount() << "  Contract employees= " << Employee::getcCount() << endl;
}

/*void print(Employee worker)
{
    cout << Employee::firstName << " " << Employee::lastName << " " << Employee::typeName << endl;
}*/
