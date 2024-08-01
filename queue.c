#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue* q) { return (q->front == q->rear - 1); }

bool isFull(Queue* q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue* q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

void dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

int peek(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front + 1];
}

void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    printQueue(&q);

    enqueue(&q, 20);
    printQueue(&q);

    enqueue(&q, 30);
    printQueue(&q);

    printf("Front element: %d\n", peek(&q));

    dequeue(&q);
    printQueue(&q);

    printf("Front element after dequeue: %d\n", peek(&q));

    return 0;
}
