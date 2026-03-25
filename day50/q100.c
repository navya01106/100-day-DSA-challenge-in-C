/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Traverse while root is valid and value hasn't been found
    while (root != NULL && root->val != val) {
        // Decide direction: left if smaller, right if larger
        if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    // Return the node (found) or NULL (not found)
    return root;
}