#include <stdio.h>
#include <string.h>
#include "assets.h"

// declaring the arrays
int assetID[100];
char assetName[100][50];
char assetType[100][50];
float purchaseValue[100];
char department[100][50];
char condition[100][50];

int count = 0;

// ---------- ADD ASSET ----------
void addAsset() {

    if (count >= 100) {
        printf("Asset register is full!\n");
        return;
    }

    printf("\n--- Add New Asset ---\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assetID[count]);

    if (assetID[count] <= 0) {
        printf("Error: Asset ID must be positive!\n");
        return;
    }

    // check for duplicate ID
    for (int i = 0; i < count; i++) {
        if (assetID[i] == assetID[count]) {
            printf("Error: Asset ID already exists!\n");
            return;
        }
    }

    getchar(); // clear buffer before fgets

    printf("Enter Asset Name: ");
    fgets(assetName[count], 50, stdin);
    assetName[count][strcspn(assetName[count], "\n")] = '\0';

    if (strlen(assetName[count]) == 0) {
        printf("Error: Asset name cannot be empty!\n");
        return;
    }

    printf("Enter Asset Type: ");
    fgets(assetType[count], 50, stdin);
    assetType[count][strcspn(assetType[count], "\n")] = '\0';

    printf("Enter Purchase Value: ");
    scanf("%f", &purchaseValue[count]);

    if (purchaseValue[count] < 0) {
        printf("Error: Purchase value cannot be negative!\n");
        return;
    }

    getchar(); // clear buffer before fgets

    printf("Enter Department: ");
    fgets(department[count], 50, stdin);
    department[count][strcspn(department[count], "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(condition[count], 50, stdin);
    condition[count][strcspn(condition[count], "\n")] = '\0';

    count++;
    printf("Asset added successfully!\n");
}

// ---------- DISPLAY ASSET ----------
void displayAsset() {

    if (count == 0) {
        printf("No assets to display.\n");
        return;
    }

    printf("\n--- Asset List ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID       : %d\n", assetID[i]);
        printf("Asset Name     : %s\n", assetName[i]);
        printf("Asset Type     : %s\n", assetType[i]);
        printf("Purchase Value : %.2f\n", purchaseValue[i]);
        printf("Department     : %s\n", department[i]);
        printf("Condition      : %s\n", condition[i]);
    }
}

// ---------- SEARCH ASSET ----------
void searchAsset() {

    if (count == 0) {
        printf("No assets to search.\n");
        return;
    }

    int searchID;
    int found = 0;

    printf("Enter Asset ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (assetID[i] == searchID) {
            printf("\n--- Asset Found ---\n");
            printf("Asset ID       : %d\n", assetID[i]);
            printf("Asset Name     : %s\n", assetName[i]);
            printf("Asset Type     : %s\n", assetType[i]);
            printf("Purchase Value : %.2f\n", purchaseValue[i]);
            printf("Department     : %s\n", department[i]);
            printf("Condition      : %s\n", condition[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Asset not found.\n");
    }
}