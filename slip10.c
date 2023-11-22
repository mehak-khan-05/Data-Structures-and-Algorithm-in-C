#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void init(struct queue *q)
{
    q->front = q->rear = -1;
    q->arr = (int *)calloc(q->size, sizeof(int));
}

int isfull(struct queue *q)
{
    return (q->rear == q->size - 1);
}

int isEmpty(struct queue *q)
{
    return (q->front == q->rear);
}

void enqueue(struct queue *q, int val)
{
    if (!isfull(q))
    {
        q->rear += 1;
        q->arr[q->rear] = val;
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = q->front + 1;
        a = q->arr[q->front];
    }
    return a;
}

int peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return q->arr[q->front + 1];
    }
}

void display(struct queue *q)
{
    int i;
    printf("Content in queue:\t");
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    int ch, val;
    struct queue q;
    q.size = 100;
    init(&q);
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isfull(&q))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                display(&q);
            }
            break;

        case 2:
            if (isEmpty(&q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Element dequeued: %d\n", dequeue(&q));
                display(&q);
            }
            break;

        case 3:
            val = peek(&q);
            if (val != -1)
            {
                printf("Front element (Peek): %d\n", val);
            }
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter correct choice\n");
        }
    } while (ch > 0 && ch < 5);

    free(q.arr); // Free allocated memory
    return 0;
}
