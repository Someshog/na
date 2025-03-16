#include <stdio.h>

#define SIZE 10  // Define the maximum matrix size

int main() {
    int i, j, k, n;
    float a[SIZE][SIZE + 1], x[SIZE], factor;

    // Input matrix size
    printf("\nEnter the size of matrix n (max %d): ", SIZE);
    scanf("%d", &n);

    if (n > SIZE) {
        printf("Error: Maximum matrix size is %d\n", SIZE);
        return 1;
    }

    // Input augmented matrix
    printf("\nEnter elements in matrix form & RHS\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {  // Includes RHS column
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            if (i != j) {  // Skip diagonal element
                factor = a[i][j] / a[j][j];
                for (k = 0; k <= n; k++) {
                    a[i][k] = a[i][k] - a[j][k] * factor;
                }
            }
        }
    }

    // Extracting solutions
    for (i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
    }

    // Printing solution
    printf("\nSolution of the given matrix is:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = %.3f\n", i, x[i]);
    }

    return 0;
}
