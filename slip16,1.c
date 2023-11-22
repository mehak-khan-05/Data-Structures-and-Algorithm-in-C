#include <stdio.h>

void counting_sort(int arr[], int n) {
    int max = arr[0], min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;

    int count[range];
    int output[n];

    // Initialize count array with zeros
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Update count array to store the position of each element
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void recursive_counting_sort(int arr[], int low, int high) {
    if (low < high) {
        counting_sort(arr + low, high - low + 1);
        recursive_counting_sort(arr, low, high - 1);
    }
}

int main() {
    int n;

    // Get input from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using recursive Counting Sort
    recursive_counting_sort(arr, 0, n - 1);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
