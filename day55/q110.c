int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(101 * sizeof(struct TreeNode*));
    int* result = (int*)malloc(101 * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];

            if (i == levelSize - 1)
                result[(*returnSize)++] = curr->val;

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }

    free(queue);
    return result;
}