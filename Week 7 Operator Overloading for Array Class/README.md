# Week 7 – Operator Overloading for Array Class (CP112)

This lab focuses on operator overloading in C++ to extend the functionality of a custom `Array` class. The lab demonstrates both member and friend/global operator overloads for working with dynamic arrays.

## Tasks

You are required to:

1. Overload the `+` operator to:
   - Concatenate two arrays (e.g., `C = A + B`)
   - Add a constant to every element (e.g., `A + 2`)
   - Add a constant to every element using global overload (e.g., `1 + A`)

2. Overload the unary `+` operator:
   - Return the sum of all elements in the array (e.g., `+A`)

3. Overload the `<<` operator:
   - Shift the elements in an array to the left by `k` positions (e.g., `A << 3`)

4. Implement stream operators:
   - `>>` to input array values
   - `<<` to output array values

5. Keep the provided `main.cpp` unchanged.

## Input Format

User will be prompted to enter 17 integers as input during program execution.

## Output Format

Displays:

- Initial array states
- Results of all overloaded operations
- Sum of elements
- Attempt to access out-of-range subscript (with error handling)

### Example
```bash
Enter 17 integers:
10 20 30 ...
After input, the Arrays contain:
integers1:
10 20 30 ...
integers2:
...
integers1 and integers2 are not equal
...
The sum of the elements in array C = 495
Array integers1 = 1+integers1+2 =
13 23 33 ...
```

## Key Concepts

- Operator overloading for:
  - Assignment `=`
  - Equality `==` / Inequality `!=`
  - Addition `+` (both binary and unary)
  - Array subscript `[]`
  - Left shift `<<` for rotating array
- Copy constructor and destructor
- Friend functions vs member functions

## Files Included

- `main.cpp` — Contains the test driver (must remain unchanged)
- `Array.h` — Declaration of the `Array` class and overloaded operators
- `Array.cpp` — Implementation of the class and all operators
- `Problem.pdf` — Full lab instructions and grading notes

