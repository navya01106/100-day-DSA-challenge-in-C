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

void rotateRight(struct Node** head, int k) {
    if (*head == NULL || (*head)->next == NULL || k == 0)
        return;

    struct Node* current = *head;
    int length = 1;
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    current->next = *head;
    k = k % length;
    int stepsToNewHead = length - k;

    for (int i = 0; i < stepsToNewHead; i++) {
        current = current->next;
    }

    *head = current->next;
    current->next = NULL;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    rotateRight(&head, k);
    printList(head);

    return 0;
}