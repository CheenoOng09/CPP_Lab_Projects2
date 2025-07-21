#include <iostream>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"


using namespace std;

CheckingAccount::CheckingAccount(double bal, double iRate, double transFeeW, double transFeeD )
    :Account(bal, iRate)
{
    transactFeeW = transFeeW;
    transactFeeD = transFeeD;
}

bool CheckingAccount::debit(double withdrawAmount)
{
    return Account::debit(withdrawAmount + transactFeeW);
    /*if(withdrawAmount > 0 && withdrawAmount <= getBalance()){
        balance = balance - withdrawAmount - transactFeeW;
        return true;
    }
    else if (withdw > balance){
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }*/
}
void CheckingAccount::credit(double depositAmount)
{
    Account::credit(depositAmount - transactFeeD);
    /*if(depositAmount > 0)
        balance = balance + depositAmount - transactFeeD;*/
}

bool CheckingAccount::CheckingToSaving(SavingAccount &SavingsAccnt, const double amount)
{
    if(amount > 0 && amount <= getBalance()){
        CheckingAccount::debit(amount);
        SavingsAccnt.credit(amount);

        /*SavingsAccnt.balance = amount + SavingsAccnt.getBalance(); deposit the amount to the savings
        balance = balance - amount - transactFeeW;*/ // withdraw the amount from the checking
        return true;
    }
    else if (amount > getBalance()){
        cout << "Transfer transaction fails." << endl;
        return false;
    }
}
