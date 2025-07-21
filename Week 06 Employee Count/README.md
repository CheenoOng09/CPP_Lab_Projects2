# Week 6 – Employee Count (CP112)

This lab demonstrates the use of **friend functions**, **static data members**, **static member functions**, and object tracking using a C++ class. The program tracks the number of permanent and contract employees created during runtime.

## Tasks

You are required to:

1. Add a private data member `eType` to represent employee type:
   - `'P'` = Permanent
   - `'C'` = Contract

2. Replace the static member `count` with:
   - `pCount` to count permanent employees
   - `cCount` to count contract employees

3. Add the following member functions:
   - `int getpCount()` — returns permanent count
   - `int getcCount()` — returns contract count
   - `static void printAllCount()` — prints both counts
   - `Employee* printFirstName()` — prints first name, returns pointer to object
   - `Employee& printLastName()` — prints last name, returns reference to object

4. Add a friend function:
   - `void print(const Employee&)` — prints full employee info using access to private members

5. Implement correct constructor/destructor behavior:
   - Update static counts accordingly
   - Print logs for constructor and destructor

6. Do **not** modify the provided `main.cpp`.

## Output Behavior

- Prints the total employee count before, during, and after object instantiation
- Logs constructor and destructor messages for each employee
- Demonstrates method chaining with `this` pointer
- Uses the friend function to print employee info

### Sample Output (Excerpt)
Number of employees before instantation of any object is 0
Employee constructor for Jhon Reid is called.
Employee constructor for Maria Vinci is called.
Employee's type F is incorrect.
...
Total number of employees after object are instantiated: 7
Emily Willow C

Employee 1: Susan Baker
Employee 2: Robert Jones

Total number of employees after objects are instantiated:
Total number of Employees= 5 Permanent employees= 4 Contract employees= 1
...
After objects are deleted, Total number of employees= 0 Permanent employees= 0 Contract employees= 0


## Key Concepts

- Static data members (`pCount`, `cCount`)
- Friend function for external access
- Pointer and reference return types
- Proper object destruction tracking
- Function overloading and method chaining

## Files Included

- `main.cpp` — Provided driver code (do not modify)
- `Employee.h`, `Employee.cpp` — Class interface and implementation
- `Problem.pdf` — Full lab instructions and grading criteria

