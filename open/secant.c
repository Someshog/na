#include <stdio.h>
#include <conio.h>
#include <math.h>
#define EPS 0.00005

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define f(x) 3 * x + sin(x) - exp(x)

int main()
{
    double x0, x1, x2, f0, f1, f2;
    int itr;

    printf("Enter the number of iterations: ");
    scanf("%d", &itr);

    // Initialize x1 with a positive value of f(x)
    for (x1 = 0.0;;)
    {
        f1 = f(x1);
        if (f1 > 0)
        {
            break;
        }
        else
        {
            x1 += 0.1;
        }
    }

    x0 = x1 - 0.1;
    f0 = f(x0);

    printf("\n\n\tITERATION\t x2\t\t F(x)\n");

    for (int i = 0; i < itr; i++)
    {
        if (f0 == f1)
        {
            printf("Mathematical Error: Division by zero.\n");
            return 1;
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        if (fabs(2) > EPS)
        {
            printf("\t%d\t\t%.6f\t%.6f\n", i + 1, x2, f2);
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

    }

    printf("\nRoot is: %.6f\n", x2);
    return 0;
}