#include <stdio.h>
#include <string.h>

#define MAX 50

// Functions
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateSalary();

// Arrays
char id[MAX][10];
char name[MAX][50];
char department[MAX][30];

float basic[MAX];
float housing[MAX];
float transport[MAX];

int count = 0;


// Add Employee
void addEmployee()
{
    printf("\nEnter Employee ID: ");
    scanf("%s", id[count]);

    printf("Enter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Department: ");
    scanf(" %[^\n]", department[count]);

    printf("Enter Basic Salary: ");
    scanf("%f", &basic[count]);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housing[count]);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transport[count]);

    count++;

    printf("Employee added successfully!\n");
}


// Display Employees
void displayEmployees()
{
    int i;

    if (count == 0)
    {
        printf("\nNo employees available.\n");
    }
    else
    {
        printf("\n===== EMPLOYEES =====\n");

        for (i = 0; i < count; i++)
        {
            printf("\nEmployee ID: %s\n", id[i]);
            printf("Name: %s\n", name[i]);
            printf("Department: %s\n", department[i]);
            printf("Basic Salary: %.2f\n", basic[i]);
        }
    }
}


// Search Employee
void searchEmployee()
{
    char searchID[10];
    int i;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%s", searchID);

    for (i = 0; i < count; i++)
    {
        if (strcmp(id[i], searchID) == 0)
        {
            printf("\nEmployee Found!\n");
            printf("ID: %s\n", id[i]);
            printf("Name: %s\n", name[i]);
            printf("Department: %s\n", department[i]);
            printf("Basic Salary: %.2f\n", basic[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}


// Calculate Salary
void calculateSalary()
{
    char searchID[10];
    int i;

    printf("\nEnter Employee ID: ");
    scanf("%s", searchID);

    for (i = 0; i < count; i++)
    {
        if (strcmp(id[i], searchID) == 0)
        {
            float total;

            total = basic[i] + housing[i] + transport[i];

            printf("\nEmployee: %s\n", name[i]);
            printf("Basic Salary: %.2f\n", basic[i]);
            printf("Housing Allowance: %.2f\n", housing[i]);
            printf("Transport Allowance: %.2f\n", transport[i]);
            printf("Total Salary: %.2f\n", total);

            return;
        }
    }

    printf("Employee not found.\n");
}
