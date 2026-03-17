#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top < 0) {
        // printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n, operation, value;
    
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);
        if (operation == 1) {
            scanf("%d", &value);
            push(value);
        } else if (operation == 2) {
            pop();
        } else if (operation == 3) {
            display();
        }
    }

    return 0;
}