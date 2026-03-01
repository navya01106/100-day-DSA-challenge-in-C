#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
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
            node->prev = tail;
            tail = node;
        }
    }

    struct Node* curr = head;
    while (curr) {
        if (curr->next)
            printf("%d ", curr->data);
        else
            printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while (curr) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}