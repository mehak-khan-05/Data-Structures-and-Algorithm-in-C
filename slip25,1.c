#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool is_empty(struct Stack* stack) {
    return stack->top == -1;
}

bool is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    return stack->items[stack->top];
}

int precedence(char operator) {
    switch (operator) {
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

void infix_to_postfix(char infix_expression[], char postfix_notation[]) {
    struct Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix_expression[i] != '\0') {
        char current_char = infix_expression[i];

        if (is_operand(current_char)) {
            postfix_notation[j++] = current_char;
        } else if (current_char == '(') {
            push(&stack, current_char);
        } else if (current_char == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix_notation[j++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(current_char)) {
                postfix_notation[j++] = pop(&stack);
            }
            push(&stack, current_char);
        }

        i++;
    }

    while (!is_empty(&stack)) {
        postfix_notation[j++] = pop(&stack);
    }

    postfix_notation[j] = '\0';
}

int main() {
    char infix_expression[] = "(a*(b+c)*((da)/b))";
    char postfix_notation[MAX_SIZE];

    infix_to_postfix(infix_expression, postfix_notation);

    printf("Infix Expression: %s\n", infix_expression);
    printf("Postfix Notation: %s\n", postfix_notation);

    return 0;
}
// abc+*dab/*