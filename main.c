#include "app.h"


/* =========================
   MAIN FUNCTION
   ========================= */

int main()
{
    int choice;

    initializeData();

    while (1)
    {
        printf("\n");
        printf("============================================================\n");
        printf("                                                            \n");
        printf("                     SMART MART                             \n");
        printf("                                                            \n");
        printf("              YOUR DIGITAL SHOPPING SYSTEM                  \n");
        printf("                                                            \n");
        printf("============================================================\n");

        printf("\nWelcome! Please select your role:\n\n");

        printf("[1] Customer\n");
        printf("[2] Shop Manager\n");
        printf("[3] Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                customerMenu();
                break;

            case 2:
                managerLogin();
                break;

            case 3:

                printf("\n");
                printf("============================================================\n");
                printf("          Thank you for visiting Smart Mart!                \n");
                printf("                  Have a great day!                          \n");
                printf("============================================================\n");

                return 0;

            default:

                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


/* =========================
   CLEAR INPUT BUFFER
   ========================= */

void clearInputBuffer()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
