#include <stdio.h>
#define SIZE 5

// Circular Queue structure
typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return (q->front == 0 && q->rear == SIZE - 1) || (q->rear == (q->front - 1) % (SIZE - 1));
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }

    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }

    return value;
}

// Display the queue elements
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue is now full

    displayQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    displayQueue(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);

    displayQueue(&q);

    return 0;
}
