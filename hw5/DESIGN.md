# HW5 Design Document
CSE 13S – Winter 2026  
Homework 5: Wordle

## Overview

This assignment implements a simplified version of Wordle in C.
A secret 5-letter word is chosen from a dictionary, and the user
enters guesses until the correct word is found.

For each guess, the program returns feedback for each letter:
- Green: correct letter in the correct position
- Yellow: letter appears in the word but in a different position
- Gray: letter does not appear in the word

The program validates guesses, compares them to the secret word,
and continues until the user wins.

---

## validate_guess

Purpose:
Checks whether a guess is valid.

A guess is valid if:
- It has exactly 5 characters
- All characters are lowercase letters a–z
- The word exists in the dictionary

Pseudocode:


Time complexity: O(n) where n is the number of words in the dictionary.

---

## compare_guess

Purpose:
Compares the guess to the secret word and determines feedback
for each position.

Rules:
- If guess[i] == secret[i] → green
- Else if guess[i] appears anywhere in secret → yellow
- Else → gray

Pseudocode:


This runs in constant time since the word length is fixed at 5.

---

## Data Structures

Dictionary:
- Stored as `char **`
- Each word is a dynamically allocated string

Response:
- Can be stored as a 5-character array or dynamically allocated array
- Stores the color result for each letter

---

## Memory Management Plan

Dynamic memory may be allocated for:
- The dictionary array
- Each individual word in the dictionary
- Any dynamically created response arrays

Before the program exits:
- Free each word in the dictionary
- Free the dictionary array
- Free any other allocated memory

Valgrind will be used to confirm there are no memory leaks:


The goal is to have 0 bytes definitely lost.

---

## Error Handling

The program checks for:
- Invalid guess length
- Invalid characters
- Guess not in dictionary
- Failed memory allocation (malloc returning NULL)

If an error occurs, the program prints a message to stderr
and continues or exits appropriately.

---

## Testing Plan

Testing includes:
- Valid guesses
- Invalid guesses (wrong length or invalid characters)
- Words not in dictionary
- Immediate correct guess
- Multiple guesses before success
- Running Valgrind to ensure no memory leaks

