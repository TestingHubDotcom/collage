#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct DNode* head = NULL;

void insert(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    printf("Inserted %d\n", value);
}

void delete(int value) {
    struct DNode* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) {
        printf("Value %d not found!\n", value);
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted %d\n", value);
}

void display() {
    struct DNode* temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct DNode *curr = head, *temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
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
