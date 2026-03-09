# Homework 7 Design Document
CSE 13S – Hash Tables, Sets, I/O and Strings

## Overview

This program implements a small search engine for the Twenty Newsgroups dataset. The program reads a collection of Usenet posts, builds an index of terms appearing in the posts, and allows the user to perform searches on those terms.

Two main hash tables are used:

1. **MetadataLookupTable** – maps a message_id to the metadata for a post.
2. **TermLookupTable** – maps each term to a set of message_ids containing that term.

When the program starts, it reads all posts, extracts terms from each post, and builds the inverted index. After the index is built, the program enters an interactive loop where the user can perform AND queries, OR queries, display posts, or quit.

The set of message IDs associated with each term is implemented using a **binary search tree (string_set)**.

---

## String Utility Functions

### lowercase

This function converts all characters in a string to lowercase.

Plan:
- Iterate through each character of the string.
- Use `tolower()` from `ctype.h`.
- Modify the string in place.

Pseudocode:


---

### startswith

This function checks whether a string starts with a given prefix.

Plan:
- Compare characters from both strings.
- Continue until the prefix ends or a mismatch occurs.

Pseudocode:


---

## String Set (Binary Search Tree)

The string_set is implemented as a **binary search tree**. Each node contains:

- a string
- a left pointer
- a right pointer

The tree stores strings in **alphabetical order**.

---

### add

Adds a string to the set.

Plan:
- If the node is NULL, create a new node.
- Compare the string with the current node’s string.
- Recursively insert into the correct subtree.
- If the string already exists, return the existing set.

Pseudocode:


---

### contains

Checks if a string exists in the set.

Pseudocode:


---

### set_union

Creates a new set containing all elements from both sets.

Plan:
- Create an empty set.
- Traverse the first set and add all elements.
- Traverse the second set and add all elements.

Pseudocode:


---

### set_intersection

Creates a new set containing only elements that appear in both sets.

Plan:
- Traverse one set.
- For each string, check if it exists in the other set.
- If it does, add it to the new set.

Pseudocode:


---

### free_set

Frees all memory associated with the set.

Plan:
- Recursively free the left and right subtrees.
- Free the string stored in the node.
- Free the node itself.

Pseudocode:


---

### list_entries

Creates a linked list of all strings in the set.

Plan:
- Traverse the tree.
- Add each string to a linked list.

Pseudocode:


---

## MetadataLookupTable

This table maps **message IDs to PostMetadata structures** using a hash table.

The hash table stores:
- message_id (key)
- PostMetadata struct (value)

---

### store_metadata

Stores a PostMetadata structure in the hash table.

Plan:
- Compute a hash from the message_id.
- Find the correct bucket.
- Allocate memory for a copy of the metadata.
- Insert it into the table.

Pseudocode:


---

### metadata_lookup

Looks up metadata by message_id.

Plan:
- Compute hash.
- Search the bucket for the message_id.
- Return pointer if found.

Pseudocode:


---

### free_metadata_lookup_table

Frees all metadata entries and the hash table itself.

Plan:
- Iterate through each bucket.
- Free all stored metadata.
- Free the table.

---

## TermLookupTable

This hash table maps **terms to sets of message IDs**.

Each entry contains:
- term (string key)
- string_set of message IDs

---

### add_message_id_to_term

Adds a message ID to the set for a term.

Plan:
- Compute hash for the term.
- Check if the term exists in the table.
- If not, create a new string_set.
- Add the message_id to the set.

Pseudocode:


---

### term_lookup

Returns the string_set associated with a term.

Plan:
- Compute hash.
- Search bucket.
- Return set if found.

Pseudocode:


---

### free_term_lookup_table

Frees all term entries and their associated sets.

Plan:
- Free each string_set.
- Free each term string.
- Free the table.

---

## Query Operations

Queries operate on linked lists of search terms.

---

### union_lookup (OR query)

Returns the union of all sets associated with the query terms.

Plan:
- Start with an empty set.
- For each term:
  - lookup the set
  - union it with the current result.

Pseudocode:

if term_set exists:
    result = union(result, term_set)


---

### intersection_lookup (AND query)

Returns the intersection of all sets associated with the query terms.

Plan:
- Start with the set for the first term.
- Intersect with sets for the remaining terms.

Pseudocode:

if term_set exists:
    result = intersection(result, term_set)


---

## Memory Management

The program uses dynamic memory allocation for:

- binary search tree nodes
- strings
- hash table entries
- metadata structures

To avoid memory leaks:

- Every allocated structure will have a corresponding `free` function.
- `free_set` will free BST nodes and strings.
- `free_metadata_lookup_table` frees all metadata.
- `free_term_lookup_table` frees term entries and their sets.

The program will be tested using **Valgrind** to ensure all allocated memory is properly freed.

Command used for testing:


This ensures the program has no memory leaks.
