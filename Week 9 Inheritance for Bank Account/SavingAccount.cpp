#include <iostream>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"

using namespace std;


SavingAccount::SavingAccount(double bal, double iRate, double transFee)
    : Account(bal, iRate)
{
    transactFee = transFee;
}

bool SavingAccount::debit(double withdw)
{
    return Account::debit(withdw + transactFee);
    /*if(withdw > 0 && withdw <= getBalance()){
        balance = getBalance() - withdw - transactFee;
        return true;
    }
    else if (withdw > getBalance()){
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }*/
}
bool SavingAccount::SavingToChecking(CheckingAccount &cAnt, const double amount)
{
    if(amount > 0 && amount <= getBalance()){
        SavingAccount::debit(amount);
        cAnt.credit(amount);
        //CheckingAccount.setBalance(amount + CheckingAccount.getBalance());
        //CheckingAccount.balance = amount + CheckingAccount.getBalance();
        //setBalance(getBalance() - amount - transactFee); //balance = balance - amount - transactFee;
        //CheckingAccount.setBalance(CheckingAccount.getBalance() - CheckingAccount.transactFeeD); //CheckingAccount.balance = CheckingAccount.getBalance() - CheckingAccount.transactFeeD;
        return true;
    }
    else if (amount > getBalance()){
        cout << "Transfer transaction fails." << endl;
        return false;
    }
}
