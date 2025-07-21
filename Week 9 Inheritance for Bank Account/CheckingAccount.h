#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
    CheckingAccount(double = 0.0, double = 0.0, double = 3.0, double = 2.0); // Balance, Interest Rate, transaction fee (withdraw), transaction fee (deposit)
    bool debit(double = 0.0); // withdraw money with transaction fee
    void credit(double = 0.0);
    bool CheckingToSaving( SavingAccount&, const double );
private:
    double transactFeeW; // Withdraw
    double transactFeeD; // Deposit
};

#endif
