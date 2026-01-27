#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_newline(char *s, int maxsize) {
    for (int i = 0; i < maxsize && s[i]; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    const int BUFSIZE = 80;
    char buffer[BUFSIZE];
    FILE *infile = NULL;

    if (argc != 2) {
        fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
        return 1;
    }

    infile = fopen(argv[1], "r");
    if (!infile) {
        fprintf(stderr, "input file %s not found\n", argv[1]);
        return 1;
    }

    long result = 0;

    // Read first number
    if (!fgets(buffer, BUFSIZE, infile)) {
        printf("ERROR\n");
        return 1;
    }
    remove_newline(buffer, BUFSIZE);
    result = strtol(buffer, NULL, 10);

    // Process the rest of the file
    while (fgets(buffer, BUFSIZE, infile)) {
        char op[2];
        long num;

        // Operator line
        remove_newline(buffer, BUFSIZE);
        strncpy(op, buffer, 1);
        op[1] = '\0';

        // Number line
        if (!fgets(buffer, BUFSIZE, infile)) {
            printf("ERROR\n");
            return 1;
        }
        remove_newline(buffer, BUFSIZE);
        num = strtol(buffer, NULL, 10);

        // Perform operation
        if (strcmp(op, "+") == 0) {
            result += num;
        } else if (strcmp(op, "-") == 0) {
            result -= num;
        } else if (strcmp(op, "*") == 0) {
            result *= num;
        } else if (strcmp(op, "/") == 0) {
            if (num == 0) {
                printf("ERROR\n");
                fclose(infile);
                return 0;
            }
            result /= num;
        } else {
            printf("ERROR\n");
            fclose(infile);
            return 1;
        }
    }

    // Print final result
    printf("%ld\n", result);
    fclose(infile);
    return 0;
}

