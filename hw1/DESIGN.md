# Homework 1: Design Document

  * author: Mayur Rajan
  * date: January 2026

## introduction

In this homework, I will do the thing and solve important computer science
problems and probably win a
[Turing Award](https://en.wikipedia.org/wiki/Turing_Award) for doing so.

TODO(you): The purpose of this homework is to practice writing simple functions in C and structuring code across multiple files. We also implemented a small program (`caat.c`) that manipulates input characters. This exercise helps reinforce modular programming and using header files.

## function 1: area_of_disk
*Purpose:** Compute the area of a disk given its radius.  
**Implementation:**  
- Formula: `area = π * radius^2`  
- Used the `M_PI` constant from `<math.h>`  
- Returns a `double`  
- Assumes radius is positive  

---

## function 2: area_of_ring
**Purpose:** Compute the area of a ring (disk with a hole) given outer and inner radii.  
**Implementation:**  
- Uses `area_of_disk` for both outer and inner radii  
- Returns `area_of_ring = area_outer - area_inner`  
- Works for any positive outer and inner radii  

---

## function 3: bigger_minus_smaller
**Purpose:** Return the difference between the larger and smaller of two integers.  
**Implementation:**  
- Compare `a` and `b`  
- Return `a - b` if `a` is larger, else `b - a`  
- Handles negative numbers correctly  

---

## function 4: value_in_range
**Purpose:** Determine whether a value lies in a given inclusive range `[lower_bound, upper_bound]`.  
**Implementation:**  
- Returns `true` if `lower_bound <= x <= upper_bound`, `false` otherwise  
- Uses a simple Boolean expression

---

## function 5: sum_of_greater_squares
**Purpose:** Compute the sum of the squares of the two largest integers out of three.  
**Implementation:**  
- Squares `a`, `b`, and `c`  
- Finds the smallest square and excludes it  
- Returns the sum of the other two squares  
- Works correctly even if numbers are negative 

  
## the caat program
**Purpose:** Read characters from standard input and print them to standard output, doubling vowels.  
**Implementation:**  
- Uses `getchar()` to read each character  
- Uses `putchar()` to print each character  
- If the character is a vowel (`a e i o u` or uppercase), print it **twice**  
- Stops processing at EOF  
- Does not produce any extra output  
