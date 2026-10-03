#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 10

void   budgetMenu(void);
int    addDepartment(void);
int    enterExpenditure(void);
void   displayBudgets(void);
void   displayOverBudget(void);
double calculateRemaining(double allocated, double expenditure);
int    findDepartmentIndex(const char *name);
int    isValidAmount(double amount);

#endif