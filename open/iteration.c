#include<stdio.h>
#include<math.h>
#define EPS 0.00005
#define F(x) (x*x*x + 1)/2
#define f(x) x*x*x - 2*x + 1

void ITER();

void main() {
    printf("\n Solution by ITERATION method \n");
    printf("\n Equation is ");
    printf("\n X*X*X - 2*X + 1 = 0\n\n");
    ITER();
}

void ITER() {
    float x1, x2, x0, f0, f1, f2, error;
    int i = 0, n;

    for (x1 = 1;; x1++) {
        f1 = F(x1);
        if (f1 > 0)
            break;
    }

    for (x0 = x1 - 1;; x0--) {
        f0 = f(x0);
        if (f0 < 0)
            break;
    }

    x2 = (x0 + x1) / 2;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    
    printf("\n The 1st approximation to the root is: %f", x2);

    for (; i < n - 1; i++) {
        f2 = F(x2);
        printf("\n The %d approximation to the root is: %f", i + 2, f2);
        x2 = F(x2);
        error = fabs(f2 - f1);

        if (error < EPS)
            break;

        f1 = f2;
    }

    if (error > EPS)
        printf("\n NOTE:- The number of iterations are not sufficient.");
    
    printf("\n The root is %.4f", f2);
}
