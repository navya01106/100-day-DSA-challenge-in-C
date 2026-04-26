#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int** adj = (int**)malloc(n * sizeof(int*));
    int* inDegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j]) {
                inDegree[j]++;
            }
        }
    }
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        for (int i = 0; i < n; i++) {
            if (adj[u][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(inDegree);
    free(queue);
    return 0;
}