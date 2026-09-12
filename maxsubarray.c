#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = -999999;
    int rightSum = -999999;
    int sum = 0;
    int i;

    for (i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high) {
    int mid;
    int left, right, cross;

    if (low == high)
        return a[low];

    mid = (low + high) / 2;

    left = maxSubarray(a, low, mid);
    right = maxSubarray(a, mid + 1, high);
    cross = maxCrossingSum(a, low, mid, high);

    return max(max(left, right), cross);
}

int main() {
    int a[100], n, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = maxSubarray(a, 0, n - 1);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}