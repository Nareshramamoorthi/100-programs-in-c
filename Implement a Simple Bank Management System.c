#include <stdio.h>
#include <string.h>

struct BankAccount {
    char name[50];
    int accountNumber;
    float balance;
};

void createAccount(struct BankAccount *account) {
    printf("Enter account holder's name: ");
    scanf("%s", account->name);
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    account->balance = 0.0;
    printf("Account created successfully!\n\n");
}

void depositMoney(struct BankAccount *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Amount successfully deposited!\n\n");
}

void withdrawMoney(struct BankAccount *account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > account->balance) {
        printf("Insufficient balance!\n\n");
    } else {
        account->balance -= amount;
        printf("Amount successfully withdrawn!\n\n");
    }
}

void checkBalance(struct BankAccount *account) {
    printf("Account holder: %s\n", account->name);
    printf("Account number: %d\n", account->accountNumber);
    printf("Current balance: %.2f\n\n", account->balance);
}

int main() {
    struct BankAccount account;
    int choice;

    while (1) {
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                depositMoney(&account);
                break;
            case 3:
                withdrawMoney(&account);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    }
    return 0;
}
