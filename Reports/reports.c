#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"

void employeeReport(void)
{
    printf("\n===== EMPLOYEE REPORT =====\n");
    displayEmployees();
}

void budgetReport(void)
{
    printf("\n===== BUDGET REPORT =====\n");
    displayBudgets();
    displayOverBudget();
}

void supplierReport(void)
{
    printf("\n===== SUPPLIER REPORT =====\n");
    displaySuppliers();
}

void assetReport(void)
{
    printf("\n===== ASSET REPORT =====\n");
    displayAsset();
}

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}

#ifdef REPORTS_STANDALONE
int main(void)
{
    int choice;
    do
    {
        printf("\n===== REPORTS DEMO =====\n");
        printf("1. Add Employee\n");
        printf("2. Budget Menu (add departments / expenditure)\n");
        printf("3. Add Supplier\n");
        printf("4. Add Asset\n");
        printf("5. Reports Menu\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addEmployee();  break;
            case 2: budgetMenu();   break;
            case 3: addSupplier();  break;
            case 4: addAsset();     break;
            case 5: reportsMenu();  break;
            case 6: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
#endif
