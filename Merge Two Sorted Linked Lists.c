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
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->data <= list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        return list2;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two sorted linked lists
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
