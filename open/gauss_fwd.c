#include <stdio.h>

#define MAX 10

int main()
{
    int n, i, j;
    float x[MAX], y[MAX][MAX], val, h, p, result;
    float y1, y2, y3, y4;

    //... Input Section
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    printf("\nEnter the x values: ");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("\nEnter the y values: ");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    //... Compute Forward Differences
    for (j = 1; j < 5; j++) // Columns (Order of Differences)
    {
        for (i = 0; i < n - j; i++) // Rows (Data points)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    //... Input x value for interpolation
    printf("\nEnter the value of x: ");
    scanf("%f", &val);

    //... Calculation Section
    h = x[1] - x[0]; // Assuming equally spaced x values

    i = 0;

    while (x[i] < val)
    {
        i++;
    }

    p = (val - x[i]) / h;
    y1 = p * y[i][1];
    y2 = p * (p - 1) * y[i - 1][2] / 2;
    y3 = (p + 1) * p * (p - 1) * y[i - 2][3] / 6;
    y4 = (p + 1) * p * (p - 1) * (p - 2) * y[i - 3][4] / 24;

    //... Taking Sum
    result = y[i][0] + y1 + y2 + y3 + y4;

    //... Output Section
    printf("\nWhen x = %6.4f, y = %6.8f", val, result);

    return 0;
}
