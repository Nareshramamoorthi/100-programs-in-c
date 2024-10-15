#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[100];
    float salary;
};

void addEmployee(struct Employee *employees, int *count) {
    printf("Enter employee ID: ");
    scanf("%d", &employees[*count].id);
    printf("Enter employee name: ");
    scanf(" %[^\n]%*c", employees[*count].name);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*count].salary);
    (*count)++;
    printf("Employee added successfully!\n\n");
}

void displayEmployees(struct Employee *employees, int count) {
    printf("Employee records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("\n");
}

void searchEmployee(struct Employee *employees, int count) {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee found: ID: %d | Name: %s | Salary: %.2f\n\n", employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee not found!\n\n");
}

void updateSalary(struct Employee *employees, int count) {
    int id;
    float newSalary;
    printf("Enter employee ID to update salary: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new salary: ");
            scanf("%f", &newSalary);
            employees[i].salary = newSalary;
            printf("Salary updated successfully!\n\n");
            return;
        }
    }
    printf("Employee not found!\n\n");
}

int main() {
    struct Employee employees[100];  // Assume the system can store up to 100 employees
    int choice, employeeCount = 0;

    while (1) {
        printf("Employee Management System:\n");
        printf("1. Add a new employee\n");
        printf("2. Display all employees\n");
        printf("3. Search for an employee\n");
        printf("4. Update employee salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                displayEmployees(employees, employeeCount);
                break;
            case 3:
                searchEmployee(employees, employeeCount);
                break;
            case 4:
                updateSalary(employees, employeeCount);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
