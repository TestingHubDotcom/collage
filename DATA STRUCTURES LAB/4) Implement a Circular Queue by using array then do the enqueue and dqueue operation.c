#include <stdio.h>
#define MAX 100

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((front == 0 && rear == MAX-1) || (rear == (front-1)%(MAX-1))) {
        printf("Queue Overflow!\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX-1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    cq[rear] = val;
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = cq[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX-1) {
        front = 0;
    } else {
        front++;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", cq[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1) printf("Dequeued: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
