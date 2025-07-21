#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" // include Date class definition

using namespace std;

class Employee{
public:
    Employee(const string &, const string &, const Date &, const Date &, const int &, Date &);
    void print() const;
    ~Employee(); // Provided to confirm destruction order

    Employee* setRetiredDate(const Date &); /////
    Employee& increaseSalary(int); //////

private:
    string firstName; //composition member object
    string lastName;
    const Date birthDate;
    const Date hireDate;
    const int hiredSalary; //////////////
    int monthSalary; ////////////////////
    Date retiredDate; ///////////////////
};

#endif
// Employee class Definition showing composition
// Member functions defined in Employee.cpp
