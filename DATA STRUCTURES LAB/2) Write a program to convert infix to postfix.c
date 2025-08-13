#include <stdio.h>
#define SIZE 10 // Maximum size of the stack

// Stack structure definition
typedef struct
{
    int a[SIZE]; // Array to store stack elements
    int tos;     // Top of stack index
} stack;

// Initialize the stack
void init(stack *pts)
{
    pts->tos = -1;
}

// Check if the stack is empty
int isempty(stack *pts)
{
    return (pts->tos == -1);
}

// Check if the stack is full
int isfull(stack *pts)
{
    return (pts->tos == (SIZE - 1));
}

// Push an item onto the stack
void push(stack *pts, int item)
{
    if (isfull(pts))
        return; // Do nothing if stack is full
    pts->a[++pts->tos] = item;
}

// Pop an item from the stack
int pop(stack *pts)
{
    if (isempty(pts))
        return -999; // Return error value if stack is empty
    int z = pts->a[pts->tos];
    pts->tos--;
    return z;
}

// Peek at the top item of the stack without popping
int peek(stack *pts)
{
    if (isempty(pts))
        return -999; // Return error value if stack is empty
    return (pts->a[pts->tos]);
}

// Function to return precedence of operators
int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

// Function to check if character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    stack s;
    init(&s);
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0')
    {
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            // Operand goes directly to output
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (!isempty(&s) && peek(&s) != '(')
            {
                postfix[k++] = pop(&s);
            }
            if (!isempty(&s) && peek(&s) == '(')
                pop(&s); // Remove '('
        }
        else if (isOperator(ch))
        {
            while (!isempty(&s) && precedence(peek(&s)) >= precedence(ch))
            {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    // Pop any remaining operators
    while (!isempty(&s))
    {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

// Main function to take input and display result
int main()
{
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}