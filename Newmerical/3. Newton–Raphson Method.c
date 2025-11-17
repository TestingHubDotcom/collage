#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (x) * (x) + (x) + 1) // f(x) = x³ + x + 1
#define df(x) (3 * (x) * (x) + 1)        // f'(x) = 3x² + 1

int main()
{
    float x, h;

    printf("Enter the initial value of x: ");
    scanf("%f", &x);

    do
    {
        h = f(x) / df(x);
        x = x - h;

    } while (fabs(h) > 0.00001);

    printf("Final value of the root = %.5f\n", x);

    return 0;
}

// Output:-
// Enter the initial value of x : 1 
// Final value of the root = -0.68233