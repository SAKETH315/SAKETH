#include <stdio.h>

void bucketSort(int arr[], int n) {
    int bucket[10][100];
    int count[10] = {0};
    int i, j, k = 0, index;

    for (i = 0; i < n; i++) {
        index = arr[i] / 10;
        bucket[index][count[index]++] = arr[i];
    }

    for (i = 0; i < 10; i++) {
        for (j = 1; j < count[i]; j++) {
            int temp = bucket[i][j];
            int l = j - 1;

            while (l >= 0 && bucket[i][l] > temp) {
                bucket[i][l + 1] = bucket[i][l];
                l--;
            }

            bucket[i][l + 1] = temp;
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements (0-99):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}