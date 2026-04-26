#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    int hasNegCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegCycle = 1;
            break;
        }
    }
    if (hasNegCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }
    free(edges);
    free(dist);
    return 0;
}