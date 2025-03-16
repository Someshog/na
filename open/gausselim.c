#include <stdio.h>
#include <math.h>

#define SIZE 10  // Maximum size of the matrix

int main() {
    int i, j, k, n;
    float a[SIZE][SIZE + 1], x[SIZE], factor;

    // Input matrix size
    printf("Enter the size of the matrix (max %d): ", SIZE);
    scanf("%d", &n);

    // Input augmented matrix
    printf("Enter the augmented matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward elimination (Gaussian elimination)
    for (k = 0; k < n - 1; k++) {
        if(a[k][k] == 0.0)
		  {
			   printf("Mathematical Error!");
			   return 0;
		  }
        for (i = k + 1; i < n; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Backward substitution
    for (i = n - 1; i >= 0; i--) { //i = 2
        x[i] = a[i][n];  // Start with the last column value
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];  // Divide by diagonal element
    }

    // Display solution
    printf("\nSolution of the system:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }

    return 0;
}
