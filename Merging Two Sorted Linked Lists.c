/*
Title: Merging Two Sorted Linked Lists
Description: This program merges two sorted linked lists into a single sorted list.
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

// Merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* mergedHead = NULL;

    if (l1->data <= l2->data) {
        mergedHead = l1;
        mergedHead->next = mergeSortedLists(l1->next, l2);
    } else {
        mergedHead = l2;
        mergedHead->next = mergeSortedLists(l1, l2->next);
    }

    return mergedHead;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create first sorted linked list
    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 20);
    insertAtEnd(&list1, 30);

    // Create second sorted linked list
    insertAtEnd(&list2, 15);
    insertAtEnd(&list2, 25);
    insertAtEnd(&list2, 35);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted List: ");
    printList(mergedList);

    return 0;
}
