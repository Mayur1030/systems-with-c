#include "hw3.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

// ------------------ STRINGS ------------------

// Check if 'needle' is a suffix of 'haystack'
bool str_suffix(char *haystack, char *needle) {
    int hay_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len > hay_len) {
        return false;
    }

    int start = hay_len - needle_len;
    for (int i = 0; i < needle_len; i++) {
        if (haystack[start + i] != needle[i]) {
            return false;
        }
    }

    return true;
}

// Return a new string which is 's' repeated 'n' times
char *str_repeat(char *s, int n) {
    int len = strlen(s);

    if (n == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *result = malloc(len * n + 1);
    char *p = result;

    for (int i = 0; i < n; i++) {
        strcpy(p, s);
        p += len;
    }

    result[len * n] = '\0';
    return result;
}

// Check if string is a palindrome (ignore non-letters and case)
bool str_is_palindrome(char *s) {
    int len = strlen(s);
    char *clean = malloc(len + 1);
    int idx = 0;

    // Copy only letters and lowercase them
    for (int i = 0; i < len; i++) {
        if (isalpha((unsigned char)s[i])) {
            clean[idx++] = tolower((unsigned char)s[i]);
        }
    }
    clean[idx] = '\0';

    // Empty string or no letters counts as palindrome
    if (idx == 0) {
        free(clean);
        return true;
    }

    // Check palindrome
    int left = 0;
    int right = idx - 1;
    while (left < right) {
        if (clean[left] != clean[right]) {
            free(clean);
            return false;
        }
        left++;
        right--;
    }

    free(clean);
    return true;
}

// ------------------ ARRAYS ------------------

// Dot product of two float arrays
float dot_product(float *vec_a, float *vec_b, int length) {
    float sum = 0.0f;
    for (int i = 0; i < length; i++) {
        sum += vec_a[i] * vec_b[i];
    }
    return sum;
}

// ------------------ REDUCE ------------------

// General reduce function for int arrays
int reduce(int *nums, int length, int (*f)(int, int), int initial) {
    int acc = initial;
    for (int i = 0; i < length; i++) {
        acc = f(acc, nums[i]);
    }
    return acc;
}

// ------------------ MAXIMUM WITH REDUCE ------------------

// Helper for maximum_with_reduce
int max_helper(int a, int b) {
    return (a > b) ? a : b;
}

// Return maximum element using reduce
int maximum_with_reduce(int *nums, int length) {
    return reduce(nums, length, max_helper, INT_MIN);
}

// ------------------ SUM POSITIVE WITH REDUCE ------------------

// Helper for sum_positive_with_reduce
int sum_positive_helper(int acc, int x) {
    if (x > 0) {
        return acc + x;
    }
    return acc;
}

// Return sum of positive numbers using reduce
int sum_positive_with_reduce(int *nums, int length) {
    return reduce(nums, length, sum_positive_helper, 0);
}


