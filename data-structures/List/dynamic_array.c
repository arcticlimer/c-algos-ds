#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
  int capacity;
  int *data;
} DynamicArray;

// Helper functions
inline void free_array(DynamicArray *dyn);
void _dynamic_array_realloc(DynamicArray *dyn);
DynamicArray init_array();

// List ADT API
void push(DynamicArray *dyn, int data);            // O(1)
void insert(DynamicArray *dyn, int data, int idx); // O(n)
void delete (DynamicArray *dyn, int idx);          // O(n)
void show(DynamicArray *dyn);                      // O(n)
inline int at(DynamicArray *dyn, int idx);         // O(1)

int main() {
  DynamicArray dyn = init_array();

  for (int i = 0; i <= 10; i++) {
    push(&dyn, i);
  }

  printf("Before deleting at position 2\n");
  show(&dyn);
  delete (&dyn, 2);
  printf("After deleting at position 2\n");
  show(&dyn);

  printf("Before inserting 777 at position 2\n");
  show(&dyn);
  insert(&dyn, 777, 2);
  printf("After inserting 777 at position 2\n");
  show(&dyn);

  free_array(&dyn);
}

DynamicArray init_array() {
  return (DynamicArray){
      .length = 0, .capacity = 32, .data = malloc(32 * sizeof(int))};
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

void show(DynamicArray *dyn) {
  // Iterate through the elements and print them
  printf("[");
  for (int i = 0; i < dyn->length - 1; i++) {
    printf("%d, ", dyn->data[i]);
  }
  printf("%d]\n", dyn->data[dyn->length - 1]);
}

inline void free_array(DynamicArray *dyn) { free(dyn->data); }

inline int at(DynamicArray *dyn, int idx) { return dyn->data[idx]; }
