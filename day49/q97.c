#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        return createNode(val);
    }

    // Pointer to traverse the tree
    struct TreeNode* current = root;
    
    // Pointer to keep track of the parent node (to attach the new node)
    struct TreeNode* parent = NULL;

    // Traverse the tree to find the insertion point
    while (current != NULL) {
        parent = current;
        if (val < current->val) {
            current = current->left;
        } else if (val > current->val) {
            current = current->right;
        } else {
            // Value already exists; depending on requirements, 
            // you might return here or allow duplicates (usually BSTs are unique).
            // Here we assume unique values and simply return.
            return root; 
        }
    }

    // Insert the new node as a child of the parent
    if (val < parent->val) {
        parent->left = createNode(val);
    } else {
        parent->right = createNode(val);
    }

    return root;
}

// Helper function to print the tree (In-order traversal)
void printInOrder(struct TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->val);
        printInOrder(root->right);
    }
}

// Driver code to test the solution
int main() {
    struct TreeNode* root = NULL;
    
    // Insert values
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 8);

    // Print the tree (Should output sorted order: 2 3 4 5 6 7 8)
    printf("In-order Traversal: ");
    printInOrder(root);
    printf("\n");

    return 0;
}