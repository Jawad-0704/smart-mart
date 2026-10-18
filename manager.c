#include "app.h"


/* =========================
   MANAGER LOGIN
   ========================= */

void managerLogin()
{
    char username[30];
    char password[30];


    printf("\n");
    printf("============================================================\n");
    printf("                     MANAGER LOGIN                          \n");
    printf("============================================================\n");


    printf("\nUsername: ");
    scanf("%29s", username);


    printf("Password: ");
    scanf("%29s", password);


    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        printf("\n✓ Login successful!\n");

        managerMenu();
    }
    else
    {
        printf("\n✗ Invalid username or password!\n");
    }
}


/* =========================
   MANAGER MENU
   ========================= */

void managerMenu()
{
    int choice;


    while (1)
    {
        printf("\n");
        printf("============================================================\n");
        printf("                   MANAGER DASHBOARD                        \n");
        printf("============================================================\n");


        printf("\nSTORE STATISTICS\n");

        printf("------------------------------------------------------------\n");


        printf("Total Products : %d\n",
               productCount);


        printf("Total Orders   : %d\n",
               totalOrders);


        printf("Total Sales    : Tk. %.2f\n",
               totalSales);


        printf("------------------------------------------------------------\n");


        printf("\nMANAGEMENT OPTIONS\n\n");


        printf("[1] View All Products\n");

        printf("[2] Add Product\n");

        printf("[3] Update Stock\n");

        printf("[4] Search Product\n");

        printf("[5] Sales Statistics\n");

        printf("[0] Logout\n");


        printf("\nEnter choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                displayAllProducts();

                break;


            case 2:

                addProduct();

                break;


            case 3:

                updateStock();

                break;


            case 4:

                searchProduct();

                break;


            case 5:

                salesStatistics();

                break;


            case 0:

                printf("\nLogging out...\n");

                return;


            default:

                printf("\nInvalid choice!\n");
        }
    }
}
