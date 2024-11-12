#include <stdio.h>
#define SIZE 5  // Define the maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to add an element to the circular queue
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Queue is full!\n");
        return;
    } else if (front == -1) {  // First element insertion
        front = rear = 0;
        queue[rear] = value;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[front];
    queue[front] = -1;
    if (front == rear) {  // Queue has only one element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Dequeued %d\n", data);
    return data;
}

// Function to display the elements in the circular queue
void displayQueue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
