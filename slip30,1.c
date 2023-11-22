#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Employee;

// Function to read data from file
int readData(Employee employees[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d", employees[count].name, &employees[count].age) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to write data to file
void writeData(Employee employees[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d\n", employees[i].name, employees[i].age);
    }

    fclose(file);
}

// Function to swap two employees
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
        swap(&arr[i], &arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(Employee arr[], int n) {
    int i, j;
    Employee key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(Employee arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    Employee L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].name, R[j].name) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSortHelper(Employee arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void mergeSort(Employee arr[], int left, int right) {
    mergeSortHelper(arr, left, right);
}

// Counting Sort
void countingSort(Employee arr[], int n) {
    const int MAX_NAMES = 256;  // Assuming ASCII characters
    Employee output[n];
    int count[MAX_NAMES];

    // Initialize count array
    for (int i = 0; i <=MAX_NAMES; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each name
    for (int i = 0; i < n; i++) {
        count[arr[i].name[0]]++;
    }

    // Compute cumulative count
    for (int i = 1; i <=MAX_NAMES; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].name[0]] - 1] = arr[i];
        count[arr[i].name[0]]--;
    }

    // Copy the output array back to arr
    for (int i = 0; i <= n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    const char *filename = "employee.txt";
    const int MAX_EMPLOYEES = 100;

    // Read data from file
    Employee employees[MAX_EMPLOYEES];
    int n = readData(employees, filename);

    // Bubble Sort
    bubbleSort(employees, n);

    // Write sorted data to 'sortedemponnames_bubble.txt'
    writeData(employees, n, "sortedemponnames_bubble.txt");

    // Selection Sort
    selectionSort(employees, n);

    // Write sorted data to 'sortedemponnames_selection.txt'
    writeData(employees, n, "sortedemponnames_selection.txt");

    // Insertion Sort
    insertionSort(employees, n);

    // Write sorted data to 'sortedemponnames_insertion.txt'
    writeData(employees, n, "sortedemponnames_insertion.txt");

    // Merge Sort
    mergeSort(employees, 0, n - 1);

    // Write sorted data to 'sortedemponnames_merge.txt'
    writeData(employees, n, "sortedemponnames_merge.txt");

    // Counting Sort
    countingSort(employees, n);

    // Write sorted data to 'sortedemponnames_counting.txt'
    writeData(employees, n, "sortedemponnames_counting.txt");

    return 0;
}
