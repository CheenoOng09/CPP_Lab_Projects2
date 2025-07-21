#include <iostream>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    cout << "\nCreate a saving account." << endl;
    SavingAccount sAcnt(300.0,0.05);
    sAcnt.print();
    sAcnt.debit(50.0);
    cout << "   New balance after withdrawing $50 from the saving account: " << sAcnt.getBalance() << endl;
    sAcnt.credit(150.0);
    cout << "   New balance after depositing $150 to the saving account: " << sAcnt.getBalance() << endl;
    sAcnt.print();
    cout << "   Interest of the saving account: " << sAcnt.calculateInterest() << endl;
    cout << "   New balance after adding interest: " << sAcnt.getBalance() << endl;
    cout << "Withdrawing 80 from the saving account:" << endl;
    sAcnt.debit(800);

    cout << "\nCreate a checking account." << endl;
    CheckingAccount cAcnt(400.0, 0.02);
    cAcnt.print();
    cAcnt.debit(200.0);
    cout << "   New balance after withdrawing $200 from the checking account: " << cAcnt.getBalance() << endl;
    cAcnt.credit(150.0);
    cout << "   New balance after depositing $150 to the checking account: " << cAcnt.getBalance() << endl;

    cout << endl;
    cAcnt.print();
    sAcnt.print();

    cout << "\nAfter transfer $600 from cAcnt to sAcnt:" << endl;
    cAcnt.CheckingToSaving(sAcnt,600.0);
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << "  New balance of sAcnt: " << sAcnt.getBalance() << endl;
    cout << "\nAfter transfer $800 from sAcnt to sAcnt: " << endl;
    sAcnt.SavingToChecking(cAcnt, 800.0);
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << "  New balance of sAcnt: " << sAcnt.getBalance() << endl;
    cAcnt.CheckingToSaving(sAcnt,50.0);
    cout << "\nAfter transfer $50 from cAcnt to sAcnt:" << endl;
    cout << "New balance of cAcnt " << cAcnt.getBalance() << "  New balance of sAcnt: " << sAcnt.getBalance() << endl;
    sAcnt.SavingToChecking(cAcnt, 50.0);
    cout << "\nAfter transfer $50 from sAcnt to sAcnt: " << endl;
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << "  New balance of sAcnt: " << sAcnt.getBalance() << endl;
}
