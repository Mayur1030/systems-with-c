#include "editor_lib.h"
#include <stdio.h>

int main(void) {
    ll_text_stack *stack = new_stack_empty_text();

    // Add a few lines
    stack->lines = append_text(stack->lines, "Hello, world!");
    stack->lines = append_text(stack->lines, "This is CSE 13S.");
    stack->lines = append_text(stack->lines, "Homework 4 is fun!");

    // Print list
    printf("Current text:\n");
    ll_text *cur = stack->lines;
    while (cur) {
        printf("%s\n", cur->text);
        cur = cur->next;
    }

    // Duplicate stack
    ll_text_stack *stack2 = push_duplicate(stack);
    printf("\nDuplicated stack first line: %s\n", stack2->lines->text);

    // Replace a line
    stack->lines = replace_text(stack->lines, "Hello, C!", 0);
    printf("\nAfter replace:\n");
    cur = stack->lines;
    while (cur) {
        printf("%s\n", cur->text);
        cur = cur->next;
    }

    // Pop stack
    stack = pop_stack(stack);
    stack2 = pop_stack(stack2);

    return 0;
}

