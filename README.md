# push_swap

## Overview

`push_swap` is a program that efficiently sorts a list of numbers using two stacks and a constrained set of operations. It is designed to demonstrate algorithmic optimization by minimizing the number of instructions required to achieve the sorted state. This project is an excellent exercise in algorithm design, problem-solving, and efficient use of data structures.

## Features
- Sorting using two stacks (`stack_a` and `stack_b`).
- A limited set of operations, such as `sa` (swap), `pa` (push to stack_a), `pb` (push to stack_b), `ra` (rotate), etc.
- Optimized sorting algorithms tailored for different input sizes.
- Error handling for invalid input and memory management.

## How It Works
The program:
1. Reads input numbers from the command line.
2. Validates and parses the input into a usable format.
3. Initializes two stacks: `stack_a` (containing the numbers) and `stack_b` (initially empty).
4. Uses the `push_swap` function to determine the optimal sequence of operations to sort the numbers.
5. Outputs the sequence of operations.

## Usage
### Compilation
Compile the program using `make`:
```bash
make
```

### Running the Program
To sort a list of numbers:
```bash
./push_swap 3 2 1
```
Example output:
```
pb
ra
pa
```

### Constraints
The program must:
- Accept only integers as input.
- Handle duplicates and invalid input gracefully.
- Minimize the number of operations.

## Algorithms
### Small Input
For inputs of size 3 to 5, a brute force method is used.

### Larger Input
For larger inputs, advanced algorithms like the partitioning method are implemented to reduce complexity.

## Error Handling
The program checks for:
- Non-integer values.
- Duplicate numbers.
- Memory allocation failures.

Upon error, a message is displayed, and resources are cleaned up.

## License
This project is released under the MIT License.

