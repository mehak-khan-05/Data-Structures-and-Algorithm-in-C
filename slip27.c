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

// Counting Sort
void countingSort(Employee arr[], int n) {
    const int MAX_AGE = 100;  // Assuming a maximum age, adjust as needed
    Employee output[n];
    int count[MAX_AGE + 1];

    // Initialize count array
    for (int i = 0; i <= MAX_AGE; i++) {
    count[i] = 0;
}


    // Count the occurrences of each age
    for (int i = 0; i < n; i++) {
        count[arr[i].age]++;
    }

    // Compute cumulative count
    for (int i = 1; i <= MAX_AGE; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].age] - 1] = arr[i];
        count[arr[i].age]--;
    }

    // Copy the output array back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Quick Sort
int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].age;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].age <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSortHelper(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(Employee arr[], int low, int high) {
    quickSortHelper(arr, low, high);
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
        if (L[i].age <= R[j].age) {
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

int main() {
    const char *filename = "employee.txt";
    const int MAX_EMPLOYEES = 100;

    // Read data from file
    Employee employees[MAX_EMPLOYEES];
    int n = readData(employees, filename);

    // Counting Sort
    countingSort(employees, n);

      // ... (previous code)

    // Write sorted data to 'sortedemponage_counting.txt'
    writeData(employees, n, "sortedemponage_counting.txt");

    // Quick Sort (for comparison-based sorting)
    quickSort(employees, 0, n - 1);

    // Write sorted data to 'sortedemponage_quick.txt'
    writeData(employees, n, "sortedemponage_quick.txt");

    // Merge Sort
    mergeSort(employees, 0, n - 1);

    // Write sorted data to 'sortedemponage_merge.txt'
    writeData(employees, n, "sortedemponage_merge.txt");

    return 0;
}

