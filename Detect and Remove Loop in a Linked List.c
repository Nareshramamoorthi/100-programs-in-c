/*
Title: Detect and Remove Loop in a Linked List
Description: This program detects a loop in a linked list and removes it.
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

// Detect loop in the linked list
int detectAndRemoveLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Detect loop using Floyd’s cycle-finding algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected
            removeLoop(head, slow);
            return 1;
        }
    }
    return 0;
}

// Function to remove the loop
void removeLoop(struct Node* head, struct Node* loopNode) {
    struct Node* ptr1 = head;
    struct Node* ptr2 = loopNode;

    // Find the node just before the start of the loop
    while (ptr2->next != ptr1) {
        ptr2 = ptr2->next;
        if (ptr2->next == ptr1)
            break;

        if (ptr1 != ptr2)
            ptr1 = ptr1->next;
    }
    ptr2->next = NULL; // Remove loop
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create a linked list with a loop
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = head->next; // Creates a loop

    if (detectAndRemoveLoop(head)) {
        printf("Loop detected and removed.\n");
    } else {
        printf("No loop detected.\n");
    }

    printf("Linked List after removing the loop: ");
    printList(head);

    return 0;
}
