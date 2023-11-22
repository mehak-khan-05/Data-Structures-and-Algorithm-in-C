#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists into a new sorted list
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;     // Dummy node to hang the result on
    struct Node* current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    }

    if (list2 != NULL) {
        current->next = list2;
    }

    return dummy.next;
}

// Function to insert a node at the beginning of a linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    list1 = insertAtBeginning(list1, 20);
    list1 = insertAtBeginning(list1, 15);
    list1 = insertAtBeginning(list1, 10);
    list1 = insertAtBeginning(list1, 5);

    struct Node* list2 = NULL;
    list2 = insertAtBeginning(list2, 204);
    list2 = insertAtBeginning(list2, 135);
    list2 = insertAtBeginning(list2, 130);
    list2 = insertAtBeginning(list2, 35);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
