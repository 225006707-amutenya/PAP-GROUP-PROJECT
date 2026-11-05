#include <stdio.h>
#include <string.h>
#include "budget.h"

typedef struct {
    char   name[50];
    double allocatedBudget;
    double expenditure;
} Department;

static Department departments[MAX_DEPARTMENTS];
static int departmentCount = 0;

int isValidAmount(double amount) {
    return amount >= 0.0;
}

int findDepartmentIndex(const char *name) {
    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double calculateRemaining(double allocated, double expenditure) {
    return allocated - expenditure;
}
int addDepartment(void) {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Error: maximum number of departments reached.\n");
        return 0;
    }

    char name[50];
    double budget;

    printf("Enter department name: ");
    scanf(" %49[^\n]", name);

    if (strlen(name) == 0) {
        printf("Error: department name cannot be empty.\n");
        return 0;
    }

    printf("Enter allocated budget (N$): ");
    if (scanf("%lf", &budget) != 1 || !isValidAmount(budget)) {
        printf("Error: invalid or negative budget.\n");
        while (getchar() != '\n');
        return 0;
    }

    int idx = findDepartmentIndex(name);
    if (idx >= 0) {
        departments[idx].allocatedBudget = budget;
        printf("Updated budget for %s.\n", name);
    } else {
        strcpy(departments[departmentCount].name, name);
        departments[departmentCount].allocatedBudget = budget;
        departments[departmentCount].expenditure = 0.0;
        departmentCount++;
        printf("Department '%s' added.\n", name);
    }
    return 1;
}
int enterExpenditure(void) {
    char name[50];
    double amount;

    printf("Enter department name: ");
    scanf(" %49[^\n]", name);

    int idx = findDepartmentIndex(name);
    if (idx < 0) {
        printf("Error: department not found.\n");
        return 0;
    }

    printf("Enter expenditure (N$): ");
    if (scanf("%lf", &amount) != 1 || !isValidAmount(amount)) {
        printf("Error: invalid or negative expenditure.\n");
        while (getchar() != '\n');
        return 0;
    }

    departments[idx].expenditure += amount;
    printf("Expenditure recorded for %s.\n", name);
    return 1;
}
void displayBudgets(void) {
    if (departmentCount == 0) {
        printf("No departments recorded yet.\n");
        return;
    }

    printf("\n%-20s %15s %15s %15s  %s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < departmentCount; i++) {
        double remaining = calculateRemaining(departments[i].allocatedBudget,
                                              departments[i].expenditure);
        const char *status = (remaining < 0) ? "OVER BUDGET" : "WITHIN BUDGET";
        printf("%-20s %15.2f %15.2f %15.2f  %s\n",
               departments[i].name,
               departments[i].allocatedBudget,
               departments[i].expenditure,
               remaining,
               status);
    }
}

void displayOverBudget(void) {
    int found = 0;
    printf("\nDepartments exceeding budget:\n");
    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].expenditure > departments[i].allocatedBudget) {
            printf(" - %s (over by N$%.2f)\n",
                   departments[i].name,
                   departments[i].expenditure - departments[i].allocatedBudget);
            found = 1;
        }
    }
    if (!found) printf("None. All departments are within budget.\n");
}
void budgetMenu(void) {
    int choice;
    do {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add / Update Department Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. View All Budgets\n");
        printf("4. View Departments Over Budget\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addDepartment();       break;
            case 2: enterExpenditure();    break;
            case 3: displayBudgets();      break;
            case 4: displayOverBudget();   break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
#ifdef STANDALONE
int main() {
    budgetMenu();
    return 0;
}
#endif
