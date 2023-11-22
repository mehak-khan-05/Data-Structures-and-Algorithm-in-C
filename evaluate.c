#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return '\0'; // Return a special value to indicate underflow
    } else {
        return stack->arr[stack->top--];
    }
}

char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return '\0'; // Return a special value to indicate empty stack
    } else {
        return stack->arr[stack->top];
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}


char *infixToPostfix(char *infix) {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        if (isOperator(infix[i])) {
            while (!isEmpty(s) && precedence(infix[i]) <= precedence(peek(s))) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
            i++;
        } else {
            postfix[j++] = infix[i++];
        }
    }
    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *infix = "a-b";
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", infixToPostfix(infix));
    return 0;
}
