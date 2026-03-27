#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) { curr->left = newNode(arr[i]); queue[rear++] = curr->left; }
        i++;
        if (i < n && arr[i] != -1) { curr->right = newNode(arr[i]); queue[rear++] = curr->right; }
        i++;
    }
    free(queue);
    return root;
}

// Queue node storing tree node + horizontal distance
typedef struct {
    struct Node* node;
    int hd;
} QItem;

void verticalOrder(struct Node* root, int n) {
    if (!root) return;

    // Find min and max horizontal distance
    QItem* queue = (QItem*)malloc(n * sizeof(QItem));
    int front = 0, rear = 0;

    queue[rear++] = (QItem){root, 0};
    int minHD = 0, maxHD = 0;

    // Store all nodes with their HD
    QItem* allNodes = (QItem*)malloc(n * sizeof(QItem));
    int count = 0;

    while (front < rear) {
        QItem curr = queue[front++];
        struct Node* node = curr.node;
        int hd = curr.hd;

        allNodes[count++] = curr;
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)  queue[rear++] = (QItem){node->left,  hd - 1};
        if (node->right) queue[rear++] = (QItem){node->right, hd + 1};
    }

    // Print column by column
    for (int col = minHD; col <= maxHD; col++) {
        int first = 1;
        for (int i = 0; i < count; i++) {
            if (allNodes[i].hd == col) {
                if (!first) printf(" ");
                printf("%d", allNodes[i].node->data);
                first = 0;
            }
        }
        printf("\n");
    }

    free(queue);
    free(allNodes);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);

    free(arr);
    return 0;
}
