/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/
void flatten(struct TreeNode* root) {
    while (root) {
        if (root->left) {
            struct TreeNode* pre = root->left;
            while (pre->right) pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}