/*
Title: Detect a Loop in a Linked List
Description: This program detects whether a linked list contains a loop using the Floyd’s Cycle Detection algorithm (Tortoise and Hare).
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in the linked list using Floyd’s Cycle Detection
int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Loop detected
        }
    }
    return 0; // No loop
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating a linked list
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Original Linked List: ");
    printList(head);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head)) {
        printf("Loop detected in the linked list!\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
