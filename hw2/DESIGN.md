# Homework 2: Design Document

  * author: Mayur Rajan
  * date: January 2026

## introduction

In this homework, I implemented several functions that manipulate numbers and arrays,
and a small calculator program that reads arithmetic instructions from a file.
I also explored the relationship between arrays and pointers in C.

TODO(you): write something sensible here.

## Functions

### next_collatz_number
This function computes the next number in the Collatz sequence.
If the input is even, it returns n/2; if odd, it returns 3n + 1.

### count_collatz_steps
This function counts the number of steps needed to reach 1
in the Collatz sequence. I implemented it iteratively using a while loop,
calling `next_collatz_number` repeatedly.

### maximum
This function returns the largest element of an integer array.
I looped through the array using a for loop and kept track of the maximum value.

### sum_positive
This function sums all positive elements in an integer array.
I looped through the array and added elements only if they were greater than 0.

### count_negative
This function counts the number of negative elements in an integer array.
I looped through the array and incremented a counter each time an element was less than 0.

## Calculator Program

The calculator reads numbers and operators from a file.
The first line is the initial number, followed by alternating operator and number lines.
I read each line into a buffer, removed newlines, and converted numbers using `strtol`.
I then applied the operations in order, checking for divide-by-zero.
If a division by zero occurs, the program prints "ERROR".
Otherwise, it prints the final result.

