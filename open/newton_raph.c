#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define f(x) 3 * x - cos(x) - 1
#define df(x) 3 + sin(x)

int main()
{
    double x0, x1, f0, f1, df0;
    int itr;
    float EPS, error;

    printf("Enter the number of iterations: ");
    scanf("%d", &itr);

    // Initialize x1 with a positive value of f(x)
    for (x1 = 0;;)
    {
        f1 = f(x1);
        if (f1 > 0)
        {
            break;
        }
        else
        {
            x1 += 0.01;
        }
    }
    x0 = x1 - 0.01;
    f0 = f(x0);

    printf("Enter the maximum possible error: ");
    scanf("%f", &EPS);
    if (fabs(f0) > f1)
    {
        printf("\n\tThe root is near to %.4f\n", x1);
    }
    else
    {
        printf("\n\tThe root is near to %.4f\n", x0);
    }

    for (int i = 1; i <= itr; i++)
    {
        f0 = f(x0);
        df0 = df(x0);
        x1 = x0 - (f0 / df0);
        printf("\n\tThe %d approx. to the root is %f: ", i, x1);
        error = fabs(x1 - x0);
        if (error < EPS)
        {
            break;
        }
        x0 = x1;
    }
    if (error > EPS)
    {
        printf("Unsufficient no. of iters");
    }
    printf("\n\tRoot is: %0.4f", x1);
}