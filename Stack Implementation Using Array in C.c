#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

// Structure for stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Initialize top to -1 to indicate an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value; // Push element and increment top
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--]; // Pop element and decrement top
}

// Function to view the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack); // Initialize stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    display(&stack); // Display stack elements

    printf("%d popped from stack\n", pop(&stack)); // Pop an element
    display(&stack);

    printf("Top element is %d\n", peek(&stack)); // View top element

    return 0;
}

