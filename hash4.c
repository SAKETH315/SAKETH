#include <stdio.h>

#define SIZE 100

typedef struct {
    int key;
    int frequency;
    int occupied;
} HashNode;

HashNode hashTable[SIZE];

void initialize() {
    int i;

    for (i = 0; i < SIZE; i++) {
        hashTable[i].key = 0;
        hashTable[i].frequency = 0;
        hashTable[i].occupied = 0;
    }
}

int hashFunction(int key) {
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int pos = (index + i) % SIZE;

        if (!hashTable[pos].occupied) {
            hashTable[pos].key = key;
            hashTable[pos].frequency = 1;
            hashTable[pos].occupied = 1;
            return;
        }

        if (hashTable[pos].key == key) {
            hashTable[pos].frequency++;
            return;
        }

        i++;
    }
}

void display() {
    int i;

    printf("\nElement\tFrequency\n");

    for (i = 0; i < SIZE; i++) {
        if (hashTable[i].occupied)
            printf("%d\t%d\n",
                   hashTable[i].key,
                   hashTable[i].frequency);
    }
}

int main() {
    int arr[100], n, i;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }

    display();

    return 0;
}