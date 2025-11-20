#include <stdio.h>
#define MS 10

typedef struct
{
    int a[MS];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isfull(Queue *q)
{
    if ((q->front == -1 && q->rear == MS - 1) || (q->rear + 1 == q->front))
        return 1;
    else
        return 0;
}

int isempty(Queue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue is full.\n");
        return;
    }

    if (isempty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
        if (q->rear == MS)
            q->rear = 0;
    }
    q->a[q->rear] = val;
    printf("%d inserted at rear.\n ", val);
}

void dequeue(Queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty , nothing to delete !\n");
        return;
    }
    printf("%d deleted\n", q->a[q->front]);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
    {
        q->front++;
        if (q->front == MS)
            q->front = 0;
    }
}

void enqueueFront(Queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue is full.\n");
        return;
    }

    if (isempty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->front--;
        if (q->front < 0)
            q->front = MS - 1;
    }
    q->a[q->front] = val;
    printf("%d inserted at front.\n ", val);
}

void dequeueRear(Queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty , nothing to delete !\n");
        return;
    }
    printf("%d deleted\n", q->a[q->rear]);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
    {
        q->rear--;
        if (q->rear < 0)
            q->rear = MS - 1;
    }
}

void peekFront(Queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty. Cannot peek.\n");
        return;
    }
    printf("Front element (peek): %d\n", q->a[q->front]);
}
    
void peekRear(Queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty. Cannot peek.\n");
        return;
    }
    printf("Rear element (peek): %d\n", q->a[q->rear]);
}

int main()
{
    Queue q;
    init(&q);
    int choice;
    int val;

    while (1)
    {
        printf("1. Insert at Rear (Enqueue)\n");
        printf("2. Delete from Front (Dequeue)\n");
        printf("3. Insert at Front (Enqueue Front)\n");
        printf("4. Delete from Rear (Dequeue Rear)\n");
        printf("5. Peek at Front\n");
        printf("6. Peek at Rear\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at rear: ");
            scanf("%d", &val);
            enqueue(&q, val);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            printf("Enter value to insert at front: ");
            scanf("%d", &val);
            enqueueFront(&q, val);
            break;

        case 4:
            dequeueRear(&q);
            break;

        case 5:
            peekFront(&q);
            break;
            
        case 6:
            peekRear(&q);
            break;

        case 7:
            printf("\nExiting program. Goodbye!\n");
            break;

        default:
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}