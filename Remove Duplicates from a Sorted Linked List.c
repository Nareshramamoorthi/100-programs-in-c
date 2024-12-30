/*
Title: Remove Duplicates from a Sorted Linked List
Description: This program removes duplicate elements from a sorted linked list.
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

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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

    // Creating a sorted linked list with duplicates
    head = createNode(10);
    head->next = createNode(10);
    head->next->next = createNode(20);
    head->next->next->next = createNode(20);
    head->next->next->next->next = createNode(30);

    printf("Original Sorted Linked List: ");
    printList(head);

    // Remove duplicates from the list
    removeDuplicates(head);

    printf("Linked List After Removing Duplicates: ");
    printList(head);

    return 0;
}
