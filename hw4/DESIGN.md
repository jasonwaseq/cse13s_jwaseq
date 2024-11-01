# Homework 4: Design Document

  * author: Jason Waseq
  * date: October 30, 2024

## introduction

TODO: Write 9 functions that deal with stacks, linked lists, and I/O.

## function 1: ll_text *append_text(ll_text *list, char *text)

The append_text function appends a new node containing a copy of the specified text to the end of a linked list. 
If the list is empty, the function returns the new node as the head of the list; otherwise, it traverses to the end, appends the new node, and returns the unchanged head of the list.

## function 2: ll_text *insert_text(ll_text *list, char *text, int position)

The insert_text function inserts a new node with a copy of the specified text at a given position in a linked list. 
If the position is 0, the new node becomes the head of the list; otherwise, the function traverses to the specified position, inserts the new node, and returns the unchanged head of the list.

## function 3: ll_text *delete_text(ll_text *list, int position)

The delete_text function deletes a node at the specified position in a linked list. 
If the node at position 0 is deleted, the head of the list is updated; otherwise, the function links the previous node to the deleted node's successor. 
It returns the new head of the list, and if the list becomes empty, it returns NULL.

## function 4: ll_text *replace_text(ll_text *list, char *text, int position)

The replace_text function replaces the text at a specified position in a linked list. 
It traverses to the node at the given position, frees the existing text, and replaces it with a copy of the new text using strdup. 
The function returns the unchanged head of the list after modifying the specified node.

## function 5: ll_text *duplicate_ll_text(ll_text *list)

The duplicate_ll_text function creates a complete copy of a given ll_text linked list, including all of its text entries. 
It allocates new memory for each node and its associated text, linking them together to form a new list that is independent of the original. 
The function returns the head of the duplicated list.

## function 6: int ll_text_length(ll_text *list)

The ll_text_length function calculates and returns the length of a given linked list by traversing each node and counting them. 
If the list is NULL, indicating it is empty, the function returns 0.

## function 7: ll_text_stack *push_duplicate(ll_text_stack *stack)

The push_duplicate function adds a new entry to the top of a stack of linked lists by creating a complete copy of the linked list currently at the top of the stack. 
It allocates a new stack entry, duplicates the linked list using the duplicate_ll_text function, and links the new entry to the existing stack, returning the new top of the stack.

## function 8: ll_text_stack *push_empty(ll_text_stack *stack)

The push_empty function creates a new empty entry at the top of a specified stack by allocating memory for a new stack entry and setting its linked list pointer to NULL, indicating that it contains no text. 
It links this new entry to the existing stack and returns a pointer to the new top of the stack.

## function 9: ll_text_stack *pop_stack(ll_text_stack *stack)

The pop_stack function removes the top entry from a specified stack and frees all associated memory, including the linked list contained in that entry. 
If the stack becomes empty as a result of this operation, it returns NULL; otherwise, it returns a pointer to the new top of the stack.

