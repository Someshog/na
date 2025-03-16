#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, iter, i, j, k;
    double a[MAX][MAX+1], x[MAX], sum;

    // Get the number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Get the augmented matrix row-wise
    printf("Enter the augmented matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
        x[i] = 0.0; // Initial guess
    }

    // Get the number of iterations from the user
    printf("Enter the number of iterations: ");
    scanf("%d", &iter);

    // Print header for iterations
    printf("\nIter\t");
    i = 0;
    while (i < n) { 
        printf("x[%d]\t", i+1);
        i++;
    }
    printf("\n");

    // Gauss-Seidel Iteration
    for (k = 0; k < iter; k++) {
        for (i = 0; i < n; i++) {
            sum = a[i][n]; // Start with the constant term

            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j]; // Using updated values directly
                }
            }

            x[i] = sum / a[i][i]; // Update x immediately
        }

        // Print iteration values
        printf("%d\t", k+1);
        i = 0;
        while (i < n) { 
            printf("%.4f\t", x[i]);
            i++;
        }
        printf("\n");
    }

    // Print final solution
    printf("\nFinal solution:\n");
    i = 0;
    while (i < n) { 
        printf("x[%d] = %.4f\n", i+1, x[i]);
        i++;
    }

    return 0;
}
