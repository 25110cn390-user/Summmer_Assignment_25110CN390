//wap to create salary management system
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

//employee Structure
struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;          //house rent allowance
    float da;           //dearness allowance
    float pf;           //provident fund deduction
    float gross_salary;
    float net_salary;
};

//functions Declarations
void addEmployee(struct Employee emp[], int *count);
void displayAllEmployees(struct Employee emp[], int count);
void generatePayslip(struct Employee emp[], int count);
void calculateSalary(struct Employee *emp);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n     SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Employee Record");
        printf("\n2. Display All Employee Payrolls");
        printf("\n3. Generate Employee Payslip");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayAllEmployees(employees, employee_count);
                break;
            case 3:
                generatePayslip(employees, employee_count);
                break;
            case 4:
                printf("\nExiting program. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

//function to calculate components based on basic salary
void calculateSalary(struct Employee *emp) {
    emp->hra = emp->basic_salary * 0.15; // 15% HRA
    emp->da = emp->basic_salary * 0.20;  // 20% DA
    emp->pf = emp->basic_salary * 0.10;  // 10% PF Deduction

    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - emp->pf;
}

//function to add a new record
void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nDatabase Full! Cannot add more employees.\n");
        return;
    }

    struct Employee new_emp;
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &new_emp.id);

    //basic duplicate ID validation
    for (int i = 0; i < *count; i++) {
        if (emp[i].id == new_emp.id) {
            printf("\nError: Employee ID %d already exists!\n", new_emp.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    getchar(); //clear trailing newline buffer character
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0; //strip newline

    printf("Enter Basic Salary: ");
    scanf("%f", &new_emp.basic_salary);

    //perform automated salary math
    calculateSalary(&new_emp);

    //save into the main array database
    emp[*count] = new_emp;
    (*count)++;

    printf("\nRecord added successfully!\n");
}

//function to display the overview table
void displayAllEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-12s %-8s %-8s %-8s %-12s", "ID", "Name", "Basic", "HRA", "DA", "PF", "Net Salary");
    printf("\n-----------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-12.2f %-8.2f %-8.2f %-8.2f %-12.2f\n", 
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].hra, emp[i].da, emp[i].pf, emp[i].net_salary);
    }
    printf("-----------------------------------------------------------------------------\n");
}

//function to search and print a formatted single payslip
void generatePayslip(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    int search_id;
    int found = 0;
    printf("\nEnter Employee ID to generate payslip: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            found = 1;
            printf("\n========================================");
            printf("\n           OFFICIAL PAYSLIP             ");
            printf("\n========================================");
            printf("\nEmployee ID   : %d", emp[i].id);
            printf("\nEmployee Name : %s", emp[i].name);
            printf("\n----------------------------------------");
            printf("\nEARNINGS:");
            printf("\n  Basic Salary: $%.2f", emp[i].basic_salary);
            printf("\n  HRA (15%%)   : $%.2f", emp[i].hra);
            printf("\n  DA (20%%)    : $%.2f", emp[i].da);
            printf("\n----------------------------------------");
            printf("\nDEDUCTIONS:");
            printf("\n  PF (10%%)    : $%.2f", emp[i].pf);
            printf("\n----------------------------------------");
            printf("\nGROSS SALARY  : $%.2f", emp[i].gross_salary);
            printf("\nNET PAYCHECK  : $%.2f", emp[i].net_salary);
            printf("\n========================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
