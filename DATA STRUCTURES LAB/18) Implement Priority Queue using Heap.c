// Priority Queue using Heap
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
void insert(int val) {
    int i = ++size;
    heap[i] = val;
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}
int extractMax() {
    if (size == 0) return -1;
    int max = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (2*i <= size) {
        int j = 2*i;
        if (j < size && heap[j] < heap[j+1]) j++;
        if (heap[i] >= heap[j]) break;
        swap(&heap[i], &heap[j]);
        i = j;
    }
    return max;
}
void display() {
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Extract Max\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                val = extractMax();
                if (val != -1) printf("Max: %d\n", val);
                else printf("Heap is empty!\n");
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
