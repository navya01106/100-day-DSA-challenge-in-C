/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* node) {
    // 1. Base Case: If the tree is empty (node is NULL), height is -1.
    if (node == NULL)
        return -1;

    // 2. Recursive Step: Find the height of left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // 3. Calculation: Return the larger of the two, plus 1 for the current edge
    if (leftHeight > rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

int main() {

    
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the binary tree is: %d\n", height(root));

    // Free memory (optional for simple scripts, but good practice)
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
