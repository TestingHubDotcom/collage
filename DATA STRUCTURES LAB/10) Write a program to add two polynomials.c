#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff, exp;
    struct Poly* next;
};

struct Poly* create() {
    struct Poly *head = NULL, *temp, *newNode;
    int n, c, e;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &c, &e);
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;
        if (!head) head = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }
    return head;
}

struct Poly* add(struct Poly* p1, struct Poly* p2) {
    struct Poly *res = NULL, *last = NULL, *newNode;
    while (p1 && p2) {
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        if (p1->exp > p2->exp) {
            newNode->coeff = p1->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            newNode->coeff = p2->coeff;
            newNode->exp = p2->exp;
            p2 = p2->next;
        } else {
            newNode->coeff = p1->coeff + p2->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        newNode->next = NULL;
        if (!res) res = last = newNode;
        else { last->next = newNode; last = newNode; }
    }
    while (p1) {
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        newNode->coeff = p1->coeff;
        newNode->exp = p1->exp;
        newNode->next = NULL;
        last->next = newNode; last = newNode;
        p1 = p1->next;
    }
    while (p2) {
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        newNode->coeff = p2->coeff;
        newNode->exp = p2->exp;
        newNode->next = NULL;
        last->next = newNode; last = newNode;
        p2 = p2->next;
    }
    return res;
}

void display(struct Poly* p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    printf("First polynomial:\n");
    struct Poly* p1 = create();
    printf("Second polynomial:\n");
    struct Poly* p2 = create();
    struct Poly* sum = add(p1, p2);
    printf("Sum: ");
    display(sum);
    return 0;
}
