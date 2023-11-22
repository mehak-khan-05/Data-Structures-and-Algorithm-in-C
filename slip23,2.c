#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct city {
    char name[20];
    int code;
} city;

// Function to read from file
int fileread(city a[20]) {
    FILE *fp;
    int i = 0;
    fp = fopen("cities.txt", "r");
    if (fp == NULL) {
        printf("File Not Exist\n");
    } else {
        while (fscanf(fp, "%s%d", a[i].name, &a[i].code) != EOF) {
            i++;
        }
        fclose(fp);
    }
    return i;
}

// Function to compare two cities for sorting
// Comparison function for sorting cities based on names
int compareCities(const void *a, const void *b) {
    // Compare the names of two cities and return the result
    return strcmp(((const city *)a)->name, ((const city *)b)->name);
}


// Binary Search function
void binarySearch(city a[20], int n) {
    char str[20];
    printf("Enter city: ");
    scanf("%s", str);

    // Sorting the array based on city names
    qsort(a, n, sizeof(city), compareCities);

    // Binary Search
    int low = 0, high = n - 1, mid, index = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(str, a[mid].name) == 0) {
            index = mid;
            break;
        } else if (strcmp(str, a[mid].name) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (index != -1) {
        printf("City Code: %d\n", a[index].code);
    } else {
        printf("City Not in list\n");
    }
}

int main() {
    int n;
    city a[20];

    n = fileread(a);

    // Displaying records
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].name, a[i].code);
    }

    // Performing binary search
    binarySearch(a, n);

    return 0;
}
