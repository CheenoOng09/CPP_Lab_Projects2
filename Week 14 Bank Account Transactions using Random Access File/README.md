# Week 14 - Bank Account Transactions using Random Access File

## Problem Description

This lab focuses on the use of **random access file processing** in C++. The objective is to simulate a simple banking system that supports the following operations:

- Create new bank accounts using a random access binary file
- Update account balances (deposit or withdraw)
- Delete existing accounts
- Display all existing accounts to a formatted text file
- Reprint valid account records before and after performing transactions

Each record represents a client and contains the following fields:
- Account Number (1 to 100)
- Last Name (max 15 characters)
- First Name (max 10 characters)
- Balance (double)

You are required to:
1. Modify the `newRecord()` function to use `getValidAccountNumber()` which returns the smallest unused account number.
2. Implement the `printAllRecords()` function to display all valid records (account number > 0).
3. Update `main()` to loop and handle different transaction types: print, update, create new, delete, and exit.
4. Use binary I/O functions (`read`, `write`, `seekg`, `seekp`) with `reinterpret_cast` for object serialization.
5. Use the provided `credit.dat` as the data file and test with a sequence of account operations.

## Files Included

- `main.cpp` - Contains the main program logic and all file operations.
- `Account.cpp` - Implements the `ClientData` class methods.
- `Account.h` - Header file defining the `ClientData` class with fixed-length fields.
- `credit.dat` - Binary data file representing the account database.
- `Problem.pdf` - Assignment prompt and implementation requirements.

## Key Concepts

- Random access file I/O with binary mode
- Using `seekg`, `seekp`, `tellg`, and `tellp` to move file pointers
- Creating and updating records with fixed sizes for compatibility with binary I/O
- Input validation and structured data storage
- Object-oriented design with custom classes for record management

## Sample Features Implemented

- Automatically finds the smallest available account number
- Prevents creation if all account slots are occupied
- Deletes and updates records in-place without rewriting the entire file
- Outputs a formatted `print.txt` file with all account records

