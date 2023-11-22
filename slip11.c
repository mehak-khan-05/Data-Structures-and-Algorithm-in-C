#include <stdio.h>
#include <string.h>

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

// Linear Search function
void linearsearch(city a[20], int n) {
    char str[20];
    int index = -1; // Initialize to an invalid index
    int flag = 0;

    printf("Enter city: ");
    scanf("%s", str);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, a[i].name) == 0) {
            flag = 1;
            index = i;
            break; // Exit the loop when the city is found
        }
    }

    if (flag == 1) {
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

    // Performing linear search
    linearsearch(a, n);

    return 0;
}
