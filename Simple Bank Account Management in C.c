#include <stdio.h>

// Structure to hold account details
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function to deposit money
void deposit(struct Account *acc, float amount) {
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    acc->balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, acc->balance);
}

// Function to withdraw money
void withdraw(struct Account *acc, float amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    if (amount > acc->balance) {
        printf("Insufficient balance. Current balance: %.2f\n", acc->balance);
        return;
    }
    acc->balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, acc->balance);
}

// Function to display account details
void displayAccount(struct Account acc) {
    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

int main() {
    struct Account acc;

    // Input account details
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]%*c", acc.name); // To handle spaces in names
    acc.balance = 0.0; // Initialize balance

    int choice;
    float amount;

    do {
        printf("\nBanking Menu:\n");
        printf("1. Deposit\n2. Withdraw\n3. View Account Details\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;
            case 3:
                displayAccount(acc);
                break;
            case 4:
                printf("Exiting... Thank you for using our service!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
