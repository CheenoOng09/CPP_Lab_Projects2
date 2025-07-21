# Week 15 – Vector and Map with Iterator

This lab demonstrates the use of **Standard Template Library (STL)** containers and algorithms, specifically focusing on `vector`, `map`, `set`, and **iterators**. The program performs data analysis on macro cell placement from LEF/DEF format files commonly used in VLSI design.

## Problem Description

You are given two input files:
- A `.lef` file that contains macro definitions and their sizes.
- A `.def` file that contains instances and their associated macros.

The goal is to:
- Read macro data using `map` containers.
- Store and count macro usage with `set` and `map`.
- Process instance data from the DEF file using maps and iterators.
- Exclude specific macros from the analysis using a `set` of blocked macros.
- Display useful statistics about the design layout using STL algorithms.

## Key Tasks

- Parse the `.lef` file and calculate macro areas.
- Parse the `.def` file to extract instances and their corresponding macros.
- Use `map<string, double>` and `map<string, int>` to track area and frequency.
- Sort macro usage using `vector<pair<>>` and `sort` with iterators.
- Output:
  - Number of macros
  - Number of instances
  - Total area excluding blocked macros
  - Top 10 frequently used macros
  - Instance names at 6 specific positions (100, 500, 1000, 8000, 15000, 20000)
  - Execution time

## Files Included

- `main.cpp` — Full program using STL to read, analyze, and output macro data.
- `x.lef` — Input file containing macro area data.
- `b17.def` — Input file containing macro instance data.
- `Problem.pdf` — Instructional prompt for the lab.

## STL Concepts Used

- `map` for key-value pairing of macro names to data.
- `set` for storing unique macros to exclude.
- `vector` for sorting and output.
- `iterator` for container traversal.
- STL algorithms like `sort`.

## Sample Output

```
LEF file name: x.lef
DEF file name: b17.def
Number of cell instances: 22568   Number of macros: 80
Total Area: 987654.321
The top 10 frequently used macros:
        NAND2_X1  1234
         INV_X1   1150
         ...
Instances at locations 100, 500, 1000, 8000, 15000, and 20000 respectively:
   100: U100
   500: U500
  1000: U1000
  8000: U8000
 15000: U15000
 20000: U20000

Runtime: 2 seconds
```

