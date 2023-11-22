#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        
    }
    stack->arr[++stack->top] = value;
}

// Function to check if two stacks are identical
int areStacksIdentical(struct Stack *stack1, struct Stack *stack2) {
    if (stack1->top != stack2->top) {
        return 0; // Stacks have different sizes
    }

    for (int i = 0; i <= stack1->top; ++i) {
        if (stack1->arr[i] != stack2->arr[i]) {
            return 0; // Stacks have different elements
        }
    }

    return 1; // Stacks are identical
}

int main() {
    struct Stack stack1, stack2;

    initialize(&stack1);
    initialize(&stack2);

    // Push elements onto the stacks (replace this with your actual data)
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);

    push(&stack2, 1);
    push(&stack2, 2);
    push(&stack2, 3);

    // Check if stacks are identical
    if (areStacksIdentical(&stack1, &stack2)) {
        printf("Stacks are identical\n");
    } else {
        printf("Stacks are not identical\n");
    }

    return 0;
}
