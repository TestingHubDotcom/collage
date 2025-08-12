#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = val;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp, char* output) {
    int i = 0, k = 0;
    char ch;
    while ((ch = exp[i++]) != '\0' && ch != '\n') {
        if (isalnum(ch)) {
            output[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop(); // remove '('
        } else if (ch == ' ') {
            // skip spaces
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                output[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        output[k++] = pop();
    }
    output[k] = '\0';
}

int main() {
    char exp[MAX], output[MAX];
    printf("Enter infix expression: ");
    fgets(exp, MAX, stdin);
    infixToPostfix(exp, output);
    printf("Postfix: %s\n", output);
    return 0;
}
