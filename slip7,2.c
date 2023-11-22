#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char array[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(str);
    int i;

    // Push the first half of the string onto the stack
    for (i = 0; i < length / 2; i++) {
        push(&stack, str[i]);
    }

    // If the length is odd, skip the middle character
    if (length % 2 != 0) {
        i++;
    }

    // Pop and compare the second half of the string
    while (str[i] != '\0') {
        char top = pop(&stack);

        if (top != str[i]) {
            return 0; // Not a palindrome
        }

        i++;
    }

    return 1; // Palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
