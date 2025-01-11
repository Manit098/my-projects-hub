#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    float marks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nMaximum student limit reached!\n");
        return;
    }

    Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    getchar(); // Clear newline
    fgets(s.name, NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[studentCount++] = s;
    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("\nNo students found!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nMarks: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    printf("\nStudent with ID %d not found!\n", id);
}

void updateStudent() {
    int id;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nUpdating Student (ID: %d):\n", id);
            printf("Enter New Name: ");
            getchar(); // Clear newline
            fgets(students[i].name, NAME_LENGTH, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline
            printf("Enter New Age: ");
            scanf("%d", &students[i].age);
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);
            printf("\nStudent updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with ID %d not found!\n", id);
}

void deleteStudent() {
    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("\nStudent with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("\nStudent with ID %d not found!\n", id);
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
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
