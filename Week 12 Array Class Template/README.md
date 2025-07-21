# Week 12 – Array Class Template (CP112)

This lab introduces **class templates** in C++ by building a generic `Array` class that supports arrays of any type. It demonstrates template programming with dynamic memory, operator overloading, and user-defined operations like insertion and deletion.

## Tasks

You are required to:

1. Convert the existing `Array` class into a class template.
2. Overload the following operators for the class template:
   - `>>` for input
   - `<<` for output
   - `==` and `!=` for equality checks
   - `[]` for element access (with range checking)
3. Implement two member functions:
   - `void insertA(T element, int index)`  
     Inserts `element` at the given `index`, shifting existing elements.
   - `void deleteA(int index)`  
     Deletes the element at `index`, shifting remaining elements forward.
4. Handle out-of-range indices gracefully by printing error messages but continuing execution.
5. Use the provided `main.cpp` without modification.

## Output Behavior

The program reads multiple arrays of different types, performs insertions and deletions, compares arrays, and tests the class template's behavior with various types: `int`, `double`, and `string`.

### Sample Output (Excerpt)

```
Enter 17 integers:
After input, the Arrays contain:
integers1:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17
integers2:
...
Evaluating: integers1 != integers2
integers1 and integers2 are not equal

Assigning 1001 to integers2[8]
After insertion and deletion: integers2:
...

Enter 12 double precision numbers:
...

Enter 5 strings:
...
Attempt to assign "abcd" to strA[7]
Error: subscript 7 out of range
```


## Key Concepts

- Class Templates with `template<typename T>`
- Friend function templates
- Operator overloading
- Dynamic memory management
- Type-generic programming in C++

## Files Included

- `main.cpp` — Test driver for template behavior (must not be modified)
- `Array.h` — Templated array class with insertion, deletion, and operator overloads
- `Problem.pdf` — Instructions and explanation of template concepts
