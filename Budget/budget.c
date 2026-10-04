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