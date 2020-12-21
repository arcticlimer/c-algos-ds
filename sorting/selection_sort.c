#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "arrutils.h"

#define ARR_SIZE 100000

void selection_sort(int *arr, int len);

int main() {
    clock_t start, end;
    start = clock();

    int *array = random_array(ARR_SIZE);

    // Sort the array and stops the timer
    selection_sort(array, ARR_SIZE);
    end = clock();
    // Assert our array is sorted
    assert(is_sorted(array, ARR_SIZE));

    printf("The array was sorted in %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}

// Selection sort is a simple O(n²) algorithm.
// https://en.wikipedia.org/wiki/Selection_sort
void selection_sort(int arr[], int len) {
    // Going through each item on the array
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        // Pass through each item of the array
        // and check if it's lesser than the current minimum.
        // If it is, it become the new `min` value.
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        if (min != i) {
            // Swapping a[i] and a[min] values
            int tmp = *(arr + i);
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}