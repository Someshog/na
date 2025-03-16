#include <stdio.h>
#define MAX 10

int main()
{
    int n, i, j;
    float x[MAX], y[MAX][MAX], val, h, p, result;
    float term1, term2, term3, term4;

    //... Input Section
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    printf("\nEnter the x values: ");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("\nEnter the y values: ");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    //... Compute Backward Differences
    for (j = 1; j < 5; j++) // Columns (Order of Differences)
    {
        for (i = n - 1; i >= j; i--) // Backward differences
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    //... Input x value for interpolation
    printf("\nEnter the value of x: ");
    scanf("%f", &val);

    //... Calculation Section
    h = x[1] - x[0]; // Assuming equally spaced x values

    i = n - 1;

    while (x[i] > val)
    {
        i--;
    }

    p = (val - x[i]) / h;
    term1 = p * y[i - 1][1];
    term2 = p * (p + 1) * y[i - 1][2] / 2;
    term3 = (p + 1) * p * (p - 1) * y[i - 2][3] / 6;
    term4 = (p + 2) * (p + 1) * p * (p - 1) * y[i - 3][4] / 24;

    //... Taking Sum
    result = y[i][0] + term1 + term2 + term3 + term4;

    //... Output Section
    printf("\nWhen x = %6.4f, y = %6.8f", val, result);

    return 0;
}
