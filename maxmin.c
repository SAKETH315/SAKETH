#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result maxMin(int a[], int low, int high) {
    struct Result r, left, right;
    int mid;

    if (low == high) {
        r.max = r.min = a[low];
        return r;
    }

    if (high == low + 1) {
        if (a[low] > a[high]) {
            r.max = a[low];
            r.min = a[high];
        } else {
            r.max = a[high];
            r.min = a[low];
        }
        return r;
    }

    mid = (low + high) / 2;

    left = maxMin(a, low, mid);
    right = maxMin(a, mid + 1, high);

    r.max = (left.max > right.max) ? left.max : right.max;
    r.min = (left.min < right.min) ? left.min : right.min;

    return r;
}

int main() {
    int a[100], n, i;
    struct Result r;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    r = maxMin(a, 0, n - 1);

    printf("Maximum = %d\n", r.max);
    printf("Minimum = %d\n", r.min);

    return 0;
}