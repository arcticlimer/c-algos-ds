#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define ARRAY_SIZE 11

struct Node *ll__from_array(int *data_array, int len);
void ll__display(struct Node *list);
void ll__push(struct Node **head, int value);
void ll__unshift(struct Node **head, int value);
int ll__shift(struct Node *head);
int ll__pop(struct Node *head);
int ll__find(struct Node *node, int value);
int ll__at(struct Node *node, int at);
void ll__insert(struct Node **head, int at, int value);
void ll__reverse(struct Node **head);
void ll__delete(struct Node **head, int value);
void ll__free(struct Node *head);

int main() {
    int array[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct Node *ll = ll__from_array(array, ARRAY_SIZE);

    // Testing the linked list
    ll__display(ll);
    ll__push(&ll, 777);
    ll__display(ll);
    ll__unshift(&ll, 4231);
    ll__display(ll);
    printf("Popped: %d\n", ll__pop(ll));
    ll__display(ll);
    ll__insert(&ll, 5, 1337);
    ll__display(ll);
    ll__delete(&ll, 1337);
    ll__display(ll);
    ll__reverse(&ll);
    ll__display(ll);
    ll__pop(ll);
    ll__display(ll);
    printf("Shifted: %d\n", ll__shift(ll));
    ll__display(ll);
    printf("The value 6 is at index %d\n", ll__find(ll, 6));
    printf("The item at index 9 is %d\n", ll__at(ll, 9));
    ll__free(ll);
    return 0;
}


struct Node {
    int data;
    struct Node* next;
};


struct Node *ll__from_array(int data_array[], int len) {
    struct Node *head = NULL;

    // Start a head and push a new node to it for each array item
    for(int i = 0; i < len; i++)
        ll__push(&head, data_array[i]);

    return head;
}


void ll__push(struct Node **head, int value) {
   struct Node *node = malloc(sizeof(struct Node));
    node->data = value;

    if (*head == NULL) *head = node;
    // Traverse the list and add the new node to the end
    else {
        struct Node *tmp_ptr = *head;
        while(tmp_ptr->next != NULL)
            tmp_ptr = tmp_ptr->next;

        tmp_ptr->next = node;
    }
}


void ll__unshift(struct Node **head, int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = *head;
    *head = node;
}


void ll__insert(struct Node **head, int at, int value) {
    // Create a new node and add the value to it
    struct Node *node = malloc(sizeof(struct Node)), *tmp_ptr = *head;
    node->data = value;

    // Go at the given position on the linked list and append the node
    while(at-- -1) {
        tmp_ptr = tmp_ptr->next;
    }
    node->next = tmp_ptr->next;
    tmp_ptr->next = node;
}

// Deletes the first occurence of `target` on the list
void ll__delete(struct Node **head, int target) {
    struct Node *tmp_ptr = *head, *prev;

    while(tmp_ptr->next != NULL) {
        if (tmp_ptr->data == target) {
            prev->next = tmp_ptr->next;
            free(tmp_ptr);
        }
        prev = tmp_ptr;
        tmp_ptr = tmp_ptr->next;
    }
}


void ll__free(struct Node *head) {
    while(head->next != NULL) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
}


int ll__pop(struct Node *head) {
    struct Node *tmp_ptr = head, *prev;

    while(tmp_ptr->next != NULL) {
        prev = tmp_ptr;
        tmp_ptr = tmp_ptr->next;
    }

    // Retrieve the last item of the linked list
    int data = tmp_ptr->data;
    // Removes the last item from the linked list,
    // free it and returns the data.
    prev->next = NULL;
    free(tmp_ptr);
    return data;
}


int ll__shift(struct Node *head) {
    int value = head->data;
    (*head) = *head->next;
    return value;
}


int ll__find(struct Node *head, int value) {
    int i = 0;
    while(head->next != NULL) {
        if (head->data == value) return i;
        head = head->next;
        i++;
    }
    return -1;
}


int ll__at(struct Node *head, int at) {
    while(at--) {
        head = head->next;
    }
    return head->data;
}


void ll__reverse(struct Node **head) {
    struct Node *prev = NULL,
                *current = *head,
                *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


void ll__display(struct Node *ll) {
    while(ll != NULL) {
        printf(" %d ->", ll->data);
        ll = ll->next;
    }
    printf(" NULL\n");
}
