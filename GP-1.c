#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    double sum;

    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    if (x == 1)
        sum = n;
    else
        sum = (pow(x, n) - 1) / (x - 1);

    printf("Sum = %.0f", sum);

    return 0;
}