# Homework 3: Design Document

  * author: Mayur Rajan
  * date: January 2026

## introduction

In this homework, we implemented seven functions that work with strings, arrays, and function pointers. The goal was to practice manipulating strings, using dynamic memory allocation, computing with arrays, and understanding functional programming concepts like `reduce`.

---

## 1. `str_suffix(char *haystack, char *needle)`
**Purpose:** Determine if `needle` is a suffix of `haystack`.  

**Approach:**  
- Compute the lengths of `haystack` and `needle`.  
- If `needle` is longer than `haystack`, return `false`.  
- Otherwise, compare the last `needle_len` characters of `haystack` with `needle`.  
- Implemented iteratively with a simple for-loop.  

**Memory:** No dynamic allocation needed.  

---

## 2. `str_repeat(char *s, int n)`
**Purpose:** Return a new string that repeats `s` `n` times.  

**Approach:**  
- Compute the length of `s`.  
- Allocate memory for `len(s) * n + 1` characters.  
- Use a loop to copy `s` into the result `n` times.  
- Ensure the final string is null-terminated.  
- If `n` is 0, return an empty string.  

**Memory:** Caller is responsible for freeing the allocated memory.  

---

## 3. `str_is_palindrome(char *s)`
**Purpose:** Check if a string is a palindrome, ignoring non-letter characters and case.  

**Approach:**  
- Allocate scratch space equal to the length of `s`.  
- Copy only ASCII letters into scratch space and convert to lowercase.  
- Use two pointers (`left` and `right`) to check characters from both ends.  
- Free scratch space before returning.  
- Empty strings or strings with no letters count as palindromes.  

**Memory:** Properly frees scratch space to avoid leaks.  

---

## 4. `dot_product(float *vec_a, float *vec_b, int length)`
**Purpose:** Compute the dot product of two float arrays of the same length.  

**Approach:**  
- Initialize a sum to 0.  
- Loop through each element, multiplying corresponding elements and adding to sum.  
- Return the sum.  

**Memory:** No dynamic allocation needed.  

---

## 5. `reduce(int *nums, int length, int (*f)(int, int), int initial)`
**Purpose:** General-purpose reduction over an array with a binary function.  

**Approach:**  
- Initialize accumulator to `initial`.  
- Loop through the array, updating accumulator as `acc = f(acc, nums[i])`.  
- Return accumulator at the end.  

**Memory:** No dynamic allocation needed.  

---

## 6. `maximum_with_reduce(int *nums, int length)`
**Purpose:** Find the maximum element using `reduce`.  

**Approach:**  
- Implement helper function `max_helper(a, b)` that returns the larger of two integers.  
- Call `reduce` with `max_helper` and `INT_MIN` as the initial value.  

**Memory:** No dynamic allocation needed.  

---

## 7. `sum_positive_with_reduce(int *nums, int length)`
**Purpose:** Compute the sum of positive elements using `reduce`.  

**Approach:**  
- Implement helper function `sum_positive_helper(acc, x)` that adds `x` to `acc` only if `x > 0`.  
- Call `reduce` with `sum_positive_helper` and 0 as the initial value.  

**Memory:** No dynamic allocation needed.  

---

## Summary
This homework reinforces:

- String manipulation and memory allocation.  
- Use of loops and conditionals for checking suffixes and palindromes.  
- Array operations and simple functional programming with `reduce`.  
- Writing helper functions for modularity and reusability.  
- Proper memory management to avoid leaks.  

All functions were implemented in `hw3.c` and tested using `hw3_test.c`.
