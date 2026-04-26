#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, s;
    scanf("%d", &n);
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);
    int* visited = (int*)calloc(n, sizeof(int));
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    visited[s] = 1;
    queue[rear++] = s;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int i = 0; i < n; i++) {
            if (adj[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(queue);
    return 0;
}