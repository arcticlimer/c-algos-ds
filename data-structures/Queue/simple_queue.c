#include "simple_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue *queue = init_queue();
  print_list(queue->list);
  enqueue(queue, 1);
  print_list(queue->list);
  enqueue(queue, 2);
  print_list(queue->list);
  enqueue(queue, 3);
  print_list(queue->list);
  printf("First of the queue: %d\n", dequeue(queue));
  print_list(queue->list);
  enqueue(queue, dequeue(queue));
  print_list(queue->list);
}

Queue *init_queue() {
  Queue *queue = malloc(sizeof(Queue));
  queue->list = init_list();
  return queue;
}

void free_queue(Queue *queue) {
  free_list(queue->list);
  free(queue);
  queue = NULL;
}

void enqueue(Queue *queue, int data) { push_back(queue->list, data); }

int dequeue(Queue *queue) {
  int data = at(queue->list, 0);
  remove_elem(queue->list, 0);
  return data;
}
