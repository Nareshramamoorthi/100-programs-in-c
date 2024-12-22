/*
Code Name: Advanced Linked List with Sorting and Search
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

// Sort the linked list in ascending order
void sortList(struct Node** head) {
    if (*head == NULL) return;
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Search for a value in the linked list
int searchNode(struct Node* head, int key) {
    int position = 0;
    while (head != NULL) {
        if (head->data == key) {
            return position; // Return position if key is found
        }
        head = head->next;
        position++;
    }
    return -1; // Return -1 if key is not found
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
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    printf("Original List: ");
    printList(head);

    // Sort the list
    sortList(&head);
    printf("Sorted List: ");
    printList(head);

    // Search for a node
    int key = 20;
    int position = searchNode(head, key);
    if (position != -1) {
        printf("Element %d found at position %d\n", key, position);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    return 0;
}
