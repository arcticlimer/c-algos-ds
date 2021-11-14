#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  int data;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int length;
} DoublyLinkedList;

DoublyLinkedList *init_list();           // O(1)
void free_list(DoublyLinkedList *list);  // O(n)
void free_node(Node *node);              // O(1)
void print_list(DoublyLinkedList *list); // O(n)

void push_front(DoublyLinkedList *list, int data);           // O(1)
void push_back(DoublyLinkedList *list, int data);            // O(1)
void insert(DoublyLinkedList *list, int position, int data); // O(n)
void remove_elem(DoublyLinkedList *list, int position);      // O(n)
int at(DoublyLinkedList *list, int position);                // O(n)

#endif // !DOUBLY_LINKED_LIST_H
