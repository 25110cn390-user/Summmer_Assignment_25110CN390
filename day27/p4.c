//wap to create marksheet generation system
#include <stdio.h>
#include <string.h>

//structure 
struct Student {
    char name[50];
    int rollNo;
    int marks[5];
    int total;
    float percentage;
    char division[20];
};

int main() {
    struct Student s;
    const char *subjects[5] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Science"};
    s.total = 0;

    //student Information
    printf("=========================================\n");
    printf("       MARKSHEET GENERATION SYSTEM       \n");
    printf("=========================================\n");
    
    printf("Enter Student Full Name: ");
    //safely read string with spaces 
    scanf(" %[^\n]s", s.name); 
    
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    // accept input & validate marks
    printf("\nEnter marks out of 100 for the following subjects:\n");
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("%s: ", subjects[i]);
            scanf("%d", &s.marks[i]);
            
            //validation step 
            if (s.marks[i] >= 0 && s.marks[i] <= 100) {
                break;
            }
            printf("Invalid Input! Marks must be strictly between 0 and 100.\n");
        }
        s.total += s.marks[i];
    }

    //calculation
    s.percentage = s.total / 5.0;

    if (s.percentage >= 60.0) {
        strcpy(s.division, "First Division");
    } else if (s.percentage >= 45.0) {
        strcpy(s.division, "Second Division");
    } else if (s.percentage >= 33.0) {
        strcpy(s.division, "Third Division");
    } else {
        strcpy(s.division, "Fail / Retake");
    }

    // Marksheet
    printf("\n\n");
    printf("====================================================\n");
    printf("                OFFICIAL REPORT CARD                \n");
    printf("====================================================\n");
    printf(" Student Name: %-25s Roll No: %-5d\n", s.name, s.rollNo);
    printf("----------------------------------------------------\n");
    printf(" %-25s | %-15s\n", "SUBJECT NAME", "MARKS OBTAINED");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf(" %-25s | %-15d\n", subjects[i], s.marks[i]);
    }
    
    printf("----------------------------------------------------\n");
    printf(" Aggregate Total: %-13d Maximum Marks: 500\n", s.total);
    printf(" Final Percentage: %-12.2f%%\n", s.percentage);
    printf(" Academic Standing: %-20s\n", s.division);
    printf("====================================================\n");

    return 0;
}
