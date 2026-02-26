# HW6 Design Document  
## Wordle Solver – Strings, Searching, Pointers

### Overview

In this assignment, I am implementing a Wordle solver in C. The solver maintains a dynamically allocated vocabulary (an array of `char *` pointers) and iteratively narrows the search space based on feedback from guesses.

At each step, the solver selects the word with the highest heuristic score. The score of a word is computed based on how frequently its unique letters appear across the remaining vocabulary. After each guess, the vocabulary is reduced according to the response pattern ('g', 'y', 'x').

All implementation work is done in `search_util.c`. I will also write unit tests in `search_util_test.c` to verify correctness of each function.

---

### Letter Scoring Function

**Purpose:**  
Compute how many words in the current vocabulary contain a given letter.

**Design:**  
- Iterate through the vocabulary (`char **vocab`).
- Skip any NULL pointers (these represent eliminated words).
- For each word, check if the letter appears at least once.
- If it does, increment a counter.
- Return the total count.

**Pseudocode:**

function eliminate_gray(letter, vocabulary):
    for each word in vocabulary:
        if word is not NULL:
            if letter appears in word:
                free(word)
                set pointer to NULL

---

## Eliminating Words – Yellow Response

Purpose:
Remove words that either:
- Do not contain the letter
- Contain the letter in the guessed position

Pseudocode:

function eliminate_yellow(letter, position, vocabulary):
    for each word in vocabulary:
        if word is not NULL:

            if letter does NOT appear in word:
                free(word)
                set pointer to NULL

            else if word[position] == letter:
                free(word)
                set pointer to NULL

---

## Eliminating Words – Green Response

Purpose:
Keep only words that contain the correct letter in the correct position.

Pseudocode:

function eliminate_green(letter, position, vocabulary):
    for each word in vocabulary:
        if word is not NULL:
            if word[position] != letter:
                free(word)
                set pointer to NULL

---

## Memory Management Plan

The vocabulary is stored as a dynamically allocated char ** array. Each element is a dynamically allocated string.

When eliminating words, I free the individual string and set its pointer to NULL so other functions can safely skip it.

At program termination:
- Iterate through vocabulary
- Free any remaining non-NULL strings
- Free the outer char ** array

I will use Valgrind to verify that no memory leaks occur:

valgrind --leak-check=full ./solver rinse

---

## Testing Plan

I will write unit tests in search_util_test.c to verify:

- score_letter correctly counts letter occurrences
- score_word correctly ignores duplicate letters
- best_word selects the highest scoring word
- eliminate_gray removes words with the specified letter
- eliminate_yellow removes words correctly based on position
- eliminate_green keeps only correct-position words

Each function will be tested independently with small sample vocabularies.

EOF
