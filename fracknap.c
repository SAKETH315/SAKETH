#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

int main() {
    struct Item item[100], temp;
    int n, capacity, i, j;
    float totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].weight, &item[i].value);
        item[i].ratio = (float)item[i].value / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (item[j].ratio < item[j + 1].ratio) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            capacity -= item[i].weight;
            totalValue += item[i].value;
        } else {
            totalValue += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value = %.2f\n", totalValue);

    return 0;
}