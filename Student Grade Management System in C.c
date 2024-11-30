#include <stdio.h>

// Structure to store student information
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function to input student data
void inputStudentData(struct Student *student) {
    printf("Enter Student ID: ");
    scanf("%d", &student->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]%*c", student->name); // To handle spaces in name
    printf("Enter Marks: ");
    scanf("%f", &student->marks);
}

// Function to display student data
void displayStudentData(struct Student student) {
    printf("\nStudent ID: %d\n", student.id);
    printf("Student Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);

    if (student.marks >= 90) {
        printf("Grade: A\n");
    } else if (student.marks >= 75) {
        printf("Grade: B\n");
    } else if (student.marks >= 50) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }
}

int main() {
    struct Student student;

    inputStudentData(&student);
    displayStudentData(student);

    return 0;
}
