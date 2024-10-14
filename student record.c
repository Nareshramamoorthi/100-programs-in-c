#include <stdio.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[100];
    float marks;
};

void addStudent(struct Student *students, int *count) {
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", students[*count].name);
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully!\n\n");
}

void displayStudents(struct Student *students, int count) {
    printf("List of students:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d | Name: %s | Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
    printf("\n");
}

void searchStudent(struct Student *students, int count) {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("Student found: Roll Number: %d | Name: %s | Marks: %.2f\n\n", students[i].rollNumber, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n\n");
}

void calculateAverageMarks(struct Student *students, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += students[i].marks;
    }
    float average = total / count;
    printf("Average marks of all students: %.2f\n\n", average);
}

int main() {
    struct Student students[100];  // Assume we can store up to 100 students
    int choice, studentCount = 0;

    while (1) {
        printf("Student Management System:\n");
        printf("1. Add a new student\n");
        printf("2. Display all students\n");
        printf("3. Search for a student\n");
        printf("4. Calculate average marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                calculateAverageMarks(students, studentCount);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
