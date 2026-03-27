int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(2001 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int** result = (int**)malloc(2001 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2001 * sizeof(int));

    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];
            level[i] = curr->val;
            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        if (!leftToRight) {
            int lo = 0, hi = levelSize - 1;
            while (lo < hi) {
                int tmp = level[lo];
                level[lo++] = level[hi];
                level[hi--] = tmp;
            }
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    free(queue);
    return result;
}