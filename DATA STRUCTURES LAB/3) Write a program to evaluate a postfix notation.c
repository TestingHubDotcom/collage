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

// Function to evaluate a postfix expression
int evaluate(char post[])
{
    stack s;
    init(&s); // Initialize stack
    int op1, op2, result;
    int i;

    for (i = 0; post[i] != '\0'; ++i)
    {
        // If the character is a digit, push it to the stack
        if (post[i] >= '0' && post[i] <= '9')
        {
            push(&s, post[i] - '0');
        }
        // If the character is an operator, pop two operands and apply the operator
        else
        {
            op2 = pop(&s); // Second operand
            op1 = pop(&s); // First operand
            switch (post[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            // Push the result back to the stack
            push(&s, result);
        }
    }
    // The final result will be on the top of the stack
    return pop(&s);
}

// Main function to take input and display result
int main()
{
    char infix[100];
    printf("Enter postfix expression: ");
    scanf("%s", infix);
    printf("Postfix evaluation result: %d\n", evaluate(infix));
    return 0;
}