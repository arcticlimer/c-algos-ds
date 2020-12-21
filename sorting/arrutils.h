// Helper library for sorting algorithms in this folder

#ifndef ARRUTILS_H
#define ARRUTILS_H

#include <stdlib.h>
#include <stdio.h>

// Creates an array on `len` size, fills it with random numbers
// and returns a reference to it.
int *random_array(int len) {
    // Seeding the randomizer
    srand(time(NULL));

    int *arr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) arr[i] = rand();
    return arr;
}

// Prints an array items until `arr[threshold]`
void print_array(int arr[], int threshold) {
    for (int i = 0; i < threshold; i++) printf("%d, ", arr[i]);
}

int is_sorted(int arr[], int len) {
    // Track last item
    int li = -1;

    // If the current array item is lesser than the previous,
    // the array is not sorted.
    for (int i = 0; i < len; i++) {
        if(arr[i] < li) return 0;
        li = arr[i];
    }
    return 1;
}

#endif
