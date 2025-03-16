#include <stdio.h>

#define MAX 10  // Maximum number of data points

int main() {
    int n, i, j;
    float x[MAX], y[MAX][MAX], value, h, p, result, term;

    // Taking number of data points as input
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input all x values at once
    printf("Enter %d values of x: ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Input all y values at once
    printf("Enter %d corresponding values of y: ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);  // First column stores y values
    }

    // Compute the backward difference table
    for (j = 1; j < n; j++) {  // Columns
        for (i = n - 1; i >= j; i--) {  // Rows (backward computation)
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Input the value of x for which y is required
    printf("\nEnter the value of x for which you want to find y: ");
    scanf("%f", &value);

    // Compute h and p
    h = x[1] - x[0];
    p = (value - x[n - 1]) / h;  // Using last x value for backward formula

    // Compute the interpolated value using Newton's backward formula
    result = y[n - 1][0];  // First term from the last row
    term = 1;  // To store p, p(p+1), p(p+1)(p+2), ...

    for (i = 1; i < n; i++) {
        term *= (p + (i - 1)) / i;  // Compute the term coefficient
        result += term * y[n - 1][i];   // Add corresponding difference term
    }

    // Output the result
    printf("\nFor x = %.4f, interpolated y = %.6f\n", value, result);

    return 0;
}
