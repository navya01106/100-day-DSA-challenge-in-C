int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    
    // Initialize a queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    // Prepare the result arrays
    int** result = (int**)malloc(10000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    
    while (front < rear) {
        int levelSize = rear - front;
        int* levelValues = (int*)malloc(levelSize * sizeof(int));
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* currentNode = queue[front++];
            levelValues[i] = currentNode->val;
            
            if (currentNode->left != NULL) {
                queue[rear++] = currentNode->left;
            }
            if (currentNode->right != NULL) {
                queue[rear++] = currentNode->right;
            }
        }
        
        result[*returnSize] = levelValues;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }
    
    free(queue);
    return result;

}