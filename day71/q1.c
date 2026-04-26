#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, q;
    scanf("%d %d", &m, &q);
    int* hashTable = (int*)malloc(m * sizeof(int));
    int* occupied = (int*)calloc(m, sizeof(int));
    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        int h = key % m;
        if (strcmp(op, "INSERT") == 0) {
            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;
                if (!occupied[idx]) {
                    hashTable[idx] = key;
                    occupied[idx] = 1;
                    break;
                }
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;
                if (occupied[idx] && hashTable[idx] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    free(hashTable);
    free(occupied);
    return 0;
}