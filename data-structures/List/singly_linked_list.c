#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int length;
} LinkedList;

// Helper functions
LinkedList *from_array(int *buffer, int size); // O(n)
void free_list(LinkedList *list);              // O(n)
void free_node(Node *node);                    // O(1)

// List ADT API
void push(LinkedList *list, int data);                 // O(1)
void remove_elem(LinkedList *list, int position);      // O(n)
void insert(LinkedList *list, int position, int data); // O(n)
void show(LinkedList *list);                           // O(n)
int length(LinkedList *list);                          // O(1)
int at(LinkedList *list, int position);                // O(n)

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
  free_list(list);
}

LinkedList *from_array(int *buffer, int size) {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->length = 0;

  for (int i = 0; i < size; i++) {
    push(list, buffer[i]);
  }

  return list;
}

void push(LinkedList *list, int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = list->head;
  list->head = node;
  list->length++;
}

void insert(LinkedList *list, int position, int data) {
  Node *head = list->head;

  for (int i = 0; i < position - 1; i++) {
    if (head != NULL) {
      head = head->next;
    }
  }

  if (head != NULL) {
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

  if (head != NULL && head->next != NULL) {
    head->next = head->next->next;
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
    printf("%d, ", head->data);
    head = head->next;
  }
  printf("]\n");
}

void free_list(LinkedList *list) {
  Node *head = list->head;

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
