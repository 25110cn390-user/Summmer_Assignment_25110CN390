//wap to create student record management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

// struct to hold student info
struct Student {
    int rollNo;
    char name[50];
    float gpa;
};

//function prototypes
void addStudentRecord();
void displayAllRecords();
void searchStudentRecord();
void deleteStudentRecord();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                deleteStudentRecord();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

// function to add a new record 
void addStudentRecord() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);
    getchar(); //clear newline character left in buffer

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; //remove trailing newline

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fprintf(fp, "%d, %s, %.2f\n", s.rollNo, s.name, s.gpa);
    fclose(fp);

    printf("Record added successfully!\n");
}

// function to read and display records
void displayAllRecords() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found. Add a record first!\n");
        return;
    }

    struct Student s;
    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("--------!---------------!---------------!------------\n");

    while (fscanf(fp, "%d, %49[^,], %f\n", &s.rollNo, s.name, &s.gpa) == 3) {
        printf("%-10d %-30s %-5.2f\n", s.rollNo, s.name, s.gpa);
    }
    fclose(fp);
}

// function to search for a specific record
void searchStudentRecord() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetRoll, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    while (fscanf(fp, "%d, %49[^,], %f\n", &s.rollNo, s.name, &s.gpa) == 3) {
        if (s.rollNo == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", s.rollNo);
            printf("Name:        %s\n", s.name);
            printf("GPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}

// function to delete a record 
void deleteStudentRecord() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int targetRoll, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &targetRoll);

    //copy all lines except the targeted one 
    while (fscanf(fp, "%d, %49[^,], %f\n", &s.rollNo, s.name, &s.gpa) == 3) {
        if (s.rollNo == targetRoll) {
            found = 1; 
        } else {
            fprintf(tempFp, "%d, %s, %.2f\n", s.rollNo, s.name, s.gpa);
        }
    }
    fclose(fp);
    fclose(tempFp);

    //replacing old file with new updated file
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}
