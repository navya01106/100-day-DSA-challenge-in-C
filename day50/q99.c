/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root && root->val != val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}