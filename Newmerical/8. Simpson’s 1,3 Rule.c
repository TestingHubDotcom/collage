#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x); // Function e^x
}

float simpson(float x[], int n, float h)
{
    float sum = f(x[0]) + f(x[n]);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum += 2 * f(x[i]);
        else
            sum += 4 * f(x[i]);
    }

    return sum * (h / 3.0);
}

int main()
{
    int a, b, n;

    printf("Enter the limits a and b: ");
    scanf("%d %d", &a, &b);

    printf("Enter number of intervals (n must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Error: n must be even for Simpson's 1/3 rule.\n");
        return 0;
    }

    float x[n + 1];
    float h = (float)(b - a) / n;

    x[0] = a;

    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }

    printf("The integrated value using Simpson's 1/3 rule is: %.4f\n", simpson(x, n, h));

    return 0;
}

// Output:-
// Enter the limits a and b : 0 1 
// Enter number of intervals(n must be even) : 50 
// The integrated value using Simpson's 1/3 rule is: 1.7183