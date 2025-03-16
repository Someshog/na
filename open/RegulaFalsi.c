#include <stdio.h>
#include <math.h>
#include <string.h>
#define EPS 0.00005
#define F(x) 3 * x + sin(x) - exp(x)
void RegulaFalsi();

void main()
{
    /////
    RegulaFalsi();
}
void RegulaFalsi()
{
    float f0, f1, f2;
    float x0, x1, x2;
    int itr;
    printf("No. of Iterations: ");
    scanf("%d", &itr);
    for (x1 = 0.0;;)
    {
        f1 = F(x1); // f1 store +ve
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
    f0 = F(x0); // f0 stores -ve
    printf("\n\n\tITERATION\t x2\t\t F(x)\n");
    for (int i = 0; i < itr; i++)
    {
        x2 = x0 - ((x1 - x0) / (f1 - f0)) * f0;
        f2 = F(x2);
        
        if (f0 * f2 > 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        if (fabs(x2) > EPS)
        {
            printf("\n\t%d\t %f\t\t%f\n", i + 1, x2, f2);
            
        }

    }
    printf("\n Root = %f\n", x2);
}