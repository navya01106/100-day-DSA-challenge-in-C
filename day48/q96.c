/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    // 1. Base Case: If the tree is empty, sum is 0
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    // 2. Check if the left child exists
    if (root->left != NULL) {
        // Check if the left child is a leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            // It is a left leaf, add its value
            sum += root->left->val;
        } else {
            // It is not a leaf, recurse down the left subtree
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // 3. Always recurse down the right subtree to find other left leaves
    sum += sumOfLeftLeaves(root->right);

    return sum;
}