
# push_swap

## Introduction

The `push_swap` project is designed to sort integers using two stacks, `a` and `b`, following specific operations. This README provides an overview of the mandatory part, requirements, and implementation details.

## Objectives

The goal is to sort a stack of integers into ascending order with the minimum number of operations. The operations allowed are:

- **sa**: Swap the first two elements of stack `a`.
- **sb**: Swap the first two elements of stack `b`.
- **ss**: Perform `sa` and `sb` simultaneously.
- **pa**: Push the top element of stack `b` to stack `a`.
- **pb**: Push the top element of stack `a` to stack `b`.
- **ra**: Rotate stack `a` (move the top element to the bottom).
- **rb**: Rotate stack `b` (move the top element to the bottom).
- **rr**: Perform `ra` and `rb` simultaneously.
- **rra**: Reverse rotate stack `a` (move the bottom element to the top).
- **rrb**: Reverse rotate stack `b` (move the bottom element to the top).
- **rrr**: Perform `rra` and `rrb` simultaneously.

## Program Details

- **Program Name**: `push_swap`
- **Files to Submit**: `Makefile`, `*.h`, `*.c`
- **Makefile Rules**:
  - `NAME`: Name of the program.
  - `all`: Build the program.
  - `clean`: Remove object files.
  - `fclean`: Remove object files and the executable.
  - `re`: Rebuild the program.

## Usage

Run the program with a list of integers as arguments. The first argument should be the top of stack `a`.

```bash
./push_swap 2 1 3 6 5 8
```
## Example
For the input:
./push_swap 2 1 3 6 5 8

## The output might be:
sa
pb
pb
pb
sa
pa
pa
pa

## Error Handling
If there are non-integer arguments or duplicates, the program will output Error.
If no arguments are provided, the program will not output anything.

## Benchmark
To achieve a minimal grade (80%), sort 100 random numbers in fewer than 700 operations.
For maximal validation, sort 500 random numbers with no more than 5500 operations.

## External Functions
- read, write, malloc, free, exit
- ft_printf or equivalent
- Functions from the math library (-lm option)
- Functions from MiniLibX

Additional Information
Global variables are forbidden.
Make sure to handle errors gracefully and free all allocated memory.

## Author
NUILED
Feel free to adjust any part of this README to better fit your project's specifics or personal style!