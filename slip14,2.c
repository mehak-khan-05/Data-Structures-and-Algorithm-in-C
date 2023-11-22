#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isDequeEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

void addFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void addRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int removeFront(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("queue is empty\n");
    }

    int data = deque->front->data;
    struct Node* temp = deque->front;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int removeRear(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
       
        printf("queue is empty\n");
    }

    int data = deque->rear->data;
    struct Node* temp = deque->rear;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

void printDeque(struct Deque* deque) {
    struct Node* current = deque->front;

    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// void freeDeque(struct Deque* deque) {
//     while (!isDequeEmpty(deque)) {
//         removeFront(deque);
//     }
// }

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    int choice, data;

    do {
        printf("\n--- Deque Menu ---\n");
        printf("1. Add to Front\n");
        printf("2. Add to Rear\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from Rear\n");
        printf("5. Print Deque\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to front: ");
                scanf("%d", &data);
                addFront(&deque, data);
                break;
            case 2:
                printf("Enter data to add to rear: ");
                scanf("%d", &data);
                addRear(&deque, data);
                break;
            case 3:
                printf("Removed front item: %d\n", removeFront(&deque));
                break;
            case 4:
                printf("Removed rear item: %d\n", removeRear(&deque));
                break;
            case 5:
                printDeque(&deque);
                break;
            case 0:
                printf("Exiting program. Freeing memory...\n");
                // freeDeque(&deque);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
