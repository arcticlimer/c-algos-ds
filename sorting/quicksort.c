#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "arrutils.h"

#define ARR_SIZE 100000

void quicksort(int arr[], int  left, int right);
int _qs__partition(int arr[], int left, int right);
void _qs__swap(int *x, int *y);

int main() {
    clock_t start, end;
    start = clock();

    int *array = random_array(ARR_SIZE);

    // Sort the array and stops the timer
    quicksort(array, 0, ARR_SIZE - 1);
    end = clock();
    // Assert our array is sorted
    assert(is_sorted(array, ARR_SIZE));
    printf("The array was sorted in %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}

// Quicksort is a O(n log n) algorithm.
void quicksort(int arr[], int left, int right) {
    // We receive the left and right indexes of the array
    // If the array is not empty:
    if (left < right) {
        // Partition the array and recurses for both sides
        int partition_idx = _qs__partition(arr, left, right);

        quicksort(arr, left, partition_idx - 1);
        quicksort(arr, partition_idx + 1, right);
    }
}


int _qs__partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            _qs__swap(&arr[i], &arr[j]);
        }
    }
    _qs__swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Utility function for swapping values
void _qs__swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
