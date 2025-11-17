#include <stdio.h>
#include <math.h>

float poly(float x)
{
    float z = (x * x * x) + x + 1; // f(x) = x³ + x + 1
    return z;
}

int main()
{
    float a, b, c;

    printf("Enter the two values (a and b): ");
    scanf("%f %f", &a, &b);

    if (poly(a) * poly(b) >= 0)
    {
        printf("Invalid interval!\n");
        return 0;
    }

    do
    {
        c = (a * poly(b) - b * poly(a)) / (poly(b) - poly(a));

        if (poly(a) * poly(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(poly(c)) > 0.0001);

    printf("The solution is %.4f\n", c);

    return 0;
}

// Output:- 
// Enter the two values(a and b) : -1 - 0.5
// The solution is -0.6823