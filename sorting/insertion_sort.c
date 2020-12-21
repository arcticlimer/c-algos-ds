#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "arrutils.h"

#define ARR_SIZE 100000

void insertion_sort(int arr[], int len);

int main() {
    clock_t start, end;
    start = clock();

    int *array = random_array(ARR_SIZE);

    // Sort the array and stops the timer
    insertion_sort(array, ARR_SIZE);
    end = clock();
    // Assert our array is sorted
    assert(is_sorted(array, ARR_SIZE));

    printf("The array was sorted in %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}

// Insertion sort is a simple O(n²) sorting algorithm.
// https://en.wikipedia.org/wiki/Insertion_sort#Algorithm
void insertion_sort(int arr[], int len) {
    int idx = 1;
    while (idx < len) {
        int tmp = arr[idx];
        int current = idx - 1;
        // Shift the values that are also greater than the tmp
        while (current >= 0 && arr[current] > tmp) {
            arr[current + 1] = arr[current];
            current--;
        }
        //  Inserts it into the array and go to next array item
        arr[current + 1] = tmp;
        idx++;
    }
}
