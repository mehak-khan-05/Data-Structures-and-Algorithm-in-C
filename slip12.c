
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void init(struct CircularQueue* Q) {
    Q->front = Q->rear = NULL;
}

void addQueue(struct CircularQueue* Q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;
        newNode->next = Q->front;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
        Q->rear->next = Q->front;
    }
}

int deleteQueue(struct CircularQueue* Q) {
    if (Q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value;
    struct Node* temp = Q->front;

    if (Q->front == Q->rear) {
        value = Q->front->data;
        free(Q->front);
        Q->front = Q->rear = NULL;
    } else {
        value = Q->front->data;
        Q->front = Q->front->next;
        Q->rear->next = Q->front;
        free(temp);
    }

    return value;
}

void display(struct CircularQueue* Q) {
    if (Q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = Q->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != Q->front);

    printf("\n");
}

int main() {
    struct CircularQueue Q;
    init(&Q);

    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Add to Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add to the queue: ");
                scanf("%d", &value);
                addQueue(&Q, value);
                break;

            case 2:
                value = deleteQueue(&Q);
                if (value != -1) {
                    printf("Deleted value from the queue: %d\n", value);
                }
                break;

            case 3:
                printf("Queue contents: ");
                display(&Q);
                break;

            case 4:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
