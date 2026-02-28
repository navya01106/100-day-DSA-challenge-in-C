/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node *deleteFirst(struct Node *head, int key) {
    if (head == NULL) return NULL;
    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;
    if (curr->next != NULL) {
        struct Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
    return head;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    int key;
    scanf("%d", &key);
    head = deleteFirst(head, key);
    struct Node *curr = head;
    while (curr) {
        printf("%d", curr->data);
        if (curr->next) printf(" ");
        curr = curr->next;
    }
    printf("\n");
    return 0;
}