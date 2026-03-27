/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) { curr->left  = newNode(arr[i]); queue[rear++] = curr->left;  } i++;
        if (i < n && arr[i] != -1) { curr->right = newNode(arr[i]); queue[rear++] = curr->right; } i++;
    }
    free(queue);
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;

    struct Node** queue  = (struct Node**)malloc(n * sizeof(struct Node*));
    int*          stack  = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;
    int first = 1;

    while (front < rear) {
        int levelSize = rear - front;
        int top = 0;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];
            stack[top++] = curr->data;
            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        if (leftToRight) {
            for (int i = 0; i < top; i++) {
                if (!first) printf(" ");
                printf("%d", stack[i]);
                first = 0;
            }
        } else {
            for (int i = top - 1; i >= 0; i--) {
                if (!first) printf(" ");
                printf("%d", stack[i]);
                first = 0;
            }
        }

        leftToRight = !leftToRight;
    }
    printf("\n");

    free(queue);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root, n);

    free(arr);
    return 0;
}
