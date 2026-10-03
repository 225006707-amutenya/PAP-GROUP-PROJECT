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