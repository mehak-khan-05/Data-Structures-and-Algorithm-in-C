#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->items[++(stack->top)] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;
    char token, topToken;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isOperand(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while ((topToken = pop(&stack)) != '(') {
                postfix[j++] = topToken;
            }
        } else {
            while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infixExpression[] = "A+B*(C-D)/E";
    char postfixExpression[MAX_SIZE];

    infixToPostfix(infixExpression, postfixExpression);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    return 0;
}
