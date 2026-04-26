#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex;
    int dist;
} Node;

typedef struct {
    Node* arr;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->arr = (Node*)malloc(capacity * sizeof(Node));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->arr[parent].dist > pq->arr[idx].dist) {
            swap(&pq->arr[parent], &pq->arr[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void push(PriorityQueue* pq, int vertex, int dist) {
    if (pq->size < pq->capacity) {
        pq->arr[pq->size].vertex = vertex;
        pq->arr[pq->size].dist = dist;
        heapifyUp(pq, pq->size);
        pq->size++;
    }
}

void heapifyDown(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < pq->size && pq->arr[left].dist < pq->arr[smallest].dist) {
        smallest = left;
    }
    if (right < pq->size && pq->arr[right].dist < pq->arr[smallest].dist) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&pq->arr[smallest], &pq->arr[idx]);
        heapifyDown(pq, smallest);
    }
}

Node pop(PriorityQueue* pq) {
    Node minNode = pq->arr[0];
    pq->size--;
    pq->arr[0] = pq->arr[pq->size];
    heapifyDown(pq, 0);
    return minNode;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
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
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    PriorityQueue* pq = createQueue(n * n);
    push(pq, 0, 0);
    while (!isEmpty(pq)) {
        Node u = pop(pq);
        if (u.dist > dist[u.vertex]) {
            continue;
        }
        for (int v = 0; v < n; v++) {
            if (adj[u.vertex][v] != 0) {
                if (dist[u.vertex] + adj[u.vertex][v] < dist[v]) {
                    dist[v] = dist[u.vertex] + adj[u.vertex][v];
                    push(pq, v, dist[v]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(dist);
    free(pq->arr);
    free(pq);
    return 0;
}