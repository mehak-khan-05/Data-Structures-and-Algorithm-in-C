#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arr[], int n) {
    int i, j, min_index;

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int n;

    // Input: Size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Array with a fixed size (no dynamic allocation)
    int arr[n];

   

    // Input: Array elements (randomly generated)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random integers between 0 and 99
    }

    // Print original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting using selection sort
    selectionSort(arr, n);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
