#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void bubbleSort(struct Node* start) {
    int swapped;
    struct Node *ptr1, *lptr = NULL;

    // Checking for empty list
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data directly without double pointers
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void insertEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 64);
    insertEnd(&head, 34);
    insertEnd(&head, 25);
    insertEnd(&head, 12);
    insertEnd(&head, 22);
    insertEnd(&head, 11);
    insertEnd(&head, 90);

    printf("Linked list before sorting:\n");
    printList(head);

    bubbleSort(head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}
