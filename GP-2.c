#include <stdio.h>

int main() {
    int n, x;
    long long sum = 0, term = 1;

    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    for (int i = 0; i < n; i++) {
        sum += term;
        term *= x;
    }

    printf("Sum = %lld", sum);

    return 0;
}