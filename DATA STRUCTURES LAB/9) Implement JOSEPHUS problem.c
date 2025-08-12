#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int n) {
    struct Node *temp, *newNode;
    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

void josephus(int m) {
    struct Node *p = head, *q = NULL;
    while (p->next != p) {
        for (int i = 1; i < m; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
        p = q->next;
    }
    printf("Survivor: %d\n", p->data);
    free(p);
}

int main() {
    int n, m;
    printf("Enter number of people: ");
    scanf("%d", &n);
    printf("Enter step count: ");
    scanf("%d", &m);
    create(n);
    josephus(m);
    return 0;
}
