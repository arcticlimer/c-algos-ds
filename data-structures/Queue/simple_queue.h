#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H

#include "../List/doubly_linked_list.h"

typedef struct {
  DoublyLinkedList *list;
} Queue;

Queue *init_queue();
void free_queue(Queue *);

void enqueue(Queue *, int);
int dequeue(Queue *);

#endif // !SIMPLE_QUEUE_H
