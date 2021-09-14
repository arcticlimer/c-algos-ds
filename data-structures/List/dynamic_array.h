#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct DynamicArray {
  int length;
  int capacity;
  int *data;
} DynamicArray;

DynamicArray *init_array();                             // O(1)
DynamicArray *from_array(const int *array, int length); // O(n)
void free_array(DynamicArray *dyn);                     // O(1)
void _dynamic_array_realloc(DynamicArray *dyn);         // O(1)

// List ADT API
void push(DynamicArray *dyn, int data);            // O(1)
void delete_elem(DynamicArray *dyn, int idx);      // O(n)
void insert(DynamicArray *dyn, int data, int idx); // O(n)
inline int at(const DynamicArray *dyn, int idx);   // O(1)

// Extras
void show(const DynamicArray *dyn);         // O(n)
void reverse(DynamicArray *dyn);            // O(n)
void map(DynamicArray *dyn, int (*f)(int)); // O(n)

#endif // !DYNAMIC_ARRAY_H
