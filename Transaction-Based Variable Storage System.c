#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100
#define MAX_TRANSACTIONS 10

typedef struct {
    char name[20];
    int value;
    int is_set;
} Variable;

typedef struct {
    Variable vars[MAX_VARS];
    int count;
} Transaction;

Variable database[MAX_VARS];
Transaction transactions[MAX_TRANSACTIONS];
int db_count = 0, trans_count = 0;

// Function to find a variable
int find_variable(char *name) {
    for (int i = 0; i < db_count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// SET Command
void set_variable(char *name, int value) {
    int idx = find_variable(name);
    if (idx == -1) {
        strcpy(database[db_count].name, name);
        database[db_count].value = value;
        database[db_count].is_set = 1;
        db_count++;
    } else {
        database[idx].value = value;
    }
}

// GET Command
void get_variable(char *name) {
    int idx = find_variable(name);
    if (idx == -1 || !database[idx].is_set) {
        printf("null\n");
    } else {
        printf("%d\n", database[idx].value);
    }
}

// UNSET Command
void unset_variable(char *name) {
    int idx = find_variable(name);
    if (idx != -1) {
        database[idx].is_set = 0;
    }
}

// COUNT Command
void count_value(int value) {
    int count = 0;
    for (int i = 0; i < db_count; i++) {
        if (database[i].is_set && database[i].value == value) {
            count++;
        }
    }
    printf("%d\n", count);
}

// BEGIN Transaction
void begin_transaction() {
    if (trans_count < MAX_TRANSACTIONS) {
        transactions[trans_count] = (Transaction){.count = db_count};
        memcpy(transactions[trans_count].vars, database, sizeof(database));
        trans_count++;
    } else {
        printf("Transaction Limit Reached!\n");
    }
}

// ROLLBACK Transaction
void rollback_transaction() {
    if (trans_count > 0) {
        trans_count--;
        db_count = transactions[trans_count].count;
        memcpy(database, transactions[trans_count].vars, sizeof(database));
    } else {
        printf("No Active Transaction\n");
    }
}

// COMMIT Transaction
void commit_transaction() {
    if (trans_count > 0) {
        trans_count = 0;
    } else {
        printf("No Active Transaction\n");
    }
}

// Main Function
int main() {
    char command[10], name[20];
    int value;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "SET") == 0) {
            scanf("%s %d", name, &value);
            set_variable(name, value);
        } else if (strcmp(command, "GET") == 0) {
            scanf("%s", name);
            get_variable(name);
        } else if (strcmp(command, "UNSET") == 0) {
            scanf("%s", name);
            unset_variable(name);
        } else if (strcmp(command, "COUNT") == 0) {
            scanf("%d", &value);
            count_value(value);
        } else if (strcmp(command, "BEGIN") == 0) {
            begin_transaction();
        } else if (strcmp(command, "ROLLBACK") == 0) {
            rollback_transaction();
        } else if (strcmp(command, "COMMIT") == 0) {
            commit_transaction();
        } else if (strcmp(command, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid Command\n");
        }
    }
    return 0;
}