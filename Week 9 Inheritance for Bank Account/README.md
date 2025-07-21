# Week 9 – Inheritance for Bank Account (CP112)

This lab demonstrates the concept of **public inheritance** in C++. You will design a class hierarchy with a base `Account` class and two derived classes: `SavingAccount` and `CheckingAccount`. The goal is to simulate basic banking operations with additional transaction logic specific to each account type.

## Tasks

You are required to:

1. **Implement `SavingAccount` class**:
   - Inherit from `Account`
   - Implement `debit()` that deducts both the amount and transaction fee (if successful)
   - Implement `SavingToChecking()` to transfer funds to a `CheckingAccount`

2. **Implement `CheckingAccount` class**:
   - Inherit from `Account`
   - Implement `debit()` and `credit()` to apply transaction fees if successful
   - Implement `CheckingToSaving()` to transfer funds to a `SavingAccount`

3. **Main Program Requirements**:
   - You **must not** modify the provided `main.cpp`
   - Constructor, interest handling, and print functions must behave as expected
   - Transaction success or failure must print appropriate messages

## Output Behavior

- Print initial balances, apply interest, and display updated balances
- Perform withdrawals, deposits, and fund transfers between accounts
- Display account balances after each operation

### Sample Output (Excerpt)
```
Create a saving account.
Balance: 300
Interest Rate: 0.05
New balance after withdrawing $50 from the saving account: 247
New balance after depositing $150 to the saving account: 397
Balance: 397
Interest Rate: 0.05
Interest of the saving account: 19.85
New balance after adding interest: 416.85
Withdrawing 80 from the saving account:
Debit amount exceeded account balance.

Create a checking account.
Balance: 400
Interest Rate: 0.02
...
After transfer $600 from cAcnt to sAcnt:
Transfer transaction fails.
```

## Key Concepts
- Public inheritance
- Constructor chaining
- Transaction fee logic in derived classes
- Forward class declarations
- Polymorphic behavior through overridden member functions

## Files Included
- `main.cpp` — Pre-written test driver (must remain unchanged)
- `Account.h`, `Account.cpp` — Base class implementation
- `SavingAccount.h`, `SavingAccount.cpp` — Derived class with withdraw/transfer logic
- `CheckingAccount.h`, `CheckingAccount.cpp` — Derived class with withdraw/credit/transfer logic
- `Problem.pdf` — Full lab instructions and grading criteria
