# Week 5 – Data Member Initialization and Class Composition (CP112)

This project demonstrates **class composition**, **const data members**, **data member initialization**, and the use of the **this pointer** in C++. It models employee records using a composed `Date` class and focuses on verifying consistency between dates such as birth, hire, and retirement.

## Tasks

You are required to:

1. Modify the `Date` class to include:
   - `beforeDate(const Date&) const`
   - `afterDate(const Date&) const`

2. Modify the `Employee` class to include:
   - A `const int` data member `hiredSalary`
   - An `int` data member `monthSalary` initialized to `hiredSalary`
   - A `Date` member `retiredDate`, initially set to 1/1/1900
   - `setRetiredDate(const Date&)` to update retirement date and check consistency
   - `increaseSalary(int)` to increase monthly salary
   - Validations in constructor:
     - `hireDate` must be after `birthDate`
     - `retiredDate` must be after `hireDate`

3. Modify or implement any other required methods to make the given `main()` work without any changes.

## Input/Output

No input is required; everything is hardcoded in `main.cpp`. The output includes:

- Constructor and destructor logs for each object
- Warnings if any date inconsistencies exist
- Final print of each employee's details

### Example Output (Excerpt)
Date object constructor for date 3/24/1961
Date object constructor for date 4/12/1998
...
Employee object constructor: Tom Crouse Monthly paid: 66000
TomCrouse Hired: 4/12/1998 Birthday: 3/24/1961 Hired Salary: 66000 Monthly pay: 68000 Dismissing: 2/28/2021
...
Employee object destructor: Hunton, Mary
...


## Key Concepts

- Class Composition (`Employee` has `Date`)
- Constant data members and initializer lists
- Cascading function calls using `this` pointer
- Destructor order confirmation
- Date comparison functions

## Files Included

- `main.cpp` — Provided main function (do not modify)
- `Date.h`, `Date.cpp` — `Date` class and methods
- `Employee.h`, `Employee.cpp` — `Employee` class and methods
- `Problem.pdf` — Complete problem instructions and learning objectives

