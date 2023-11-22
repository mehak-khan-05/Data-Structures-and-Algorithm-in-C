#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
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

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed to the stack.\n", value);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1; // Return a special value to indicate underflow
    } else {
        return stack->arr[stack->top--];
    }
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a special value to indicate empty stack
    } else {
        return stack->arr[stack->top];
    }
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

void reverse(struct Stack *stack) {
    int size = stack->top + 1;
    int *tempArray = malloc(size * sizeof(int));

    if (tempArray == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Copy elements to a temporary array
    for (int i = 0; i < size; ++i) {
        tempArray[i] = pop(stack);
    }

    // Copy elements back to the stack
    for (int i = 0; i < size; ++i) {
        push(stack, tempArray[i]);
    }

    free(tempArray);
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Reverse\n");
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
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                reverse(&stack);
                printf("Stack reversed.\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
