#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "reports.h"

/* Sub-menu prototypes */
void employeeMenu(void);
void supplierMenu(void);
void assetMenu(void);

int main(void)
{
    int choice;

    do
    {
        printf("\n==================================================\n");
        printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("==================================================\n");
        printf("  1. Employee Management\n");
        printf("  2. Budget Management\n");
        printf("  3. Supplier Management\n");
        printf("  4. Asset Management\n");
        printf("  5. Reports\n");
        printf("  6. Exit\n");
        printf("--------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: employeeMenu(); break;
            case 2: budgetMenu();   break;
            case 3: supplierMenu(); break;
            case 4: assetMenu();    break;
            case 5: reportsMenu();  break;
            case 6: printf("\nExiting MFMS. Goodbye.\n"); break;
            default: printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

/* ---------------- EMPLOYEE MENU ---------------- */
void employeeMenu(void)
{
    int choice;
    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addEmployee();      break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee();   break;
            case 4: calculateSalary();  break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

/* ---------------- SUPPLIER MENU ---------------- */
void supplierMenu(void)
{
    int choice;
    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: compareSuppliers(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

/* ---------------- ASSET MENU ---------------- */
void assetMenu(void)
{
    int choice;
    do
    {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addAsset();     break;
            case 2: displayAsset(); break;
            case 3: searchAsset();  break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}