#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); 
}

// Function to get precedence of operators
int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to push an element to the stack
void push(char* stack, int* top, char c) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1); 
    }
    stack[++(*top)] = c;
}

// Function to pop an element from the stack
char pop(char* stack, int* top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        exit(1); 
    }
    return stack[(*top)--];
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1; 
    int i, j=0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i]; 
        } else if (infix[i] == '(') { 
            push(stack, &top, '(');
        } else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top); 
            }
            if (top == -1 || stack[top] != '(') {
                printf("Mismatched parentheses\n");
                exit(1); 
            }
            pop(stack, &top); 
        } else if (isOperator(infix[i])) {
            while (top > -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(stack, &top); 
            }
            push(stack, &top, infix[i]);
        }
    }

    while (top > -1) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
