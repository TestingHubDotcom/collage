#include <stdio.h>
#include <math.h>

double f(double x, double y)
{
    return x + y; // dy/dx = x + y
}

void rungekutta(double x0, double y0, double x_end, double h)
{
    int n = (x_end - x0) / h;
    double x = x0;
    double y = y0;

    printf("\n  x\t\t  y\n");
    printf("------------------------------\n");
    printf("%.5lf\t %.5lf\n", x, y);

    for (int i = 1; i <= n; i++)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;

        printf("%.5lf\t %.5lf\n", x, y);
    }

    printf("\nApproximate solution at x = %.5lf is y = %.5lf\n", x, y);
}

int main()
{
    double x0, y0, x_end, h;

    printf("Enter initial value x0: ");
    scanf("%lf", &x0);

    printf("Enter initial value y0: ");
    scanf("%lf", &y0);

    printf("Enter value of x at which solution is required: ");
    scanf("%lf", &x_end);

    printf("Enter step size h: ");
    scanf("%lf", &h);

    rungekutta(x0, y0, x_end, h);

    return 0;
}

// Output:-
// Enter initial value x0 : 0 
// Enter initial value y0 : 1 
// Enter value of x at which solution is required : 0.1 
// Enter step size h : 0.02
//     x     y
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// 0.00000 1.00000 
// 0.02000 1.02040 
// 0.04000 1.04162 
// 0.06000 1.06367 
// 0.08000 1.08657 
// 0.10000 1.11034

// Approximate solution at x = 0.10000 is y = 1.11034