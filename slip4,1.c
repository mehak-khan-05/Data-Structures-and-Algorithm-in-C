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
    if (isfull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear += 1;
        q->arr[q->rear] = val;
        printf("Enqueued %d into the queue\n", val);
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
        printf("Dequeued %d from the queue\n", a);
    }
    return a;
}

void reverse(struct queue *q)
{
    int *stack = (int *)malloc(q->size * sizeof(int));
    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
    
    }

    int top = -1;

    // Push all elements from the queue to the stack
    while (!isEmpty(q))
    {
        stack[++top] = dequeue(q);
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (top != -1)
    {
        enqueue(q, stack[top--]);
    }

    free(stack);
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        printf("Contents in the queue are: ");
        for (i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch, val;
    struct queue q;
    q.size = 100;
    q.arr = (int *)malloc(q.size * sizeof(int));
    
    init(&q);

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Reverse\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(&q, val);
            display(&q);
            break;

        case 2:
            dequeue(&q);
            display(&q);
            break;

        case 3:
            reverse(&q);
            printf("Queue reversed\n");
            display(&q);
            break;

        case 4:
            display(&q);
            break;

        case 5:
            printf("Exiting program\n");
            break;

        default:
            printf("Enter correct choice\n");
        }
    } while (ch > 0 && ch < 5);

    free(q.arr);
    return 0;
}
