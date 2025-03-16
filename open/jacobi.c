#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, iter, i, j, k;
    float a[MAX][MAX+1], x[MAX], newX[MAX];

    // Get the number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Get the augmented matrix row-wise
    printf("Enter the augmented matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]); // Read both coefficients and constants
        }
        x[i] = 0.0; // Initial guess
    }

    // Get number of iterations from user
    printf("Enter the number of iterations: ");
    scanf("%d", &iter);

    printf("\nIter\t");
    for (i = 0; i < n; i++) printf("x[%d]\t", i+1);
    printf("\n");

    // Perform Gauss-Jacobi Iterations
    for (k = 0; k < iter; k++) {
        // Compute new values
        for (i = 0; i < n; i++) {
            float sum = a[i][n]; // Start with the constant term

            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }

            newX[i] = sum / a[i][i]; // Compute new value
        }

        // Update x values
        for (i = 0; i < n; i++) {
            x[i] = newX[i];
        }

        // Print iteration values
        printf("%d\t", k+1);
        for (i = 0; i < n; i++) printf("%.4f\t", x[i]);
        printf("\n");
    }

    // Print final solution
    printf("\nFinal solution after %d iterations:\n", iter);
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i+1, x[i]);
    }

    return 0;
}
