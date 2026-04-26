#include <stdio.h>
#include <stdlib.h>

void dfs(int s, int* visited, int** adj, int n) {
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 0; i < n; i++) {
        if (adj[s][i] && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }
}

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
    dfs(s, visited, adj, n);
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    return 0;
}