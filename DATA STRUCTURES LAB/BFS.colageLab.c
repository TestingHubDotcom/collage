#include <stdio.h>
#define MAX 100

typedef struct Queue
{
    int a[MAX];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int x)
{
    if (q->rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->a[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int temp = q->a[q->front];
        q->front++;
        return temp;
    }
}

void bfs(int N, int A[][N], int src, int p[], int d[])
{
    char c[N];
    Queue q;
    init(&q);

    for (int j = 0; j < N; j++)
    {
        c[j] = 'w';
        p[j] = -1;
        d[j] = -1;
    }

    p[src] = -1;
    d[src] = 0;
    c[src] = 'g';
    
    enqueue(&q, src);

    while (!isEmpty(&q))
    {
        int i = dequeue(&q);
        printf("%d ", i);

        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == 1 && c[j] == 'w')
            {
                c[j] = 'g';
                d[j] = d[i] + 1;
                p[j] = i;
                enqueue(&q, j);
            }
        }
        c[i] = 'b';
    }
}

int main()
{
    int N;
    printf("Enter number of vertices: ");
    scanf("%d", &N);

    int A[N][N], p[N], d[N];

    printf("Enter the adjacency matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("BFS traversal starting from node 0:\n");
    bfs(N, A, 0, p, d);

    printf("\n\nParent array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);

    printf("\nDistance array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", d[i]);

    return 0;
}