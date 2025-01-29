#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3  // Define LRU Cache Capacity

// Doubly Linked List Node
typedef struct Node {
    int key, value;
    struct Node* prev, *next;
} Node;

// Hash Map (Array-based) for Quick Lookup
Node* hashTable[100] = { NULL };

// LRU Cache Structure
typedef struct {
    Node* head, *tail;
    int size;
} LRUCache;

// Function to Create a New Node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to Initialize LRU Cache
LRUCache* initCache() {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = cache->tail = NULL;
    cache->size = 0;
    return cache;
}

// Function to Move a Node to the Front (Most Recently Used)
void moveToFront(LRUCache* cache, Node* node) {
    if (cache->head == node) return; // Already at front

    // Remove node from current position
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (cache->tail == node) cache->tail = node->prev;

    // Move to front
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
}

// Function to Add a Node to LRU Cache
void put(LRUCache* cache, int key, int value) {
    if (hashTable[key] != NULL) { // If Key Exists, Update and Move to Front
        hashTable[key]->value = value;
        moveToFront(cache, hashTable[key]);
    } else { // New Entry
        Node* newNode = createNode(key, value);
        hashTable[key] = newNode;

        if (cache->size == CAPACITY) { // If Full, Remove LRU
            hashTable[cache->tail->key] = NULL;
            cache->tail = cache->tail->prev;
            free(cache->tail->next);
            cache->tail->next = NULL;
            cache->size--;
        }

        // Add to Front
        newNode->next = cache->head;
        if (cache->head) cache->head->prev = newNode;
        cache->head = newNode;
        if (cache->size == 0) cache->tail = newNode;
        cache->size++;
    }
}

// Function to Get Value from LRU Cache
int get(LRUCache* cache, int key) {
    if (hashTable[key] == NULL) return -1; // Not Found
    moveToFront(cache, hashTable[key]);
    return hashTable[key]->value;
}

// Function to Display LRU Cache
void display(LRUCache* cache) {
    Node* temp = cache->head;
    while (temp) {
        printf("%d:%d ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Main Function
int main() {
    LRUCache* cache = initCache();

    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);
    display(cache); // Output: 3:30 2:20 1:10

    put(cache, 4, 40); // Removes least used (1)
    display(cache); // Output: 4:40 3:30 2:20

    printf("Get(3): %d\n", get(cache, 3)); // Output: 30
    display(cache); // Output: 3:30 4:40 2:20

    return 0;
}
