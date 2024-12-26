

/*
Title: Sorted Insertion in a Linked List
Description: This program inserts elements into a linked list while maintaining sorted order.
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

// Function to insert a node in sorted order
void sortedInsert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // Special case: If the list is empty or new node should be the head
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Locate the node after which the new node should be inserted
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
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

    // Insert elements
    sortedInsert(&head, 30);
    sortedInsert(&head, 10);
    sortedInsert(&head, 20);
    sortedInsert(&head, 40);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
