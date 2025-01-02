/*
Title: Merge Two Sorted Linked Lists
Description: This program merges two sorted linked lists into one sorted list.
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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSortedLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSortedLists(l1, l2->next);
    }

    return result;
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
    // Create first sorted linked list
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Create second sorted linked list
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("First Sorted Linked List: ");
    printList(l1);

    printf("Second Sorted Linked List: ");
    printList(l2);

    // Merge the two sorted linked lists
    struct Node* mergedList = mergeSortedLists(l1, l2);

    printf("Merged Sorted Linked List: ");
    printList(mergedList);

    return 0;
}
