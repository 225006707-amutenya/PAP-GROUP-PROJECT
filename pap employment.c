#include <stdio.h>
#include <string.h>

/*
 * Save this source as a .c file (for example, pap_project.c) and ensure your IDE
 * is configured to use a C compiler/include path so stdio.h resolves correctly.
 */

// declaring functions??
 void addEmployee();
 void displayEmployee();
 void calculateSalary();
 void searchEmployee();
  

 //declaring the arrays
 int employeeID[100];
 char employeeName[100][50];
 char department[100][50];
 float basicSalary[100];
 float housingAllowance[100];
 float transportAllowance[100];
 float otherAllowance[100];


 int count=0;

 int main() {
    
     int choice;

     do {
         printf("\nEmployee Management System\n");
         printf("1. Add Employee\n");
         printf("2. Display Employee\n");
         printf("3. Calculate Salary\n");
         printf("4. Search Employee\n");
         printf("5. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);

         switch (choice) {
             case 1:
                 addEmployee();
                 break;
             case 2:
                 displayEmployee();
                 break;
             case 3:
                 calculateSalary();
                 break;
             case 4:
                 searchEmployee();
                 break;
             case 5:
                 printf("Exiting the program.\n");
                 break;
             default:
                 printf("Invalid choice! Please try again.\n");
         }
     } while (choice != 5);

     return 0;
 }