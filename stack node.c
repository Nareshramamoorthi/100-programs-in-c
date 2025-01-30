#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to display the stack
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack); // Output: 30 -> 20 -> 10 -> NULL

    printf("Popped: %d\n", pop(&stack)); // Output: 30
    display(stack); // Output: 20 -> 10 -> NULL

    return 0;
}
