# Week 11 – Polymorphism for Shapes Part 2 (CP112)

This lab builds upon the previous week's polymorphic shape implementation by extending the abstract class `Shape` and introducing **shape intersection logic** and a new shape type: `Line`.

## Tasks

You are required to:

1. Add a new **pure virtual function** to the `Shape` class:
   ```cpp
   virtual bool intersection(const Shape*) const = 0;
   ```

2. Implement the `intersection()` function in all shape subclasses:
- `Triangle`
- `Rectangle`
- `Circle`
- `Line` (new class for Week 11)

3. Implement the new `Line` class:
- Inherit from `Shape`
- Represented by two endpoints (`Pt`)
- Must override all pure virtual functions including `intersection()`

4. Do not modify the `main.cpp` file.
5. Ensure that the program correctly reports intersections between all shape objects.

## Output Behavior
The program compares every shape against all others and prints whether or not they intersect.

Sample Output (Format)
```yaml
0, 0: Yes.
0, 1: Yes.
0, 2: No.
...
8, 8: Yes.

```

## Key Concepts
- Extending abstract base classes with additional virtual methods
- Implementing `intersection()` logic for each shape type
- Creating new shape types (`Line`) under the same polymorphic interface
- Runtime polymorphism via base class pointers
- Maintaining full compatibility with existing unmodified main program

## Files Included
- `main.cpp` — Driver file (must not be modified)
- `Shape.h` — Abstract base class, including the new `intersection()` pure virtual method
- `Shape.cpp` — Implementations of:
  - `Triangle`
  - `Rectangle`
  - `Circle`
  - `Line`
- `Problem.pdf` — Full lab description and evaluation rubric
