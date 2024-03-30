#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../types.h"

// Function to create a new node
node_t *create_node(int data);

// Function to insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data);

// Function to insert a new node at the end of the list
void insert_at_end(node_t **head, int data);

// Function to print the elements of the list
void print_list(node_t *head);

// Function to delete a node by value
void delete_node_by_value(node_t **head, int key);

// Function to delete a node by reference
void delete_node_by_reference(node_t **head, node_t *node_to_delete);

// Function to delete the entire list
void delete_list(node_t **head);

#endif