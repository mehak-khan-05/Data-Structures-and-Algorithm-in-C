#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            // Find the index of the minimum element
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap elements without using a separate swapping function
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate a random array of integers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generating random integers between 0 and 99
    }

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform Selection Sort
    selectionSort(arr, n);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
