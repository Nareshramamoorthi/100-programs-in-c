/*
Title: Advanced Linked List - Middle Element Finder
Description: This program performs linked list operations like insertion, deletion, and finding the middle element.
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

// Insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete a node by position
void deleteNodeByPosition(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // If the head is to be deleted
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL || temp->next == NULL) return;

    struct Node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next;
}

// Find the middle element of the linked list
void findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL) {
        printf("Middle Element: %d\n", slow->data);
    }
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

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List: ");
    printList(head);

    // Find the middle element
    findMiddle(head);

    // Delete a node by position
    deleteNodeByPosition(&head, 2);
    printf("After Deletion at Position 2: ");
    printList(head);

    // Find the middle element again
    findMiddle(head);

    return 0;
}
