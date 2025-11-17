#include <stdio.h>
#include <math.h>

float poly(float x)
{
    float z = (x * x * x) + x + 1; // Example function f(x) = x³ + x + 1
    return z;
}

int main()
{
    float a, b, c;

    printf("Enter the two values (a and b): ");
    scanf("%f %f", &a, &b);

    // Check if root exists between a and b
    if (poly(a) * poly(b) > 0)
    {
        printf("Invalid interval! f(a) and f(b) should have opposite signs.\n");
        return 0;
    }

    while (fabs(a - b) > 0.0001)
    {
        c = (a + b) / 2.0;

        if (poly(c) < 0)
            a = c;
        else
            b = c;
    }

    printf("The solution is %.4f\n", c);

    return 0;
}

// Output:- 
// Enter the two values(a and b) : -1 - 0.5 
// The solution is - 0.6823