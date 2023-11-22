#include <stdio.h>
#include <stdlib.h>


// Function to perform linear search
int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;  // Return the position if found
        }
    }
    return -1;  // Return -1 if not found
}

void generate(int arr[],int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generating random integers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    

    int n, x;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Generate a random array of integers
    // printf("Random Array: ");
    // for (int i = 0; i < n; i++) {
    //     arr[i] = rand() % 100;  // Generating random integers between 0 and 99
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    generate(arr,n);

    // Get the value to search from the user
    printf("Enter the value to search: ");
    scanf("%d", &x);

    // Perform linear search
    int position = linearSearch(arr, n, x);

    // Display the result
    if (position != -1) {
        printf("The value %d is present at position %d.\n", x, position + 1);
    } else {
        printf("The value %d is not present in the array.\n", x);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
