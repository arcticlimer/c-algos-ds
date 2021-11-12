#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
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
int at(LinkedList *list, int position);                // O(n)
int length(LinkedList *list);                          // O(1)

// Extras
void show(LinkedList *list);    // O(n)
void reverse(LinkedList *list); // O(n)

#endif // !SINGLY_LINKED_LIST_H
