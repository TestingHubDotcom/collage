#include <stdio.h>
#define MAX 20

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

void inddelta(float y[][MAX], int n)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
}

void calculate(float x[], float y[][MAX], int n, float value)
{
    float sum = y[0][0];
    float h = x[1] - x[0];
    float u = (value - x[0]) / h;
    float term;

    for (int i = 1; i < n; i++)
    {
        term = 1.0;

        for (int j = 0; j < i; j++)
        {
            term *= (u - j);
        }

        term = (term / fact(i)) * y[0][i];
        sum += term;
    }

    printf("The estimated value at x = %.2f is: %.4f\n", value, sum);
}

int main()
{
    int n;
    float x[MAX], y[MAX][MAX], value;

    printf("Enter number of observations (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter values of x:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter values of y:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    inddelta(y, n);

    printf("Enter the value of x to estimate: ");
    scanf("%f", &value);

    calculate(x, y, n, value);

    return 0;
}

// Output:-
// Enter number of observations(max 20) : 4 
// Enter values of x : 1 2 3 4 
// Enter values of y : 1 8 27 64 
// Enter the value of x to estimate : 5 
// The estimated value at x = 5.00 is : 125.0000