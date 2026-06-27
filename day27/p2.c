//wap to create employ management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

//struct to represent an employee
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

//function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee Record");
        printf("\n4. Update Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n==================================");
        printf("\nEnter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nThank you for using the system!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

//function to add a new record to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); //clear trailing newline from buffer

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

//function to read and display all records from the file
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open file in read-binary mode
    if (fp == NULL) {
        printf("\nNo records found! Add some employees first.\n");
        return;
    }

    Employee emp;
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("-------------------------------------------------------------\n");
    fclose(fp);
}

//function to search a record by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == searchId) {
            found = 1;
            printf("\nRecord Found:");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: %.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

//function to update a record
void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); 
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == targetId) {
            found = 1;
            
            //move back pointer position to edit the record
            fseek(fp, -sizeof(Employee), SEEK_CUR);

            printf("\nEnter New Details for ID %d:\n", targetId);
            getchar(); // Clear buffer

            printf("Enter Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("Enter Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = '\0';

            printf("Enter Salary: ");
            scanf("%f", &emp.salary);

            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}

//function to delete a record
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError processing request!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == deleteId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);             //delete old original file
        rename("temp.dat", FILE_NAME); //rename temp file to main file
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat"); //delete temp file if record wasn't found
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}
