#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }
    return queue->front->data;
}

void display(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, data;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;

            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3:
                data = peek(&queue);
                if (data != -1) {
                    printf("Front of the queue: %d\n", data);
                } else {
                    printf("Queue is empty. Cannot peek.\n");
                }
                break;

            case 4:
                printf("Queue elements: ");
                display(&queue);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
