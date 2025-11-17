#include <stdio.h>

float l(int i, float x[], int n, float a)
{
    float res = 1;

    for (int j = 0; j < n; j++)
    {
        if (j != i)
        {
            res = res * (a - x[j]) / (x[i] - x[j]);
        }
    }

    return res;
}

int main()
{
    int n;
    float x[20], y[20], a, sum = 0;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points (x[i] y[i]):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &a);

    for (int i = 0; i < n; i++)
    {
        sum = sum + l(i, x, n, a) * y[i];
    }

    printf("Interpolated value at x = %.3f is %.3f\n", a, sum);

    return 0;
}

// Output:-
// Enter number of data points : 3 
// Enter data points(x[i] y[i]) : 1 1 2 4 3 9 
// Enter the value of x to interpolate : 5 
// Interpolated value at x = 5.000 is 25.000