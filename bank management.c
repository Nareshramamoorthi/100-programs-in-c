#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

void createAccount(struct Account *accounts, int *count) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*count].accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]%*c", accounts[*count].accountHolder);
    accounts[*count].balance = 0.0;  // New account starts with zero balance
    (*count)++;
    printf("Account created successfully!\n\n");
}

void displayAccounts(struct Account *accounts, int count) {
    printf("List of accounts:\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
    printf("\n");
}

void deposit(struct Account *accounts, int count) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited %.2f to account %d. New balance: %.2f\n\n", amount, accNum, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n\n");
}

void withdraw(struct Account *accounts, int count) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawn %.2f from account %d. New balance: %.2f\n\n", amount, accNum, accounts[i].balance);
            } else {
                printf("Insufficient balance!\n\n");
            }
            return;
        }
    }
    printf("Account not found!\n\n");
}

void checkBalance(struct Account *accounts, int count) {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Number: %d | Name: %s | Balance: %.2f\n\n",
                   accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n\n");
}

int main() {
    struct Account accounts[100];  // Assume the system can store up to 100 accounts
    int choice, accountCount = 0;

    while (1) {
        printf("Bank Account Management System:\n");
        printf("1. Create a new account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Check account balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                displayAccounts(accounts, accountCount);
                break;
            case 3:
                deposit(accounts, accountCount);
                break;
            case 4:
                withdraw(accounts, accountCount);
                break;
            case 5:
                checkBalance(accounts, accountCount);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
