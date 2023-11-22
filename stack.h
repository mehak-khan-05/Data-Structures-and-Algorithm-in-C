

#define MAX_SIZE 100 // Maximum size of the stack

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize an empty stack
void initialize(Stack *stack);

// Function to check if the stack is empty
int isEmpty(Stack *stack);

// Function to check if the stack is full
int isFull(Stack *stack);

// Function to push an element onto the stack
void push(Stack *stack, int value);

// Function to pop an element from the stack
int pop(Stack *stack);

// Function to return the top element of the stack without removing it
int peek(Stack *stack);

