#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

// Function to add an element to the queue
void enqueue(struct Node** stack1, int data) {
    push(stack1, data);
}

// Function to remove an element from the queue
int dequeue(struct Node** stack1, struct Node** stack2) {
    if (*stack2 == NULL) {
        while (*stack1 != NULL) {
            int data = pop(stack1);
            push(stack2, data);
        }
    }
    return pop(stack2);
}

// Function to display the queue elements
void displayQueue(struct Node* stack1, struct Node* stack2) {
    struct Node* temp1 = stack1;
    struct Node* temp2 = stack2;

    printf("Queue: ");
    while (temp2 != NULL) {
        printf("%d <- ", temp2->data);
        temp2 = temp2->next;
    }
    while (temp1 != NULL) {
        printf("%d <- ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack1 = NULL;
    struct Node* stack2 = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&stack1, value);
                break;
            case 2:
                value = dequeue(&stack1, &stack2);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(stack1, stack2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
