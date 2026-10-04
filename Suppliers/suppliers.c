
#include <stdio.h>
#include <string.h>
#include "Supplier.h"

#define MAX_SUPPLIERS 100

int supplierID[MAX_SUPPLIERS];
char supplierName[MAX_SUPPLIERS][100];
char email[MAX_SUPPLIERS][100];
char phone[MAX_SUPPLIERS][30];
char town[MAX_SUPPLIERS][50];

int supplierCount = 0;


void displayMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();
void compareSuppliers();

int main()
{
    int choice;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 5:
                printf("\nExiting Supplier Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}



void displayMenu()
{
    printf("SUPPLIER MANAGEMENT SYSTEM\n");
    printf("1. Add Supplier\n");
    printf("2. Display Suppliers\n");
    printf("3. Search Supplier\n");
    printf("4. Compare Suppliers\n");
    printf("5. Exit\n");
}


void addSupplier()
{
    if(supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached. Cannot add more suppliers.\n");
        return;
    }

    printf("\n Add Supplier\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &supplierID[supplierCount]);
    getchar();

    printf("Enter Supplier Name: ");
    fgets(supplierName[supplierCount], 100, stdin);
    supplierName[supplierCount][strcspn(supplierName[supplierCount], "\n")] = '\0';

    printf("Enter Email: ");
    fgets(email[supplierCount], 100, stdin);
    email[supplierCount][strcspn(email[supplierCount], "\n")] = '\0';

    printf("Enter Telephone Number: ");
    fgets(phone[supplierCount], 30, stdin);
    phone[supplierCount][strcspn(phone[supplierCount], "\n")] = '\0';

    printf("Enter Town/Location: ");
    fgets(town[supplierCount], 50, stdin);
    town[supplierCount][strcspn(town[supplierCount], "\n")] = '\0';

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}



void displaySuppliers()
{
    int i;

    if(supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\nSUPPLIER LIST\n");
    printf("\n");

    for(i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone: %s\n", phone[i]);
        printf("Town/Location: %s\n", town[i]);

        printf("Name Length: %lu characters\n",
               strlen(supplierName[i]));
    }
}


void searchSupplier()
{
    char searchName[100];
    int i;
    int found = 0;

    if(supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\nEnter supplier name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for(i = 0; i < supplierCount; i++)
    {
        if(strcmp(searchName, supplierName[i]) == 0)
        {
            printf("\nSupplier found!\n");
            printf("Supplier ID: %d\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone: %s\n", phone[i]);
            printf("Town/Location: %s\n", town[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nSupplier not found.\n");
    }
}


void compareSuppliers()
{
    int first, second;

    if(supplierCount < 2)
    {
        printf("\nYou need at least two suppliers to compare.\n");
        return;
    }

    printf("\nEnter number of first supplier (1-%d): ", supplierCount);
    scanf("%d", &first);

    printf("Enter number of second supplier (1-%d): ", supplierCount);
    scanf("%d", &second);
    getchar();

    if(first < 1 || first > supplierCount ||
       second < 1 || second > supplierCount)
    {
        printf("\nInvalid supplier number.\n");
        return;
    }

   

    printf("\nSupplier 1:\n");
    printf("ID: %d\n", supplierID[first - 1]);
    printf("Name: %s\n", supplierName[first - 1]);
    printf("Email: %s\n", email[first - 1]);
    printf("Telephone: %s\n", phone[first - 1]);
    printf("Town: %s\n", town[first - 1]);

    printf("\nSupplier 2:\n");
    printf("ID: %d\n", supplierID[second - 1]);
    printf("Name: %s\n", supplierName[second - 1]);
    printf("Email: %s\n", email[second - 1]);
    printf("Telephone: %s\n", phone[second - 1]);
    printf("Town: %s\n", town[second - 1]);

    if(strcmp(supplierName[first - 1], supplierName[second - 1]) == 0)
    {
        printf("\nThe supplier names are the same.\n");
    }
    else
    {
        printf("\nThe supplier names are different.\n");
    }
}

