#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define HAYSTACK_LEN 10000

int binary_search(int *haistack, int size, int needle);
int *create_haystack(int len);

int main() {

    int *haystack = create_haystack(HAYSTACK_LEN);
    int needle = 1221;

    printf("%d\n", binary_search(haystack, HAYSTACK_LEN, needle));

    free(haystack);
    return 0;
}

// Binary search is a O(log n) algorithm to check if a needle exists in a haystack.
// https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm
int binary_search(int *haystack, int size, int needle) {
    int left_idx = 0;
    int right_idx = size - 1;

    while (left_idx <= right_idx) {
        int middle = floor((left_idx + right_idx) / 2);
        // If the current item is lesser than the needle, chop to the right.
        if (*(haystack + middle) < needle) {
            left_idx = middle + 1;
        }
        // If the current item is greater than the needle, chop to the left.
        else if (*(haystack + middle) > needle) {
            right_idx = middle - 1;
        }
        // If we found the item, return 1.
        else {
            return 1;
        }
    }
    // If the item is not found, return 0.
    return 0;
}

// Helper function to create a haystack of `len` size.
int *create_haystack(int len) {
    int *arr = malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++) *(arr + i) = i;
    return arr;
}
