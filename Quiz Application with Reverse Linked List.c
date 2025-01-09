/*
Title: Quiz Application with Reverse Linked List
Description: A quiz app using linked lists to store questions and display them in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a quiz question in the linked list
typedef struct QuestionNode {
    char question[256];
    char options[4][100];
    char correctOption;
    struct QuestionNode* next;
} QuestionNode;

// Function to create a new question node
QuestionNode* createNode(const char* question, const char* options[], char correctOption) {
    QuestionNode* newNode = (QuestionNode*)malloc(sizeof(QuestionNode));
    strcpy(newNode->question, question);
    for (int i = 0; i < 4; i++) {
        strcpy(newNode->options[i], options[i]);
    }
    newNode->correctOption = correctOption;
    newNode->next = NULL;
    return newNode;
}

// Function to add a question node at the end of the list
void appendNode(QuestionNode** head, QuestionNode* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        QuestionNode* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to reverse the linked list
QuestionNode* reverseList(QuestionNode* head) {
    QuestionNode *prev = NULL, *current = head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to display the quiz questions
void displayQuestions(QuestionNode* head) {
    QuestionNode* temp = head;
    int questionNumber = 1;
    while (temp) {
        printf("\nQuestion %d: %s\n", questionNumber++, temp->question);
        for (int i = 0; i < 4; i++) {
            printf("%c. %s\n", 'A' + i, temp->options[i]);
        }
        temp = temp->next;
    }
}

int main() {
    QuestionNode* quizList = NULL;
    char userAnswer;
    int score = 0;

    // Adding questions to the linked list
    const char* options1[] = {"New Delhi", "Mumbai", "Kolkata", "Chennai"};
    appendNode(&quizList, createNode("What is the capital of India?", options1, 'A'));

    const char* options2[] = {"Charles Babbage", "Alan Turing", "John von Neumann", "Ada Lovelace"};
    appendNode(&quizList, createNode("Who is known as the father of computers?", options2, 'A'));

    const char* options3[] = {"Earth", "Mars", "Jupiter", "Venus"};
    appendNode(&quizList, createNode("Which planet is known as the Red Planet?", options3, 'B'));

    printf("Welcome to the Quiz Application!\n");
    printf("Answer the questions by typing A, B, C, or D.\n");

    // Traverse the list and ask questions
    QuestionNode* temp = quizList;
    int questionNumber = 1;

    while (temp) {
        printf("\nQuestion %d: %s\n", questionNumber++, temp->question);
        for (int i = 0; i < 4; i++) {
            printf("%c. %s\n", 'A' + i, temp->options[i]);
        }
        printf("Your Answer: ");
        scanf(" %c", &userAnswer);

        if (userAnswer == temp->correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c.\n", temp->correctOption);
        }

        temp = temp->next;
    }

    // Display final score
    printf("\nQuiz Over! Your Score: %d\n", score);

    // Reverse the linked list and display questions in reverse order
    printf("\nReviewing Questions in Reverse Order:\n");
    quizList = reverseList(quizList);
    displayQuestions(quizList);

    return 0;
}
