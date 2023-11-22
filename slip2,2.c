#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return;
    }
    return stack->arr[stack->top--];
}

// Function to copy the content of one stack into another while maintaining the order
void copyStack(Stack *source, Stack *destination) {
    Stack temp; // Auxiliary stack to reverse the order

    initialize(&temp);

    // Push elements from source to temp to reverse the order
    while (!isEmpty(source)) {
        push(&temp, pop(source));
    }

    // Push elements from temp to destination to maintain the order
    while (!isEmpty(&temp)) {
        push(destination, pop(&temp));
    }
}

void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack1, stack2;

    initialize(&stack1);
    initialize(&stack2);

    // Push some elements onto stack1
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);

    // Display stack1
    printf("Original ");
    displayStack(&stack1);

    // Copy stack1 to stack2 while maintaining the order
    copyStack(&stack1, &stack2);

    // Display stack2
    printf("Copied ");
    displayStack(&stack2);

    return 0;
}
