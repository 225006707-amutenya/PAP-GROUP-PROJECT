Municipal Financial Management System (MFMS)

Course:  PAP521S - Programming in Practice

Group Members

| Student Initials and Surname | Student Number |
|------------------------------|----------------|
| A.N Amutenya                 | 225006707      |
| J.K Fillemon                 | 225166518      |
| B.R Carlos                   | 225138190      |
| F.R.N.A Simon                | 224082418      |
| K.T.T.M Kalimba              | 226074358      |
| J.I Ashikono                 | 226091910      |
| J.A.T.S Uugwanga             | 225166933      |

Project Description

A menu-driven C program that helps a municipality manage
employees, budgets, suppliers and assets. Built in ANSI C (C99).

System Features

1. Employee Management
-	Add a new employee (ID, name, department, basic salary, allowances)
-	Display all employees in the system
-	Search for an employee by ID or name
-	Calculate an employee's total salary (basic + housing + transport)
-	Display individual employee details
2. Budget Management
-	Enter departmental allocated budgets
-	Record expenditure per department
-	Calculate remaining budget for each department
-	Display all budget information
-	Identify departments that have exceeded their allocated budget
3. Supplier Management
-	Add a new supplier (ID, name, email, telephone, town)
-	Display all registered suppliers
-	Search for a supplier by ID or name
-	Compare supplier information
4. Asset Management
-	Register a new municipal asset (ID, name, type, purchase value, department, condition)
-	Display all registered assets
-	Search for an asset by ID or name
-	Display assets by department or type
5. Reports
-	Employee report: total employees, average salary, highest/lowest salary
-	Budget report: total allocated, total expenditure, remaining budget, over-budget departments
-	Supplier report: list of all registered suppliers
-	Asset report: list of all registered municipal assets
6. Input Validation
-	Reject negative salaries and budgets
-	Handle invalid menu choices
-	Reject empty names
-	Detect invalid numerical input
Compilation Instructions
Requires GCC. From the project root:  gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
How to Run:
On Windows:
    mfms.exe
Then choose a menu option (1–6) and follow the prompts.

 Individual Responsibilities
 
J.A.T.S Uugwanga -Employee Management

K.T.T.M Kalimba - Budget Management

F.R.N.A Simon - Supplier Management

J.I Ashikono -  Asset Management

B.R Carlos - Reports

J.K Fillemon - Functions, integration and validation

A.N Amutenya - Testing, documentation and Git coordination
