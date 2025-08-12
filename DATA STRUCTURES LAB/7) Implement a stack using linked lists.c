#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

void push(int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = top->data;
    struct StackNode* temp = top;
    top = top->next;
    free(temp);
    printf("%d popped from stack.\n", value);
    return value;
}

void display() {
    struct StackNode* temp = top;
    printf("Stack elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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
