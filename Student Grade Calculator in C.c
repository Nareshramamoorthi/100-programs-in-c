#include <stdio.h>

// Function to calculate grade based on marks
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

int main() {
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    float marks[n];
    char grades[n];

    // Input marks for each student
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);
        grades[i] = calculateGrade(marks[i]);
    }

    // Display grades
    printf("\nStudent Grades:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Marks = %.2f, Grade = %c\n", i + 1, marks[i], grades[i]);
    }

    return 0;
}
