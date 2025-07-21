# Week 4 – Queue Class: Task Scheduling (CP112)

This project implements a custom `Queue` class to simulate task scheduling based on arriving and ideal execution orders. It uses linked list implementation and models CPU task execution timing.

## Tasks

You are required to:

1. Define the `Queue` class in `Queue.h` and implement it in `Queue.cpp`.
2. Write logic in `main.cpp` to:
   - Compare arriving task order with ideal task order
   - Reschedule mismatched tasks to the back of the queue
   - Track total time taken based on execution or rescheduling
3. Ensure correct usage of constructors and destructors for dynamic memory management.

## Input Format

- Line 1: Size of the queue
- Line 2: Number of test cases
- For each test case:
  - Line 1: Number of tasks in ideal order
  - Line 2: Number of tasks in arriving list
  - Line 3: Arriving order (space-separated)
  - Line 4: Ideal order (space-separated)

## Output Format

For each test case:
- *** Test: `<test_number>`
- -- Total Time: `<seconds>`


## Time Calculation Rules

- Executing a task takes **3 seconds**
- Rescheduling a task (moving to back of queue) takes **2 seconds**

## Key Concepts

- Linked list implementation of queue (with `frontPtr` and `rearPtr`)
- Enqueue, dequeue, peek, isFull, isEmpty logic
- Task scheduling based on queue manipulation
- Dynamic memory handling and destructor logic

## Files Included

- `main.cpp` — Logic to process task orders and calculate total time
- `Queue.h` — Queue class definition
- `Queue.cpp` — Queue method implementations
- `Problem.pdf` — Lab description and constraints

## Notes

- All printouts such as queue creation and destruction messages are expected.
- Ensure `main.cpp`, `Queue.h`, and `Queue.cpp` are cleanly separated.
- Your implementation must match the class interface and naming exactly.

