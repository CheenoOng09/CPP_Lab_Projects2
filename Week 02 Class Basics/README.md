# Week 2 – Class Basics (CP112)

This project introduces the fundamentals of C++ class creation, object instantiation, and basic object-oriented programming concepts. The lab uses a `Time` class to practice:

- Class declaration and implementation
- Constructors and member functions
- Object creation via name, pointer, and reference
- Passing objects as parameters
- Function overloading and scope resolution

## Tasks

You are required to:

1. **Fix Syntax Errors** in the given `main()` function.
2. **Modify 2 lines** and **add 4 new lines** to make the program work.
3. **Implement 3 member functions** in the `Time` class:
   - `void resetTime()` — Resets time to 00:00:00
   - `void compareTime(Time t2)` — Compares time with another object and prints:
     - `"Earlier"`, `"Later"`, or `"Same"`
   - `void advanceTime(int numMinutes)` — Adds minutes to the current time, wrapping hours over 24.

## Input/Output

No manual input is required. The `main()` function demonstrates usage of all methods. The output should follow the given format in the lab handout, showing universal and standard time before and after modification.

## Key Concepts

- Class design and encapsulation
- Member function implementation
- Object pointers and references
- Time arithmetic and comparison logic
- Proper commenting of changes for grading:
  - `//################` for added lines
  - `//*******************` for modified lines

## Files Included

- `main.cpp` — Includes the `Time` class and an incomplete `main()` to be fixed
- `Problem.pdf` — Lab instructions and grading requirements

## Notes

Make sure your output format matches the sample exactly. No lines in `main()` may be deleted. All added or modified lines must be clearly commented.
