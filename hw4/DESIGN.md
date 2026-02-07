# HW4 Design Document

**Author:** mrajan1  
**Course:** CSE 13S, Winter 2026  

---

## Overview

HW4 involves building a basic text editor in C that supports appending, inserting, deleting, and replacing lines of text, as well as undo functionality. The editor stores text as a linked list of lines (`ll_text`) and uses a stack of these lists (`ll_text_stack`) to manage undo operations.

The design emphasizes modularity, memory safety, and clarity in handling linked lists and stacks. Each function is planned to perform its task efficiently while avoiding memory leaks.

---

## Data Structures

1. **`ll_text` (linked list of lines)**  
   - **Fields:**  
     - `text` — a null-terminated string storing the content of the line.  
     - `next` — pointer to the next line, or `NULL` if it’s the last line.  
   - **Reasoning:** Allows dynamic storage of text lines and efficient insertion, deletion, and traversal.

2. **`ll_text_stack` (stack for undo functionality)**  
   - **Fields:**  
     - `list` — pointer to an `ll_text` representing one editor state.  
     - `next` — pointer to the next stack entry.  
   - **Reasoning:** Every editing operation pushes a copy of the current linked list onto the stack. Undo operations pop the stack to restore the previous state.

---

## Functions

### `ll_text *append_text(ll_text *list, char *text)`  
- **Purpose:** Add a new line at the end of the list.  
- **Plan:** Traverse to the last node, allocate a new node, copy `text` using `strdup`, link it, and return the front of the list.

### `ll_text *insert_text(ll_text *list, char *text, int position)`  
- **Purpose:** Insert a new line at a specified position.  
- **Plan:** If `position == 0`, make the new node the head. Otherwise, traverse to the node before the position, insert a new node, copy `text` with `strdup`, and return the updated list.

### `ll_text *delete_text(ll_text *list, int position)`  
- **Purpose:** Delete the line at a given position.  
- **Plan:** Traverse to the node before the target, unlink and free the target node and its `text`, return the updated front of the list.

### `ll_text *replace_text(ll_text *list, char *text, int position)`  
- **Purpose:** Replace the text of a line at a specific position.  
- **Plan:** Traverse to the node, free the existing `text`, copy the new `text` with `strdup`, return the list.

### `ll_text *duplicate_ll_text(ll_text *list)`  
- **Purpose:** Create a deep copy of a linked list.  
- **Plan:** Iterate through the original list, allocate new nodes, copy each `text` using `strdup`, link nodes in order, return the new list.

### `int ll_text_length(ll_text *list)`  
- **Purpose:** Compute the number of lines in the list.  
- **Plan:** Traverse the list, counting nodes until `NULL` is reached, return the count.

### `ll_text_stack *push_duplicate(ll_text_stack *stack)`  
- **Purpose:** Push a duplicate of the top linked list onto the stack.  
- **Plan:** Duplicate the top `ll_text` using `duplicate_ll_text`, allocate a new stack node, set its `list` to the duplicate, link it to the current stack, and return the new stack top.

### `ll_text_stack *push_empty(ll_text_stack *stack)`  
- **Purpose:** Push an empty list onto the stack.  
- **Plan:** Allocate a new stack node with `list = NULL`, link it to the current stack, return the new stack top.

### `ll_text_stack *pop_stack(ll_text_stack *stack)`  
- **Purpose:** Remove the top stack entry and free all associated memory.  
- **Plan:** Free the top `ll_text` list and the stack node, return the next stack entry (or `NULL` if the stack is empty).

---

## Algorithm / Logic

1. **Input Handling:** Open the file, read line by line, and create an initial linked list.  
2. **Editing Operations:** Each append, insert, delete, or replace operation modifies a copy of the current linked list and pushes it onto the stack.  
3. **Undo Operations:** Pop the top of the stack to revert to the previous state, freeing the removed linked list to avoid memory leaks.  
4. **Output Generation:** Print or save the text from the front of the current `ll_text` list.

---

## Testing Strategy

- **Unit Testing:** Test each function individually using small linked lists.  
- **Integration Testing:** Run the full editor, perform sequences of edits, and verify stack behavior.  
- **Edge Cases:** Empty file, inserting at position 0, deleting the last line, undoing the first operation.  
- **Tools:** Use Valgrind to detect memory leaks, and `diff` to compare output files with expected results.

---

## Notes

- Assumptions: Input text lines will not exceed 1024 characters unless extended.  
- Memory Management: All `strdup` and `malloc` allocations will be freed appropriately.  
- Enhancements: Once all functions are correct, optional features like search or longer lines may be added without changing library function signatures.

