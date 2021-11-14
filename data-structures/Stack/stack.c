#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack *stack = init_stack(5);
  printf("%d\n", pop(stack));
  printf("%d\n", is_empty(stack));
  push(stack, 1);
  push(stack, 2);
  show_stack(stack);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  show_stack(stack);
  pop(stack);
  show_stack(stack);
  pop(stack);
  printf("%d\n", is_empty(stack));
  show_stack(stack);
  free_stack(stack);
}

Stack *init_stack(int capacity) {
  int *stack_data = malloc(sizeof(int) * capacity);
  Stack *stack = malloc(sizeof(Stack));

  stack->capacity = capacity;
  stack->index = 0;
  stack->data = stack_data;

  return stack;
}

bool is_empty(Stack *stack) {
  return stack->index == 0;
}

void push(Stack *stack, int data) {
  if (stack->index < stack->capacity) {
    stack->data[stack->index++] = data;
  }
}

int pop(Stack *stack) {
  if (stack->index > 0) {
    return stack->data[stack->index--];
  }

  return 99999999;
}

void show_stack(Stack *stack) {
  for (int i = 0; i < stack->index; i++) {
    printf("%d ", stack->data[i]);
  }
    printf("\n");
}

void free_stack(Stack *stack) {
  free(stack->data);
  free(stack);
  stack = NULL;
}
