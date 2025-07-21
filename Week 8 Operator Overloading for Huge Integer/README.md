# Week 8 – Operator Overloading for Huge Integer (CP112)

This lab demonstrates advanced operator overloading by implementing a custom `HugeInt` class capable of handling integers with an arbitrary number of digits. The lab emphasizes the use of **global friend functions**, **dynamic memory**, and **overloaded operators** to simulate arithmetic with large numbers.

## Tasks

You are required to:

1. Modify the `HugeInt` class to support:
   - Dynamically allocated digit arrays (`short* integer`)
   - Accurate digit tracking (`int digits`)

2. Overload the following operators:
   - `+` for:
     - `HugeInt + HugeInt`
     - `HugeInt + int`
     - `HugeInt + string`
     - `int + HugeInt`
     - `string + HugeInt`
   - `+=` for `HugeInt += int` and `HugeInt += HugeInt`
   - `++` (both prefix and postfix)
   - `<=` for all combinations:
     - `HugeInt <= HugeInt`
     - `HugeInt <= int`, `int <= HugeInt`
     - `HugeInt <= string`, `string <= HugeInt`
   - `=` assignment from another `HugeInt`, `int`, or `string`

3. Implement:
   - `getNumDigits()` to return digit count
   - Proper memory management using destructor (`delete[]`)
   - Output formatting to show digits with a count in parentheses

4. Do not modify the provided `main.cpp`.

## Output Format

- Proper printing of HugeInt values followed by their digit count in parentheses
- All overloaded operations must behave like native types
- Comparison and increment operations must function as expected
- Program output must exactly match expected results (especially the `yes-yes-no-yes-no` pattern for comparisons)

### Example Output (Excerpt)
```
n1 is 87654321(8)
n3 is 9999999999999999999999999999999999(34)
n4 is 1(1)
n6 = n3 + n4 = 10000000000000000000000000000000000(35)

9 + n1 = 87654330(8) 87654330(8) 87654330(8)
n4+100+900+n5 = 1002(4)

n3++ = 10000000000000000000000000000000000(35)
++n3 = 10000000000000000000000000000000002(35)
...
Total number of digits = 140
yes-1
no-2
yes-3
no-4
yes-5
yes-6
```

## Key Concepts

- Global operator overloading (`friend` functions)
- Prefix and postfix increment
- Overloaded comparison operators
- Dynamic memory allocation and cleanup
- Overloaded constructors from `int`, `string`, and `HugeInt`

## Files Included

- `main.cpp` — Driver file (should not be modified)
- `Hugeint.h` — Declaration of the `HugeInt` class and overloaded operators
- `Hugeint.cpp` — Full implementation of all overloaded behavior
- `Problem.pdf` — Lab instructions and grading criteria
