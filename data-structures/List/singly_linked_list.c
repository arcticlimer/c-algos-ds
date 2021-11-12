#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

int main() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  LinkedList *list = from_array(array, 10);
  push(list, 324);
  insert(list, 5, 777);
  show(list);
  remove_elem(list, 5);
  show(list);
  printf("element at position 5: %d\n", at(list, 5));
  printf("The size of the list is: %d\n", length(list));
  // TODO: reversing
  /* puts("Linked list after reversing"); */
  /* reverse(list); */
  /* show(list); */
  free_list(list);
}

LinkedList *from_array(int *buffer, int size) {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->length = 0;

  // Allocate a new list and for each element of the array, push it to the list.
  for (int i = 0; i < size; i++) {
    push(list, buffer[i]);
  }

  return list;
}

void push(LinkedList *list, int data) {
  Node *node = malloc(sizeof(Node));
  // We create a new node, make its next node be the actual list head and then
  // turn the list head into this new node.
  // old: 1 -> 2 -> 3 -> 4
  // new: 5 -> 1 -> 2 -> 3 -> 4
  node->data = data;
  node->next = list->head;
  list->head = node;
  list->length++;
}

void insert(LinkedList *list, int position, int data) {
  Node *head = list->head;

  // We go advance the list until the index `position`
  for (int i = 0; i < position - 1; i++) {
    if (head != NULL) {
      head = head->next;
    }
  }

  if (head != NULL) {
    // Do the same thing as `push`, but now with two nodes.
    Node *new_head = malloc(sizeof(Node));
    new_head->data = data;
    new_head->next = head->next;
    head->next = new_head;
    list->length++;
  }
}

void remove_elem(LinkedList *list, int position) {
  Node *head = list->head;

  for (int i = 0; i < position - 1; i++) {
    if (head != NULL) {
      head = head->next;
    }
  }

  // Pretty much the same as insert, but we now free the node at the index
  // `position` and set it to its `next` node.
  if (head != NULL && head->next != NULL) {
    Node *new_head = head->next->next;
    if (head->next != NULL) {
      free_node(head->next);
    }
    head->next = new_head;
    list->length--;
  }
}

int at(LinkedList *list, int position) {
  Node *head = list->head;

  for (int i = 0; i < position; i++) {
    if (head != NULL) {
      head = head->next;
    }
  }

  // Return this crazy value if there is nothing at the index
  int result = head != NULL ? head->data : -9999999;
  return result;
}

int length(LinkedList *list) { return list->length; }

void show(LinkedList *list) {
  Node *head = list->head;
  // TODO: Maybe make printing prettier
  printf("[");
  while (head != NULL) {
    printf("%d", head->data);
    head = head->next;

    if (head != NULL) {
      printf(" -> ");
    }
  }
  printf("]\n");
}

void free_list(LinkedList *list) {
  Node *head = list->head;

  // For each node, free it and after that free the allocated list.
  while (head != NULL) {
    Node *actual = head;
    head = actual->next;
    free_node(actual);
  }

  free(list);
  list = NULL;
}

void free_node(Node *node) {
  free(node);
  node = NULL;
}

void reverse(LinkedList *list) {
  // TODO
}
