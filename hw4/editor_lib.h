#ifndef EDITOR_LIB_H
#define EDITOR_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Linked list node for a line of text */
typedef struct ll_text {
    char *text;
    struct ll_text *next;
} ll_text;

/* Stack of linked lists */
typedef struct ll_text_stack {
    ll_text *lines;
    struct ll_text_stack *next;
} ll_text_stack;

/* Linked list functions */
ll_text *append_text(ll_text *list, char *text);
ll_text *insert_text(ll_text *list, char *text, int position);
ll_text *delete_text(ll_text *list, int position);
ll_text *replace_text(ll_text *list, char *text, int position);
ll_text *duplicate_ll_text(ll_text *list);
int ll_text_length(ll_text *list);

/* Stack functions */
ll_text_stack *push_duplicate(ll_text_stack *stack);
ll_text_stack *push_empty(ll_text_stack *stack);
ll_text_stack *pop_stack(ll_text_stack *stack);
ll_text_stack *new_stack_empty_text(void);

/* Utility functions */
void chomp(char *s);
int save_to_file(ll_text *list, const char *filename);
ll_text_stack *load_from_file(const char *filename);

#endif /* EDITOR_LIB_H */
