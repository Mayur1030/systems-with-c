# Homework 4: Design Document

  * author: Mayur Rajan
  * date: February 2026

## introduction

In this homework, I will build the very greatest text editing application that I
have ever made for CSE 13s, in my whole life.

TODO(you): 

## function 1: append_text
I will allocate a new ll_text node and copy the given text into it using strdup.
If the list is empty, the new node becomes the head. Otherwise, I will traverse
to the end of the list and attach the new node.

## function 2: insert_text
I will allocate a new node, copy the text, and insert it at the given position.
If the position is 0, the new node becomes the new head. Otherwise, I will
walk the list to the correct spot and insert the node there.

## function 3: delete_text
I will traverse to the node at the specified position and remove it.
I will make sure the previous node points to the next node, and free the
deleted node and its text.

## function 4: replace_text
I will go to the specified node, free its current text, and strdup the
new text into that node.

## function 5: duplicate_ll_text
I will create a new list, iterating through the original list and copying
each node and its text into the new list.

## function 6: ll_text_length
I will traverse the list, counting nodes, and return the count.
If the list is NULL, I will return 0.

## function 7: push_duplicate
I will duplicate the linked list at the top of the stack, allocate a new
stack node, and push it to the front.

## function 8: push_empty
I will allocate a new stack node with an empty linked list and push it
onto the front of the stack.

## function 9: pop_stack
I will remove the top stack node, free all its linked list nodes and text,
and return the new top of the stack (or NULL if empty).

