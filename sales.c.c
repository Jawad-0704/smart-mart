#include "app.h"


/* =========================
   LOAD SALES
   ========================= */

void loadSales()
{
    FILE *file;

    float amount;


    file = fopen("sales.txt", "r");


    if (file == NULL)
    {
        return;
    }


    totalSales = 0;
    totalOrders = 0;


    while (fscanf(file,
                  "%f",
                  &amount) == 1)
    {
        totalSales += amount;

        totalOrders++;
    }


    fclose(file);
}


/* =========================
   SAVE SALE
   ========================= */

void saveSale(float amount)
{
    FILE *file;


    file = fopen("sales.txt", "a");


    if (file == NULL)
    {
        printf("\nError: Could not save sale!\n");
        return;
    }


    fprintf(file,
            "%.2f\n",
            amount);


    fclose(file);
}


/* =========================
   SALES STATISTICS
   ========================= */

void salesStatistics()
{
    float average;


    printf("\n");
    printf("============================================================\n");
    printf("                    SALES STATISTICS                        \n");
    printf("============================================================\n");


    printf("\nTotal Orders : %d\n",
           totalOrders);


    printf("Total Sales  : Tk. %.2f\n",
           totalSales);


    if (totalOrders > 0)
    {
        average =
            totalSales / totalOrders;


        printf("Average Sale : Tk. %.2f\n",
               average);
    }
    else
    {
        printf("Average Sale : Tk. 0.00\n");
    }


    printf("\n============================================================\n");
}
