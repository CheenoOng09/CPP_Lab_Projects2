// Employee class member function definitions
#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

//constructor uses member initializer list to pass initializer values to constructors of member objects
Employee::Employee(const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire, const int &initSalary, Date &retireDate)
    :firstName(first), // initialize first name
    lastName(last), //initialize last name
    birthDate(dateOfBirth), // initialize birthdate
    hireDate(dateOfHire), // initialize hire date
    hiredSalary(initSalary), //////////////
    monthSalary(hiredSalary),
    retiredDate(retireDate)
{
    // output Employee object to show when constructor is called
    cout << "Employee object constructor: " << firstName << ' ' << lastName << "  Monthly paid: " << monthSalary << endl;
    /*if(birthDate.Date::beforeDate(hireDate)){
        cout << firstName << " " << lastName << " with inconsistent dates!" << endl;
    }*/
    if(retiredDate.Date::beforeDate(hireDate)){
        cout << firstName << " " << lastName << " with inconsistent dates!" << endl;
    }
}

void Employee::print() const
{

    //if(retiredDate.afterDate(hireDate)){
    //    cout << firstName << " " << lastName << " with inconsistent dates!" << endl;
    //}
    cout << firstName << lastName << "  Hired: ";
    hireDate.Date::print();
    cout << "  Birthday: ";
    birthDate.Date::print();
    cout << " Hired Salary: " << hiredSalary << "  Monthly pay: " << monthSalary << "  Dismissing: ";
    retiredDate.Date::print();
    cout << endl;
}

Employee* Employee::setRetiredDate(const Date & newDate){
    retiredDate = newDate;
    return this;
}
Employee& Employee::increaseSalary(int extraSalary){
    monthSalary = extraSalary + monthSalary;
    return *this;
}

Employee::~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}
