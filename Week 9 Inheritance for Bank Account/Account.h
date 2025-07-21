#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(double = 0.0, double = 0.0);
    void credit(double = 0.0); // deposit money > 0
    bool debit(double = 0.0); // Withdraw Money > 0
    double getBalance(); // get balance
    double calculateInterest(); // return the interest and add the interest to the balance
    void print(); // print balance and interest rate
private:
    double balance; // Account balance >=0
    double interestRate; // Interest rate >= 0
};
#endif // ACCOUNT_H
