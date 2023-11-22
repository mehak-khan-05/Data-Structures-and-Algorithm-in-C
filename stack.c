#include <stdio.h>
#include "stack.h"

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    } else {
        printf("Error: Stack is full. Cannot push %d.\n", value);
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        int value = stack->data[stack->top--];
        printf("Popped %d from the stack.\n", value);
        return value;
    } else {
        printf("Error: Stack is empty. Cannot pop.\n");
        return -1; // You can choose a specific value to indicate an error
    }
}

int peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("Error: Stack is empty. Cannot peek.\n");
        return -1; // You can choose a specific value to indicate an error
    }
}


int main() {
    Stack stack;
    initialize(&stack);

    int choice, value;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                printf("Top element: %d\n", peek(&stack));
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
