# Computer Systems and C Programming (CSE 13S)

This repository contains a collection of systems programming projects developed in C, focusing on low-level memory management, data structures, and Unix-style utility development. 

## Technical Overview
The projects in this repository demonstrate proficiency in:
* **C Programming:** Implementation of core algorithms and utilities using the C11 standard.
* **Memory Management:** Rigorous use of `malloc`, `calloc`, and `realloc` with validation via **Valgrind** to ensure zero memory leaks.
* **Data Structures:** Custom implementations of Linked Lists, Stacks, and dynamic arrays.
* **Systems Programming:** File I/O operations, string manipulation, and function pointers for modular design.
* **Tooling & Workflow:** Automated builds using **Makefiles**, version control with Git, and adherence to consistent style guidelines via `clang-format`.

## Key Projects

### Persistent Text Editor (`hw4`)
A functional command-line text editor featuring an **Undo** system.
* **Architecture:** Uses a linked list of strings to represent lines of text.
* **State Management:** Implements a stack-based state machine that captures "snapshots" of the document, allowing for robust multi-level undo functionality.
* **Skills:** Deep-copying complex data structures, pointer manipulation, and interactive CLI design.

### Wordle Game Engine (`hw5`)
A C implementation of the popular word-guessing game.
* **Core Logic:** Developed a feedback engine that provides real-time character-level hints (Correct, Present, Absent).
* **Resource Management:** Focuses on dynamic dictionary loading and efficient string searching within a large vocabulary.

### Functional Programming in C (`hw3`)
Implementation of higher-order functions, specifically a generic `reduce` (fold) operation.
* **Abstraction:** Leveraged function pointers to create reusable logic for array processing (e.g., calculating dot products, finding maximums, and conditional summing).
* **String Utilities:** Includes custom implementations for suffix checking, string repetition, and case-insensitive palindrome detection.

### Command-Line Calculator (`hw2`)
A file-driven expression evaluator.
* **Features:** Supports basic arithmetic operations and error handling (e.g., division by zero).
* **Algorithms:** Includes an implementation of the Collatz Conjecture to demonstrate recursive vs. iterative problem-solving.

### Unix Utility Clones (`hw1`)
* **caat:** A specialized version of the standard `cat` utility with custom character-processing logic, demonstrating basic stream I/O and character manipulation.

## Development Methodology
Each project followed a structured development lifecycle:
1. **Design Phase:** Creation of comprehensive `DESIGN.md` documents outlining architectural choices and implementation strategies.
2. **Implementation:** Modular coding with a focus on readability and performance.
3. **Verification:** Extensive testing using custom test suites and memory analysis tools.

---
*Developed as part of the CSE 13S curriculum at UC Santa Cruz.*
