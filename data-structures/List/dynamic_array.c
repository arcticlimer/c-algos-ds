#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
  int capacity;
  int *data;
} DynamicArray;

// Helper functions
DynamicArray *init_array();                       // O(1)
DynamicArray *from_array(int *array, int length); // O(n)
void free_array(DynamicArray *dyn);               // O(1)
void _dynamic_array_realloc(DynamicArray *dyn);   // O(1)

// List ADT API
void push(DynamicArray *dyn, int data);            // O(1)
void insert(DynamicArray *dyn, int data, int idx); // O(n)
void delete (DynamicArray *dyn, int idx);          // O(n)
inline int at(DynamicArray *dyn, int idx);         // O(1)

// Extras
void show(DynamicArray *dyn);    // O(n)
void reverse(DynamicArray *dyn); // O(n)

int main() {
  DynamicArray *dyn = init_array();

  for (int i = 0; i <= 10; i++) {
    push(dyn, i);
  }

  // Insertion/Deletion
  printf("Before deleting at position 2\n");
  show(dyn);
  delete (dyn, 2);
  printf("After deleting at position 2\n");
  show(dyn);
  printf("Before inserting 777 at position 2\n");
  show(dyn);
  insert(dyn, 777, 2);
  printf("After inserting 777 at position 2\n");
  show(dyn);

  // Reversing
  puts("after reversing array");
  reverse(dyn);
  show(dyn);

  free_array(dyn);
}

DynamicArray *init_array() {
  DynamicArray *dyn = malloc(sizeof(DynamicArray));
  dyn->length = 0;
  dyn->capacity = 32;
  dyn->data = malloc(32 * sizeof(int));
  /* dyn = (DynamicArray*){ */
  /*     .length = 0, .capacity = 32, .data = malloc(32 * sizeof(int))}; */
  return dyn;
}

void _dynamic_array_realloc(DynamicArray *dyn) {
  // Reallocate the array with double capacity
  dyn->capacity *= 2;
  dyn->data = realloc(dyn->data, dyn->capacity * sizeof(int));
}

void push(DynamicArray *dyn, int data) {
  if (dyn->length == dyn->capacity) {
    _dynamic_array_realloc(dyn);
  }
  // Assign item to the end of the array and increase its length
  dyn->data[dyn->length++] = data;
}

void insert(DynamicArray *dyn, int data, int idx) {
  if (dyn->length == dyn->capacity) {
    _dynamic_array_realloc(dyn);
  }

  // Iterate in reverse shifting items to the left
  for (int i = dyn->length - 1; i >= idx; i--) {
    dyn->data[i + 1] = dyn->data[i];
  }
  // Assign new item to array and increase its length
  dyn->data[idx] = data;
  dyn->length++;
}

void delete (DynamicArray *dyn, int idx) {
  // Shifting elements to the right, overwriting element at `idx` and decreasing
  // its length
  for (int i = idx; i < dyn->length; i++) {
    dyn->data[i] = dyn->data[i + 1];
  }
  dyn->length--;
}

void reverse(DynamicArray *dyn) {
  int *new_buffer = malloc(sizeof(int) * dyn->capacity);

  for (int i = dyn->length; i >= 0; i--) {
    new_buffer[dyn->length - i - 1] = at(dyn, i);
  }

  free(dyn->data);
  dyn->data = new_buffer;
}

void show(DynamicArray *dyn) {
  // Iterate through the elements and print them
  printf("[");
  for (int i = 0; i < dyn->length - 1; i++) {
    printf("%d, ", dyn->data[i]);
  }
  printf("%d]\n", dyn->data[dyn->length - 1]);
}

DynamicArray *from_array(int *array, int length) {
  DynamicArray *dyn = init_array();

  for (int i = 0; i < length; i++) {
    push(dyn, array[i]);
  }

  return dyn;
}

void free_array(DynamicArray *dyn) {
  free(dyn->data);
  dyn->data = NULL;

  free(dyn);
  dyn = NULL;
}

inline int at(DynamicArray *dyn, int idx) { return dyn->data[idx]; }
