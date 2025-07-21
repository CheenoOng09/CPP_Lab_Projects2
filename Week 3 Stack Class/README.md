# Week 4 – Stack Class for Arithmetic Expression Checking (CP112)

This project implements a custom `Stack` class to check the correctness of arithmetic expressions based on matched parentheses. It demonstrates how to design a class with dynamic memory, separate interface and implementation, and use it in a global function.

## Tasks

You are required to:

1. Define a `Stack` class in `Stack.h` and implement its functions in `Stack.cpp`.
2. Implement a global function `checkExpression(string, Stack&)` that:
   - Pushes `(` onto the stack
   - Pops for every `)`
   - Detects unbalanced parentheses
   - Handles stack overflow
3. Use the provided `main()` to read input and process multiple expressions.

## Input Format

- First line: size of the stack
- Second line: number of expressions to check
- Next lines: each contains one arithmetic expression

## Output Format

- For each expression:
  - `Correct` if balanced
  - `More ('s` if too many opening brackets
  - `More )'s` if too many closing brackets
  - `Stack is full` if stack overflow occurs

### Example

**Input:**
4
3
(2+3)
((2+3)
2+3)

**Output:**
Correct
More ('s
More )'s


## Key Concepts

- Stack implementation using dynamic arrays and pointer arithmetic
- Header (`.h`) and implementation (`.cpp`) file separation
- Global function usage and class interaction
- Basic parsing of character expressions

## Files Included

- `main.cpp` — Driver program (cannot be modified)
- `Stack.h` — Class definition
- `Stack.cpp` — Stack method implementation
- `Problem.pdf` — Problem specification
