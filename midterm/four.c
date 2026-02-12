#include <stdlib.h>
#include <stddef.h>
#include "midterm.h"

// PROBLEM 4
size_t *count_characters(char *s, char *count_these, size_t num_characters) {
    size_t *result = malloc(num_characters * sizeof(size_t));
    if (result == NULL) {
        return NULL; // allocation failed
    }

    // Initialize counts to 0
    for (size_t i = 0; i < num_characters; i++) {
        result[i] = 0;
    }

    // Count each character
    for (size_t i = 0; s[i] != '\0'; i++) {
        for (size_t j = 0; j < num_characters; j++) {
            if (s[i] == count_these[j]) {
                result[j]++;
            }
        }
    }

    return result;
}

