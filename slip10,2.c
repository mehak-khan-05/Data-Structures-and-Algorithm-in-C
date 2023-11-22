#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char name[50];
    // Add other employee details if needed
} Employee;

void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(Employee arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j].name, arr[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() {
    FILE *file;
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    // Open the file
    file = fopen("employee.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read data from the file
    while (fscanf(file, "%s", employees[numEmployees].name) != EOF) {
        // Assuming each line in the file contains only the employee name
        numEmployees++;
    }

    // Close the file
    fclose(file);

    // Sort the data using Bubble Sort
    bubbleSort(employees, numEmployees);

    // Print the sorted data
    printf("Sorted Data using Bubble Sort:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s\n", employees[i].name);
    }

    // Sort the data using Selection Sort
    selectionSort(employees, numEmployees);

    // Print the sorted data
    printf("\nSorted Data using Selection Sort:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s\n", employees[i].name);
    }

    return 0;
}
