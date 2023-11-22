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

// Function prototypes
void initCircularQueue(struct CircularQueue* cq);
void enqueue(struct CircularQueue* cq, int x);
int dequeue(struct CircularQueue* cq);
int peek(struct CircularQueue* cq);
int isEmpty(struct CircularQueue* cq);
void display(struct CircularQueue* cq);
void reverse(struct CircularQueue* cq);

int main() {
    struct CircularQueue cq;
    initCircularQueue(&cq);

    int choice, data;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&cq, data);
                break;

            case 2:
                data = dequeue(&cq);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3:
                data = peek(&cq);
                if (data != -1) {
                    printf("Front of the queue: %d\n", data);
                } else {
                    printf("Queue is empty. Cannot peek.\n");
                }
                break;

            case 4:
                display(&cq);
                break;

            case 5:
                reverse(&cq);
                printf("Queue reversed.\n");
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}

void initCircularQueue(struct CircularQueue* cq) {
    cq->front = cq->rear = NULL;
}

void enqueue(struct CircularQueue* cq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL; // Set next to NULL

    if (isEmpty(cq)) {
        cq->front = cq->rear = newNode;
        cq->rear->next = cq->front;
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
        cq->rear->next = cq->front;
    }
}

int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        return -1;
    }
 
    struct Node* temp = cq->front;
    int data = cq->front->data;

    if (cq->front == cq->rear) {
        cq->front = cq->rear = NULL;
    } else {
        cq->front = cq->front->next;
        cq->rear->next = cq->front;
    }

    free(temp);
    temp = NULL; // Set temp to NULL to avoid dangling pointer
    return data;
}

int peek(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        return -1; // Queue is empty, so return -1
    } else {
        return cq->front->data; // Return the data of the front element
    }
}

int isEmpty(struct CircularQueue* cq) {
    return cq->front == NULL;
}

void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = cq->front;
    while (temp->next != cq->front) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Print the last element outside the loop
    printf("%d\n", temp->data);
}

void reverse(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        return; // Nothing to reverse in an empty queue
    }

    struct Node *prev, *current, *next;
    prev = cq->rear;
    current = cq->front;
    cq->rear = cq->front;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != cq->front);

    cq->front = prev;
}


