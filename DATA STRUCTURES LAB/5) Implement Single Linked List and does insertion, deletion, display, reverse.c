#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d\n", value);
}

void delete(int value) {
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Deleted %d\n", value);
}

void display() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Reverse\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
