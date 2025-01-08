/*
Title: Quiz Application
Description: A simple multiple-choice quiz app with score evaluation.
*/

#include <stdio.h>

// Structure to store a quiz question
typedef struct {
    char question[256];
    char options[4][100];
    char correctOption;
} QuizQuestion;

void displayQuestion(QuizQuestion q, int questionNumber) {
    printf("\nQuestion %d: %s\n", questionNumber, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
}

int main() {
    QuizQuestion quiz[3] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Kolkata", "Chennai"},
            'A'
        },
        {
            "Who is known as the father of computers?",
            {"Charles Babbage", "Alan Turing", "John von Neumann", "Ada Lovelace"},
            'A'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            'B'
        }
    };

    int totalQuestions = 3;
    int score = 0;
    char userAnswer;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer the questions by typing A, B, C, or D.\n");

    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(quiz[i], i + 1);
        printf("Your Answer: ");
        scanf(" %c", &userAnswer);

        // Check the user's answer
        if (userAnswer == quiz[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c.\n", quiz[i].correctOption);
        }
    }

    // Display the final score
    printf("\nQuiz Over! Your Score: %d/%d\n", score, totalQuestions);

    // Feedback based on score
    if (score == totalQuestions) {
        printf("Excellent! You got everything right!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Good job! Keep improving.\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}
