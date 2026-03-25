/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Base Case: If the tree/subtree is empty, create the node here.
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Recursive Step:
    // If val is less than current node, go left
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } 
    // If val is greater than current node, go right
    else {
        root->right = insertIntoBST(root->right, val);
    }

    // Return the root node (so the parent can link to it)
    return root;
}