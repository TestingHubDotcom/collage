#include <stdio.h>
#include <math.h>

double f(double x, double y)
{
    return x + y; // dy/dx = x + y
}

void euler(double x0, double y0, double x_end, double h)
{
    int n = (x_end - x0) / h;
    double x = x0;
    double y = y0;

    printf("\n  x\t\t y\n");
    printf("-------------------------\n");
    printf("%.5lf\t %.5lf\n", x, y);

    for (int i = 1; i <= n; i++)
    {
        y = y + h * f(x, y);
        x = x + h;

        printf("%.5lf\t %.5lf\n", x, y);
    }

    printf("\nSolution at x = %.5lf is y = %.5lf\n", x, y);
}

int main()
{
    double x0, y0, x_end, h;

    printf("Enter initial value x0: ");
    scanf("%lf", &x0);

    printf("Enter initial value y0: ");
    scanf("%lf", &y0);

    printf("Enter the value of x at which solution is needed: ");
    scanf("%lf", &x_end);

    printf("Enter step size h: ");
    scanf("%lf", &h);

    euler(x0, y0, x_end, h);

    return 0;
}

// Output:-
// Enter initial value x0 : 0 
// Enter initial value y0 : 1 
// Enter the value of x at which solution is needed : 0.1 
// Enter step size h : 0.02

//    x      y
// -- -- -- -- -- -- -- -- -- -- -- -- -
// 0.00000 1.00000 
// 0.02000 1.02000 
// 0.04000 1.04080 
// 0.06000 1.06242 
// 0.08000 1.08486 
// 0.10000 1.10816

// Solution at x = 0.10000 is y = 1.10816