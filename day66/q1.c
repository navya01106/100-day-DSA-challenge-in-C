#include <stdio.h>
#include <stdlib.h>

int hasCycle;

void dfs(int u, int** adj, int* visited, int* recStack, int n) {
    visited[u] = 1;
    recStack[u] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[u][i]) {
            if (!visited[i]) {
                dfs(i, adj, visited, recStack, n);
            } else if (recStack[i]) {
                hasCycle = 1;
            }
        }
    }
    recStack[u] = 0;
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
    int* recStack = (int*)calloc(n, sizeof(int));
    hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, recStack, n);
        }
    }
    if (hasCycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(recStack);
    return 0;
}