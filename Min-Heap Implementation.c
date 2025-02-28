#include <stdio.h>

#define MAX 100

int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    size++;
}

int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (2 * i + 1 < size) {
        int smallest = i;
        int left = 2 * i + 1, right = 2 * i + 2;

        if (heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return min;
}

void display() {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(5);
    insert(20);
    insert(2);
    insert(15);

    display();

    printf("Extracted Min: %d\n", extractMin());
    display();

    return 0;
}
