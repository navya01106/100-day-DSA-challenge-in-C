#include <stdio.h>
#include <stdlib.h>

int idx;

void dfs(int u, int** adj, int* visited, int* stack, int n) {
    visited[u] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[u][i] && !visited[i]) {
            dfs(i, adj, visited, stack, n);
        }
    }
    stack[idx++] = u;
}

int main() {
    int n;
    scanf("%d", &n);
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    idx = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, n);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(stack);
    return 0;
}