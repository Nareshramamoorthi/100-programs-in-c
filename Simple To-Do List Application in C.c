#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_LENGTH 100

// Function to display all tasks
void displayTasks(char tasks[][MAX_LENGTH], int count) {
    if (count == 0) {
        printf("No tasks to display.\n");
    } else {
        printf("\nYour To-Do List:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

// Function to add a task
void addTask(char tasks[][MAX_LENGTH], int *count) {
    if (*count >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
    } else {
        printf("Enter the task: ");
        getchar(); // Clear newline from the buffer
        fgets(tasks[*count], MAX_LENGTH, stdin);
        tasks[*count][strcspn(tasks[*count], "\n")] = 0; // Remove trailing newline
        (*count)++;
        printf("Task added successfully!\n");
    }
}

// Function to delete a task
void deleteTask(char tasks[][MAX_LENGTH], int *count) {
    if (*count == 0) {
        printf("No tasks to delete.\n");
    } else {
        int taskNumber;
        displayTasks(tasks, *count);
        printf("Enter the task number to delete: ");
        scanf("%d", &taskNumber);

        if (taskNumber < 1 || taskNumber > *count) {
            printf("Invalid task number.\n");
        } else {
            for (int i = taskNumber - 1; i < *count - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);
            }
            (*count)--;
            printf("Task deleted successfully!\n");
        }
    }
}

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int taskCount = 0;
    int choice;

    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTasks(tasks, taskCount);
                break;
            case 2:
                addTask(tasks, &taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting... Have a productive day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
