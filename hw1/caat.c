#include <stdio.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF) {  // Read one character at a time
        putchar(ch);                   // Output the character

        // Check if it's a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            putchar(ch);               // Output it again
        }
    }

    return 0;
}

