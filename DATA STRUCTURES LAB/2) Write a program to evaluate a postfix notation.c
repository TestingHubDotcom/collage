#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* exp) {
    int i = 0;
    while (exp[i]) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else if (exp[i] == ' ') {
            // skip spaces
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression (single digit operands, space separated): ");
    fgets(exp, MAX, stdin);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
