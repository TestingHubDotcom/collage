#include <stdio.h>
#define SIZE 5

typedef struct
{
    int data[SIZE];
    int top; // top of stack

} stack;

void init(stack *);
int isempty(stack *ptr);
int isfull(stack *ptr);
void push(stack *, int);
int pop(stack *);
int peek(stack *);

int main()
{
    stack sta;
    // stack *ptr = &sta;

    int choice, item;
    int popValue, peekValue;

    init(&sta);

    while (1)
    {
        printf("\nEnter 1 to PUSH \nEnter 2 to POP \nEnter 3 to PEEK \nEnter 4 to Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to push : \n");
            scanf("%d", &item);
            push(&sta, item);
            break;

        case 2:
            popValue = pop(&sta);
            if (popValue == -999)
                printf("Stack is empty\n");
            else
                printf("%d is popped from stack\n", popValue);
            break;

        case 3:
            peekValue = peek(&sta);
            if (peekValue == -999)
                printf("Stack is empty\n");
            else
                printf("The topmost item in stack is : %d\n", peekValue);
            break;

        case 4:
            return 0;
        }
    }
}

void init(stack *ptr)
{
    ptr->top = -1;
}

int isempty(stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isfull(stack *ptr)
{
    if (ptr->top == SIZE - 1)
        return 1;
    else
        return 0;
}

void push(stack *ptr, int item)
{
    if (isfull(ptr) == 1)
        printf("Stack full\n");
    else
    {
        ++ptr->top;
        ptr->data[ptr->top] = item;
    }
}

int pop(stack *ptr)
{
    if (isempty(ptr) == 1)
        return -999;
    else
        return (ptr->data[ptr->top--]);
}

int peek(stack *ptr)
{
    if (isempty(ptr) == 1)
        return -999;
    else
        return (ptr->data[ptr->top]);
}