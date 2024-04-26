#include "generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/** ll stands for linked list */

ll_node_t *malloc_node()
{
  ll_node_t *new_node = (ll_node_t *)malloc(sizeof(ll_node_t));
  if (new_node == NULL)
  {
    printf("ERROR: While trying to malloc a new node in generic linked list");
    exit(EXIT_FAILURE);
  }
  new_node->data = NULL;
  new_node->next = NULL;
  return new_node;
}

// Function to create a new node
ll_node_t *ll_create_node(void *new_data)
{
  ll_node_t *new_node = malloc_node();
  new_node->data = new_data;
  return new_node;
}

// Function to insert a new node at the beginning of the list
void ll_insert_at_beginning(ll_node_t **head, void *new_data)
{
  ll_node_t *new_node = ll_create_node(new_data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a new node at the end of the list
void ll_insert_at_end(ll_node_t **head, void *new_data)
{
  ll_node_t *new_node = ll_create_node(new_data);
  if (*head == NULL)
  {
    *head = new_node;
    return;
  }
  ll_node_t *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_node;
}

// Function to delete a node by reference
void ll_delete_node_by_reference(ll_node_t **head, ll_node_t *node_to_delete)
{
  if (*head == NULL || node_to_delete == NULL)
    return;

  if (*head == node_to_delete)
  {
    *head = node_to_delete->next;
    free(node_to_delete);
    return;
  }

  ll_node_t *current = *head;
  ll_node_t *prev = NULL;
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
void ll_delete_list(ll_node_t **head)
{
  ll_node_t *current = *head;
  ll_node_t *next;
  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

void ll_print_list(ll_node_t *head, void (*print_function)(void *))
{
  while (head != NULL)
  {
    (*print_function)(head->data);
    head = head->next;
  }
}

// // #### Example usage ####

// typedef struct {
//   int x;
//   int y;
// } test_t;

// void print_test_t_function(void *data) {
//   test_t value = *(test_t *)data;
//   printf("x: %d, y: %d\n", value.x, value.y);
// }

// int main()
// {
//   ll_node_t *head = NULL;

//   test_t *test_value = (test_t *)malloc(sizeof(test_t));
//   test_value->x = 10;
//   test_value->y = 1;

//   test_t *test_value_2 = (test_t *)malloc(sizeof(test_t));
//   test_value_2->x = 104;
//   test_value_2->y = 108;

//   // Insert some elements
//   insert_at_end(&head, test_value);
//   insert_at_end(&head, test_value_2);

//   // Print the list
//   printf("Linked List: \n");
//   print_list(head, print_test_t_function);

//   // Delete an element
//   delete_node_by_reference(&head, head);

//   // Print the modified list
//   printf("Linked List after deletion: \n");
//   print_list(head, print_test_t_function);

//   // Delete the entire list
//   delete_list(&head);

//   return 0;
// }
