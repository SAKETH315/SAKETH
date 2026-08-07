#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the sorted elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int beg = 0, end = n - 1, mid, k;

    printf("Enter the target: ");
    scanf("%d", &k);

    while(beg <= end) {
        mid = (beg + end) / 2;

        if(k == a[mid]) {
            printf("Found at index %d", mid);
            return 0;
        }
        else if(k > a[mid]) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    printf("Not found");

    return 0;
}