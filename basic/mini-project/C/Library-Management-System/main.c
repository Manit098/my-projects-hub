#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int available;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    getchar(); // Clear newline
    fgets(b.title, TITLE_LENGTH, stdin);
    b.title[strcspn(b.title, "\n")] = 0; // Remove newline
    printf("Enter Author: ");
    fgets(b.author, AUTHOR_LENGTH, stdin);
    b.author[strcspn(b.author, "\n")] = 0; // Remove newline
    b.available = 1; // Default to available

    library[bookCount++] = b;
    printf("\nBook added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("\nNo books in the library!\n");
        return;
    }

    printf("\n%-10s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Available");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-20s %-10s\n", library[i].id, library[i].title, library[i].author, library[i].available ? "Yes" : "No");
    }
}

void searchBook() {
    int id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nAvailable: %s\n", library[i].id, library[i].title, library[i].author, library[i].available ? "Yes" : "No");
            return;
        }
    }
    printf("\nBook with ID %d not found!\n", id);
}

void borrowBook() {
    int id;
    printf("\nEnter Book ID to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].available) {
                library[i].available = 0;
                printf("\nYou have successfully borrowed the book: %s\n", library[i].title);
            } else {
                printf("\nSorry, the book is currently not available.\n");
            }
            return;
        }
    }
    printf("\nBook with ID %d not found!\n", id);
}

void returnBook() {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("\nYou have successfully returned the book: %s\n", library[i].title);
            } else {
                printf("\nThe book was not borrowed.\n");
            }
            return;
        }
    }
    printf("\nBook with ID %d not found!\n", id);
}

int main() {
    int choice;

    do {
        printf("\nE-Library Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
