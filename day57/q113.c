/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = newNode(arr[0]);
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void mirror(Node* root) {
    if (!root) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root, int* first) {
    if (!root) return;
    inorder(root->left, first);
    if (!*first) printf(" ");
    printf("%d", root->data);
    *first = 0;
    inorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node* root = buildTree(arr, n);
    mirror(root);
    int first = 1;
    inorder(root, &first);
    printf("\n");
    return 0;
}