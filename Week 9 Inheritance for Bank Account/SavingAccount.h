#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H


class CheckingAccount;
class SavingAccount : public Account
{
public:
    SavingAccount(double = 0.0, double = 0.0, double = 3.0); // balance , interest rate , transaction fee
    bool debit(double = 0.0);
    bool SavingToChecking(CheckingAccount& , const double); // transfer money from saving to checking account. theres transaction fee for withdrawing
private:
    double transactFee; // transaction fee for withdrawing
    CheckingAccount *p;
};

#endif // SAVINGACCOUNT_H
