#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

class ClientData{
public:
    ClientData(int = 0, string = "", string = "", double = 0.0);

    void setAccountNumber(int);
    int getAccountNumber() const;

    void setLastName(string);
    string getLastName() const;

    void setFirstName(string);
    string getFirstName() const;

    void setBalance(double);
    double getBalance() const;
private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
};

#endif



