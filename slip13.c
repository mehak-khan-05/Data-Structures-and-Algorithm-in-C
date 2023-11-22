#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int arr[MAX_SIZE];
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

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack->arr[stack->top--]);
    }
}

// Function to peek at the top element of the stack
void peek(const struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack->arr[stack->top]);
    }
}

// Function to display the elements of the stack
void display(const struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Display Stack\n");
        printf("0. Exit\n");
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
                peek(&stack);
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                if (isFull(&stack)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 6:
                display(&stack);
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
