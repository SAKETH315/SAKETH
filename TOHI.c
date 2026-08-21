#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));

    return stack;
}

void push(struct Stack* stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void moveDisk(struct Stack* source, struct Stack* destination,
              char sourceName, char destinationName)
{
    int disk = pop(source);

    push(destination, disk);

    printf("Move disk %d from %c to %c\n",
           disk, sourceName, destinationName);
}

int main()
{
    int n, i, totalMoves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    struct Stack *A = createStack(n);
    struct Stack *B = createStack(n);
    struct Stack *C = createStack(n);

    for (i = n; i >= 1; i--)
        push(A, i);

    totalMoves = (1 << n) - 1;

    if (n % 2 == 0)
    {
        for (i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(A, B, 'A', 'B');
            else if (i % 3 == 2)
                moveDisk(A, C, 'A', 'C');
            else
                moveDisk(B, C, 'B', 'C');
        }
    }
    else
    {
        for (i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(A, C, 'A', 'C');
            else if (i % 3 == 2)
                moveDisk(A, B, 'A', 'B');
            else
                moveDisk(B, C, 'B', 'C');
        }
    }

    free(A->array);
    free(B->array);
    free(C->array);

    free(A);
    free(B);
    free(C);

    return 0;
}