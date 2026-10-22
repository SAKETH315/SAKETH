#include <stdio.h>
#include <stdlib.h>
struct Node {
char data;
int freq;
struct Node *left, *right;
};
struct Node* createNode(char data, int freq) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->freq = freq;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
int findMin(struct Node* nodes[], int n) {
int min = 0;
for (int i = 1; i < n; i++) {
    if (nodes[i]->freq < nodes[min]->freq)
        min = i;
}
return min;
}
void printCodes(struct Node* root, int code[], int top) {
if (root->left) {
code[top] = 0;
printCodes(root->left, code, top + 1);
}
if (root->right) {
    code[top] = 1;
    printCodes(root->right, code, top + 1);
}
if (!root->left && !root->right) {
    printf("%c: ", root->data);
    for (int i = 0; i < top; i++)
        printf("%d", code[i]);
    printf("\n");
}
}
void huffman(char data[], int freq[], int n) {            
struct Node* nodes[100];
int size = n;
for (int i = 0; i < n; i++)
    nodes[i] = createNode(data[i], freq[i]);
while (size > 1) {
    int min1 = findMin(nodes, size);
    struct Node* left = nodes[min1];
    nodes[min1] = nodes[size - 1];
    size--;
    int min2 = findMin(nodes, size);
    struct Node* right = nodes[min2];
    nodes[min2] = nodes[size - 1];
    size--;
    struct Node* parent = createNode('$', left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    nodes[size++] = parent;
}
int code[100];
printf("\nHuffman Codes:\n");
printCodes(nodes[0], code, 0);
}
int main() {
int n;
printf("Enter number of characters: ");
scanf("%d", &n);
if (n < 1 || n > 100) {
    printf("Enter between 1 and 100 characters.\n");
    return 1;
}
char data[100];
int freq[100];
for (int i = 0; i < n; i++) {
    printf("Enter character and frequency: ");
    scanf(" %c %d", &data[i], &freq[i]);
    if (freq[i] <= 0) {
        printf("Frequency must be positive.\n");
        return 1;
    }
}
huffman(data, freq, n);
return 0;
}
