#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee
{
//friend void print(Employee);

friend void print(Employee & worker){
    cout << worker.getFirstName() << " " << worker.getLastName() << " " << worker.getTypeName() << endl;
}
public:
    Employee( const string &, const string &, const char &);  // constructor
    ~Employee();                                // destructor
    string getFirstName() const;                // return first name
    string getLastName() const;                 // return last name
    // static member function
    static int getCount();                      // return number of objects instantiated
    static void printAllCount();
    static int getpCount();
    static int getcCount();
    Employee* printFirstName();
    Employee& printLastName();
    char getTypeName() const;

private:
    string firstName;
    string lastName;
    char typeName;
    // static data
    //static int count; // number of objects instantiated
    static int cCount;
    static int pCount;
};
#endif // EMPLOYEE_H
