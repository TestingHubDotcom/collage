#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x); // Function e^x
}

float trapezoidal(float x[], int n, float h)
{
    float sum = f(x[0]) + f(x[n]);

    for (int i = 1; i < n; i++)
    {
        sum += 2 * f(x[i]);
    }

    return sum * (h / 2.0);
}

int main()
{
    int a, b, n;

    printf("Enter the limits a and b: ");
    scanf("%d %d", &a, &b);

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    float x[n + 1];
    float h = (float)(b - a) / n;

    x[0] = a;

    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }

    printf("The integrated value using trapezoidal rule is: %.4f\n", trapezoidal(x, n, h));

    return 0;
}

// Output:-
// Enter the limits a and b : 0 1 
// Enter number of intervals : 5 0 
// The integrated value using trapezoidal rule is : 1.7240