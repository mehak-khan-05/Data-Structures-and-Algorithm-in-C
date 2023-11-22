#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
// struct queue *q;
void init(struct queue *q)
{
    q->front = q->rear = -1;
}

int isfull(struct queue *q)
{
    if (q->rear==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val)
{
    
   if(isfull(q)){
    printf("queue is empty\n");
   }
    else
    {
       
        q->rear += 1;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
       
        q->front = q->front+1;
        a=q->arr[q->rear];
    }
    return a;
}



void display(struct queue *q)
{
    int i;
    printf("content in q are : \t");
    for (i = q->front+1; i<= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
}

int main()
{
    int ch, val;
    struct queue q;
    q.size = 100;
    init(&q);
    do
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.reverse\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        if(isfull(&q)){
            printf("queue is full dear \n");
        }
        else{

            printf("enter the value to enqueue\n");
            scanf("%d", &val);
            enqueue(&q,val);
            display(&q);
        }
            break;

        case 2:
         if(isEmpty(&q)){
            printf("queue is empty dear \n");
        }
        else{
            printf("elemnts to dequeue is %d\n",dequeue(&q));
            display(&q);
        }
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("enter correct choice\n");
        }
    } while (ch > 0 && ch < 5);
    return 0;
}