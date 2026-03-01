
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int key;
    scanf("%d", &key);

    int count = 0;
    struct Node* curr = head;
    while (curr) {
        if (curr->data == key) count++;
        curr = curr->next;
    }

    printf("%d\n", count);

    curr = head;
    while (curr) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}