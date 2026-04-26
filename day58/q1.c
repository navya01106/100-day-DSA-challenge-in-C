/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Helper: find index of value in inorder array
int findIndex(int* inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Helper: recursive builder
struct TreeNode* build(
    int* preorder, int* preIndex,
    int* inorder,  int inLeft, int inRight
) {
    // Base case: no elements to construct the tree
    if (inLeft > inRight) return NULL;

    // Step 1: Pick current root from preorder
    int rootVal = preorder[(*preIndex)++];

    // Step 2: Allocate root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val   = rootVal;
    root->left  = NULL;
    root->right = NULL;

    // Step 3: Find root in inorder → splits left & right subtrees
    int mid = findIndex(inorder, inLeft, inRight, rootVal);

    // Step 4: Recurse — LEFT subtree before RIGHT (preorder property)
    root->left  = build(preorder, preIndex, inorder, inLeft,   mid - 1);
    root->right = build(preorder, preIndex, inorder, mid + 1,  inRight);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder,  int inorderSize) {
    int preIndex = 0;
    return build(preorder, &preIndex, inorder, 0, inorderSize - 1);
}