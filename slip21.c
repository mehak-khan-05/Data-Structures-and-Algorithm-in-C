#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(const struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(const struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
      
    }
    stack->arr[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        
    }
    return stack->arr[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char *str) {
    int len = strlen(str);

    struct Stack stack;
    initialize(&stack);

    // Push each character onto the stack
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
