#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
  int *data;
  int index;
  int capacity;
} Stack;

Stack *init_stack(int);
void free_stack(Stack *);
void show_stack(Stack *);
void push(Stack *, int);
int pop(Stack *);
bool is_empty(Stack *);

#endif // !STACK_H
