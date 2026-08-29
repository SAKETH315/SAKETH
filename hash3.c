#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

void initialize() {
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    if (key < 0)
        key = -key;

    return key % SIZE;
}

int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
            return 0;

        if (hashTable[pos] == key)
            return 1;

        i++;
    }

    return 0;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1) {
            hashTable[pos] = key;
            return;
        }

        if (hashTable[pos] == key)
            return;

        i++;
    }
}

int main() {
    int arr[100], n, T;
    int i, complement;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value T: ");
    scanf("%d", &T);

    for (i = 0; i < n; i++) {
        complement = T - arr[i];

        if (search(complement)) {
            printf("Pair found: %d + %d = %d\n",
                   complement, arr[i], T);
            return 0;
        }

        insert(arr[i]);
    }

    printf("No pair found\n");

    return 0;
}