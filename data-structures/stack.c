#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int stack__pop(struct Node **stack);
void stack__push(struct Node **stack, int value);
void stack__display(struct Node *stack);

int main() {
    struct Node *stack = malloc(sizeof(struct Node));
    stack__push(&stack, 29);
    stack__display(stack);
    stack__push(&stack, 28);
    stack__display(stack);
    printf("Popped: %d\n", stack__pop(&stack));
    stack__display(stack);
    return 0;
}


int stack__pop(struct Node **stack) {
    struct Node *tmp;
    int data = (*stack)->data;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return data;
}


void stack__push(struct Node **stack, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
}


void stack__display(struct Node *stack) {
    while(stack->next) {
        printf("%d, ", stack->data);
        stack = stack->next;
    }
    puts("");
}
