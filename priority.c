#include <stdio.h>

#define MAX 10

struct Node {
    int data;
    int priority;
};

int front, rear;
struct Node pq[MAX];

void create() {
    front = rear = -1;
}

void insertByPriority() {
    int num, pn;
    if (rear == MAX - 1) {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    } else {
        printf("Enter data: ");
        scanf("%d", &num);
        printf("Enter priority: ");
        scanf("%d", &pn);

        if (rear == -1) {
            rear++;
            front++;
        } else {
            rear++;
        }

        // Find the correct position to insert the new node based on priority
        int i = rear - 1;
while (i >= front && pn > pq[i].priority) {
    pq[i + 1] = pq[i];
    i--;
}

pq[i + 1].data = num;
pq[i + 1].priority = pn;

}
}

void deleteByPriority() {
    int i, pos = 0, max = pq[front].priority;

    if (front == -1) {
        printf("Priority queue is empty. Cannot delete.\n");
        return;
    } else if (front == rear) {
        printf("Deleted: Data = %d, Priority = %d\n", pq[front].data, pq[front].priority);
        front = rear = -1;
    } else {
        for (i = front; i <= rear; i++) {
            if (pq[i].priority > max) {
                max = pq[i].priority;
                pos = i;
            }
        }

        printf("Deleted: Data = %d, Priority = %d\n", pq[pos].data, pq[pos].priority);

        for (int i = pos; i < rear; i++) {
            pq[i].data = pq[i + 1].data;
            pq[i].priority = pq[i + 1].priority;
        }

        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Priority queue is empty.\n");
        return;
    } else {
        printf("Priority Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("Data = %d, Priority = %d\n", pq[i].data, pq[i].priority);
        }
    }
}

int main() {
    create();

    int choice;

    do {
        printf("\nPriority Queue Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        // // Validate user input
        // if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        //     printf("Invalid input. Please enter a number between 1 and 4.\n");
        //     while (getchar() != '\n');  // Clear input buffer
        //     continue;
        // }

        switch (choice) {
            case 1:
                insertByPriority();
                break;

            case 2:
                deleteByPriority();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice>0 &&choice<4);

    return 0;
}
