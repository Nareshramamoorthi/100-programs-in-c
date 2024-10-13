#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int id;
    int available;  // 1 if available, 0 if borrowed
};

void addBook(struct Book *books, int *count) {
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", books[*count].title);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", books[*count].author);
    books[*count].id = *count + 1;
    books[*count].available = 1;  // Mark the book as available when added
    (*count)++;
    printf("Book added successfully!\n\n");
}

void displayBooks(struct Book *books, int count) {
    printf("Available books in the library:\n");
    for (int i = 0; i < count; i++) {
        if (books[i].available) {
            printf("ID: %d | Title: %s | Author: %s\n", books[i].id, books[i].title, books[i].author);
        }
    }
    printf("\n");
}

void borrowBook(struct Book *books, int count) {
    int id;
    printf("Enter the book ID to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id && books[i].available) {
            books[i].available = 0;  // Mark as borrowed
            printf("You borrowed: %s by %s\n\n", books[i].title, books[i].author);
            return;
        }
    }
    printf("Book not available for borrowing!\n\n");
}

void returnBook(struct Book *books, int count) {
    int id;
    printf("Enter the book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id && !books[i].available) {
            books[i].available = 1;  // Mark as available
            printf("You returned: %s by %s\n\n", books[i].title, books[i].author);
            return;
        }
    }
    printf("Invalid book ID or the book wasn't borrowed!\n\n");
}

int main() {
    struct Book library[100];  // Assume a library can hold 100 books
    int choice, bookCount = 0;

    while (1) {
        printf("Library Management System:\n");
        printf("1. Add a new book\n");
        printf("2. Display available books\n");
        printf("3. Borrow a book\n");
        printf("4. Return a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                borrowBook(library, bookCount);
                break;
            case 4:
                returnBook(library, bookCount);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
