#include <iostream>
#include "Employee.h"

using namespace std;

//define and initialize static data member at global namespace scope

//int Employee::count = 0; // cannot include keyword static
int Employee::pCount = 0;
int Employee::cCount = 0;

//define static member function that returns number of Employee objects instantiated (declared static in Employee.h)
int Employee::getCount()
{
    return getcCount() + getpCount();
} // end static function getCount

// constructor initializes non-static data members and increments static data member count
Employee::Employee( const string &first, const string &last, const char &status)
    :firstName(first), lastName(last), typeName(status)
{
    if(typeName == 'C'){
        ++cCount;
        //++count; // increment static count of Employees
        cout << "Employee constructor for " << firstName << " " << lastName << " is called." << endl;
    }
    else if(typeName == 'P'){
        ++pCount;
        //++count; // increment static count of Employees
        cout << "Employee constructor for " << firstName << " " << lastName << " is called." << endl;
    }
    else{
        cout << "Employee's type " << typeName << " is incorrect." << endl;
        cout << "Employee constructor for " << firstName << " " << lastName << " is called." << endl;
    }
}

Employee::~Employee()
{
    cout << "Employee destructor for " << firstName << " " << lastName << " is called" << endl;
    if(typeName == 'C'){
        --cCount;
    }
    else if(typeName == 'P'){
        --pCount;
    }
}

string Employee::getFirstName() const
{
    return firstName; // return copy of the first name
} // end function getFirstName

string Employee::getLastName() const
{
    return lastName; // return copy of last name
} // end function getLastName

char Employee::getTypeName() const
{
    return typeName;
}

int Employee::getpCount()
{
    return pCount;
}
int Employee::getcCount()
{
    return cCount;
}
void Employee::printAllCount()
{
    cout << "Total number of Employees= " << Employee::getpCount() + Employee::getcCount() << "   Permanent employees= "
    << Employee::getpCount() << "   Contract employees= " << Employee::getcCount() << endl;
}

Employee* Employee::printFirstName(){
    cout << getFirstName() << " ";
    return this;
}
Employee& Employee::printLastName(){
    cout << getLastName() << " ";
    return *this;
}

/*void print(Employee worker){
    cout << worker.getFirstName() << " " << worker.getLastName() << " " << worker.getTypeName() << endl;
}*/
