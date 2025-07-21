# Week 10 – Polymorphism for Shapes Part 1 (CP112)

This lab explores the concept of **polymorphism** and **abstract classes** by implementing a class hierarchy of geometric shapes: `Triangle`, `Rectangle`, and `Circle`. All shape classes inherit from an abstract base class `Shape` which defines the core interface via pure virtual functions.

## Tasks

You are required to:

1. Implement the following classes, inheriting from `Shape`:
   - `Triangle`
   - `Rectangle`
   - `Circle`

2. Each class must override the following pure virtual functions:
   - `area()`: Calculate and return the shape's area
   - `perimeter()`: Calculate and return the shape's perimeter
   - `inside(const Pt&)`: Determine if a given point lies inside the shape
   - `degenerate()`: Return `true` if the shape is degenerated (e.g. zero area)
   - `print()`: Display the shape's details

3. Implement a `Pt` (Point) class for 2D coordinate representation.

4. Use **dynamic binding** to call overridden functions via base class pointers.

5. Use **downcasting** (`dynamic_cast`) to check the actual derived type and print shape classification (circle, rectangle, triangle).

6. Only modify the three lines in `main.cpp` marked with `**`. Do not modify other parts of `main.cpp`.

## Output Behavior

The program iterates over a vector of `Shape*` objects, invokes their `print()`, and tests whether a specific point lies inside them. It also identifies the runtime type of each shape.

### Sample Output (Excerpt)

```
Triangle: (1, 2) (5, 8) (-2, 10)
Area: 17
Perimeter: 24.3866
(1.5, 4) is inside this shape.
### This shape is a triangle.

Circle: 10 (0, 0)
Area: 314.159
Perimeter: 62.8319
(1.5, 4) is inside this shape.
### This shape is a circle.

Rectangle: (1, 2) (1, 2)
Area: 0
Perimeter: 0
This shape is degenerated.
(1.5, 4) is outside this shape.
This shape is a rectangle.
```


## Key Concepts

- Abstract classes and pure virtual functions
- Runtime polymorphism via base class pointers
- Downcasting using `dynamic_cast`
- Shape classification based on geometric properties
- Object-oriented design in C++

## Files Included

- `main.cpp` — Driver file (with only 3 modifiable lines)
- `Shape.h` — Abstract class and `Pt` class definition
- `Shape.cpp` — Implementations of `Triangle`, `Rectangle`, and `Circle`
- `Problem.pdf` — Full lab description and grading notes
