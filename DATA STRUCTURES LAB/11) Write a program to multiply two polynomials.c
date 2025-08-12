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

struct Poly* multiply(struct Poly* p1, struct Poly* p2) {
    struct Poly *res = NULL, *last = NULL, *t2, *newNode;
    for (; p1; p1 = p1->next) {
        t2 = p2;
        while (t2) {
            newNode = (struct Poly*)malloc(sizeof(struct Poly));
            newNode->coeff = p1->coeff * t2->coeff;
            newNode->exp = p1->exp + t2->exp;
            newNode->next = NULL;
            if (!res) res = last = newNode;
            else { last->next = newNode; last = newNode; }
            t2 = t2->next;
        }
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
    struct Poly* prod = multiply(p1, p2);
    printf("Product: ");
    display(prod);
    return 0;
}
