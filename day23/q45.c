#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            appendNode(&h