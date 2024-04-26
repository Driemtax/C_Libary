#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

/** ll stands for linked list */

typedef struct Node
{
  void *data;
  struct Node *next;
} ll_node_t;

ll_node_t *malloc_node();

// Function to create a new node
ll_node_t *ll_create_node(void *new_data);

// Function to insert a new node at the beginning of the list
void ll_insert_at_beginning(ll_node_t **head, void *new_data);

// Function to insert a new node at the end of the list
void ll_insert_at_end(ll_node_t **head, void *new_data);

// Function to delete a node by reference
void ll_delete_node_by_reference(ll_node_t **head, ll_node_t *node_to_delete);

// Function to delete the entire list
void ll_delete_list(ll_node_t **head);

void ll_print_list(ll_node_t *head, void (*print_function)(void *));

#endif
