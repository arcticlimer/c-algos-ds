#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// int main() {
// DoublyLinkedList *list = init_list();
// push_front(list, 10);
// push_front(list, 20);
// push_back(list, 30);
// push_back(list, 40);
// push_front(list, 50);
// push_back(list, 60);
// print_list(list);
// insert(list, 5, 25);
// print_list(list);
// remove_elem(list, 0);
// print_list(list);
// printf("%d\n", at(list, 5));
// free_list(list);
// }

DoublyLinkedList *init_list() {
  DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
  list->tail = NULL;
  list->head = NULL;
  list->length = 0;
  return list;
}

void free_list(DoublyLinkedList *list) {
  Node *head = list->head;

  while (head != NULL) {
    Node *old_head = head;
    head = head->next;
    free_node(old_head);
  }

  free(list);
  list = NULL;
}

void free_node(Node *node) {
  free(node);
  node = NULL;
}

void print_list(DoublyLinkedList *list) {
  Node *head = list->head;
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

void push_front(DoublyLinkedList *list, int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->prev = NULL;
  node->next = list->head;

  if (list->head != NULL) {
    list->head->prev = node;
  }

  list->head = node;

  if (list->tail == NULL) {
    list->tail = node;
  }

  list->length++;
}

void push_back(DoublyLinkedList *list, int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->prev = list->tail;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
  }

  if (list->tail != NULL) {
    list->tail->next = node;
  }

  list->tail = node;
  list->length++;
}

void insert(DoublyLinkedList *list, int position, int data) {
  Node *head = list->head;

  if (position == 0) {
    return push_front(list, data);
  } else if (position >= list->length) {
    return push_back(list, data);
  }

  if (position < list->length) {
    while (--position) {
      head = head->next;
    }

    if (head != NULL) {
      Node *target = malloc(sizeof(Node));
      target->data = data;
      target->prev = head;
      target->next = head->next;
      head->next = target;
      if (target->next != NULL) {
        target->next->prev = target;
      }
      list->length++;
    }
  }
}

void remove_elem(DoublyLinkedList *list, int position) {
  Node *head = list->head;

  if (position == 0) {
    list->head = head->next;
    free_node(head);
    return;
  }

  if (head != NULL) {
    while (position-- > 0) {
      head = head->next;
    }

    if (head != NULL) {
      head->prev->next = head->next;
      free_node(head);
    }

    list->length--;
  }
}

int at(DoublyLinkedList *list, int position) {
  Node *head = list->head;

  if (head != NULL) {
    while (position--) {
      head = head->next;
    }

    if (head != NULL) {
      return head->data;
    }
  }

  return 99999999;
}
