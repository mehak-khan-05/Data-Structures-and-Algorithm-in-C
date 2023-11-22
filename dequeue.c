#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

void initializeDeque(struct CircularQueue* cq) {
    cq->front = cq->rear = -1;
}

int isFull(struct CircularQueue* cq) {
    return ((cq->front == 0 && cq->rear == MAX_SIZE - 1) || (cq->rear == (cq->front - 1) % (MAX_SIZE - 1)));
}

int isEmpty(struct CircularQueue* cq) {
    return (cq->front == -1);
}

void enqueueFront(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Deque is full. Cannot enqueue at front.\n");
        return;
    }

    if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else if (cq->front == 0) {
        cq->front = MAX_SIZE - 1;
    } else {
        cq->front--;
    }

    cq->array[cq->front] = value;
    printf("%d enqueued at the front successfully.\n", value);
}

void enqueueRear(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Deque is full. Cannot enqueue at rear.\n");
        return;
    }

    if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else if (cq->rear == MAX_SIZE - 1) {
        cq->rear = 0;
    } else {
        cq->rear++;
    }

    cq->array[cq->rear] = value;
    printf("%d enqueued at the rear successfully.\n", value);
}

void dequeueFront(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Deque is empty. Cannot dequeue from front.\n");
        return;
    }

    printf("%d dequeued from the front successfully.\n", cq->array[cq->front]);

    if (cq->front == cq->rear) {
        initializeDeque(cq);
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
}

void dequeueRear(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Deque is empty. Cannot dequeue from rear.\n");
        return;
    }

    printf("%d dequeued from the rear successfully.\n", cq->array[cq->rear]);

    if (cq->front == cq->rear) {
        initializeDeque(cq);
    } else if (cq->rear == 0) {
        cq->rear = MAX_SIZE - 1;
    } else {
        cq->rear--;
    }
}
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = cq->front;
    printf("Deque elements: ");
    do {
        printf("%d ", cq->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (cq->rear + 1) % MAX_SIZE);

    printf("\n");
}


int main() {
    struct CircularQueue cq;
    initializeDeque(&cq);

    int choice, value;

    do {
        printf("\nDouble-Ended Queue Menu\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue at the front: ");
                scanf("%d", &value);
                enqueueFront(&cq, value);
                break;

            case 2:
                printf("Enter the value to enqueue at the rear: ");
                scanf("%d", &value);
                enqueueRear(&cq, value);
                break;

            case 3:
                dequeueFront(&cq);
                break;

            case 4:
                dequeueRear(&cq);
                break;

            case 5:
                display(&cq);
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
