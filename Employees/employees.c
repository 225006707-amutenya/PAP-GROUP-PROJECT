#include <stdio.h>
#include <string.h>

#define MAX 50

// Functions
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateSalary();

// Arrays
static char id[MAX][10];
static char name[MAX][50];
static char department[MAX][30];

static float basic[MAX];
static float housing[MAX];
static float transport[MAX];

static int count = 0;


// Add Employee
void addEmployee()
{
    if (count >= MAX)
    {
        printf("\nEmployee list is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%9s", id[count]);

    printf("Enter Name: ");
    scanf(" %49[^\n]", name[count]);

    printf("Enter Department: ");
    scanf(" %29[^\n]", department[count]);

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
    scanf("%9s", searchID);

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
    scanf("%9s", searchID);

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
// Main
int main()
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MENU =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalary(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

