#include <stdio.h>

int main()
{
    int n, k, min, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    for (int count = 1; count <= k; count++)
    {
        min = a[0];
        pos = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                pos = i;
            }
        }

        a[pos] = 999999;
    }

    printf("Kth smallest element = %d", min);

    return 0;
}