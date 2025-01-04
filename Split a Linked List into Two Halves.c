/*
Title: Split a Linked List into Two Halves
Description: This program splits a singly linked list into two halves.
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

// Function to split the linked list into two halves
void splitList(struct Node* head, struct Node** firstHalf, struct Node** secondHalf) {
    if (head == NULL || head->next == NULL) {
        *firstHalf = head;
        *secondHalf = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = NULL;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;

    // Creating a linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(head);

    // Split the list into two halves
    splitList(head, &firstHalf, &secondHalf);

    printf("First Half: ");
    printList(firstHalf);

    printf("Second Half: ");
    printList(secondHalf);

    return 0;
}
