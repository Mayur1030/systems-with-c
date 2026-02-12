#include "editor_lib.h"

/* Remove trailing newline from string */
void chomp(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }
}

/* Append a line to the end of the linked list */
ll_text *append_text(ll_text *list, char *text) {
    ll_text *new_node = malloc(sizeof(ll_text));
    new_node->text = strdup(text);
    new_node->next = NULL;

    if (!list) return new_node;

    ll_text *cur = list;
    while (cur->next) cur = cur->next;
    cur->next = new_node;
    return list;
}

/* Insert a line at a given position */
ll_text *insert_text(ll_text *list, char *text, int position) {
    ll_text *new_node = malloc(sizeof(ll_text));
    new_node->text = strdup(text);
    new_node->next = NULL;

    if (position == 0) {
        new_node->next = list;
        return new_node;
    }

    ll_text *cur = list;
    for (int i = 0; cur && i < position - 1; i++) cur = cur->next;

    if (!cur) {
        free(new_node->text);
        free(new_node);
        return list;
    }

    new_node->next = cur->next;
    cur->next = new_node;
    return list;
}

/* Delete a line at a given position */
ll_text *delete_text(ll_text *list, int position) {
    if (!list) return NULL;

    ll_text *cur = list;
    if (position == 0) {
        list = cur->next;
        free(cur->text);
        free(cur);
        return list;
    }

    for (int i = 0; cur->next && i < position - 1; i++) cur = cur->next;
    if (!cur->next) return list;

    ll_text *to_delete = cur->next;
    cur->next = to_delete->next;
    free(to_delete->text);
    free(to_delete);
    return list;
}

/* Replace text at a given position */
ll_text *replace_text(ll_text *list, char *text, int position) {
    ll_text *cur = list;
    for (int i = 0; cur && i < position; i++) cur = cur->next;
    if (!cur) return list;

    free(cur->text);
    cur->text = strdup(text);
    return list;
}

/* Duplicate a linked list */
ll_text *duplicate_ll_text(ll_text *list) {
    if (!list) return NULL;
    ll_text *new_list = NULL;
    ll_text *cur = list;
    while (cur) {
        new_list = append_text(new_list, cur->text);
        cur = cur->next;
    }
    return new_list;
}

/* Return the length of a linked list */
int ll_text_length(ll_text *list) {
    int len = 0;
    ll_text *cur = list;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return len;
}

/* Push duplicate of top of stack */
ll_text_stack *push_duplicate(ll_text_stack *stack) {
    ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
    new_stack->lines = duplicate_ll_text(stack ? stack->lines : NULL);
    new_stack->next = stack;
    return new_stack;
}

/* Push an empty list onto stack */
ll_text_stack *push_empty(ll_text_stack *stack) {
    ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
    new_stack->lines = NULL;
    new_stack->next = stack;
    return new_stack;
}

/* Pop the top of stack */
ll_text_stack *pop_stack(ll_text_stack *stack) {
    if (!stack) return NULL;
    ll_text_stack *next_stack = stack->next;

    ll_text *cur = stack->lines;
    while (cur) {
        ll_text *tmp = cur;
        cur = cur->next;
        free(tmp->text);
        free(tmp);
    }
    free(stack);
    return next_stack;
}

/* Create a new empty stack */
ll_text_stack *new_stack_empty_text(void) {
    ll_text_stack *stack = malloc(sizeof(ll_text_stack));
    stack->lines = NULL;
    stack->next = NULL;
    return stack;
}

/* Save linked list to file */
int save_to_file(ll_text *list, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return 0;

    ll_text *cur = list;
    while (cur) {
        fprintf(f, "%s\n", cur->text);
        cur = cur->next;
    }
    fclose(f);
    return 1;
}

/* Load file into stack (single node) */
ll_text_stack *load_from_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return new_stack_empty_text();

    ll_text_stack *stack = new_stack_empty_text();
    char buf[1024];
    while (fgets(buf, sizeof(buf), f)) {
        chomp(buf);
        stack->lines = append_text(stack->lines, buf);
    }
    fclose(f);
    return stack;
}

