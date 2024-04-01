#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "../types.h"

// Function to create a new node
node_t *create_node(int data)
{
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  if (newNode == NULL)
  {
    fprintf(stderr, "Memory allocation failed in function create_node in linked_list.c\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data)
{
  node_t *newNode = create_node(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a new node at the end of the list
void insert_at_end(node_t **head, int data)
{
  node_t *newNode = create_node(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  node_t *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to print the elements of the list
void print_list(node_t *head)
{
  node_t *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to delete a node by value
void delete_node_by_value(node_t **head, int value)
{
  node_t *temp = *head;
  node_t *prev = NULL;

  if (temp != NULL && temp->data == value)
  {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != value)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;
  free(temp);
}

// Function to delete a node by reference
void delete_node_by_reference(node_t **head, node_t *node_to_delete)
{
  if (*head == NULL || node_to_delete == NULL)
    return;

  if (*head == node_to_delete)
  {
    *head = node_to_delete->next;
    free(node_to_delete);
    return;
  }

  node_t *current = *head;
  node_t *prev = NULL;
  while (current != NULL && current != node_to_delete)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
    return;

  prev->next = current->next;
  free(current);
}

// Function to delete the entire list
void delete_list(node_t **head)
{
  node_t *current = *head;
  node_t *next;
  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

// #### Example usage ####
// int main()
// {
//   node_t *head = NULL;

//   // Insert some elements
//   insert_at_end(&head, 10);
//   insert_at_end(&head, 20);
//   insert_at_end(&head, 30);

//   // Print the list
//   printf("Linked List: ");
//   print_list(head);

//   // Delete an element
//   delete_node_by_value(&head, 20);

//   // Print the modified list
//   printf("Linked List after deletion: ");
//   print_list(head);

//   // Delete the entire list
//   delete_list(&head);

//   return 0;
// }
