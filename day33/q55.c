
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char* expression) {
    int len = strlen(expression);
    
    for (int i = 0; i < len; i++) {
        char c = expression[i];
        
        // If operand, print it
        if (isalnum(c)) {
            printf("%c", c);
        }
        
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            if (top != -1) {
                pop(); // Remove '(' from stack
            }
        }
        
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }
    
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char expression[MAX_SIZE];
    
    if (fgets(expression, sizeof(expression), stdin)) {
        expression[strcspn(expression, "\n")] = 0;
        infixToPostfix(expression);
    }
    
    return 0;
}