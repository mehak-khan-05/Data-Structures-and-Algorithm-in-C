#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// CircularList structure
struct CircularList {
    struct Node* last;
};

// Function to append n integers to the circular list
void append(struct CircularList* list, int n) {
    for (int i = 0; i < n; ++i) {
        int data;
        printf("Enter an integer: ");
        scanf("%d", &data);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;

        if (list->last == NULL) {
            // If the list is empty, set the new node as the last node
            list->last = new_node;
            new_node->next = list->last;
        } else {
            // Add the new node to the end of the list
            new_node->next = list->last->next;
            list->last->next = new_node;
            list->last = new_node;
        }
    }
}

// Function to display the circular list
void display(struct CircularList* list) {
    if (list->last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = list->last->next;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->last->next);
    printf("\n");
}

// Main function
int main() {
    struct CircularList circular_list;
    circular_list.last = NULL;
    int n;
printf("enter the value of n ");
scanf("%d",&n);
    // Append 5 integers to the circular list
    append(&circular_list, n);

    // Display the circular list
    printf("Circular List: ");
    display(&circular_list);

    return 0;
}
