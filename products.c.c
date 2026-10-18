#include "app.h"


/* =========================
   SAVE PRODUCTS
   ========================= */

void saveProducts()
{
    FILE *file;
    int i;

    file = fopen("products.txt", "w");

    if (file == NULL)
    {
        printf("\nError: Could not save products!\n");
        return;
    }

    for (i = 0; i < productCount; i++)
    {
        fprintf(file,
                "%d|%s|%s|%.2f|%d\n",
                products[i].id,
                products[i].name,
                products[i].category,
                products[i].price,
                products[i].stock);
    }

    fclose(file);
}


/* =========================
   LOAD PRODUCTS
   ========================= */

void loadProducts()
{
    FILE *file;

    file = fopen("products.txt", "r");

    if (file == NULL)
    {
        return;
    }

    productCount = 0;

    while (productCount < MAX_PRODUCTS &&
           fscanf(file,
                  "%d|%49[^|]|%29[^|]|%f|%d\n",
                  &products[productCount].id,
                  products[productCount].name,
                  products[productCount].category,
                  &products[productCount].price,
                  &products[productCount].stock) == 5)
    {
        productCount++;
    }

    fclose(file);
}


/* =========================
   DISPLAY PRODUCTS BY CATEGORY
   ========================= */

void displayProductsByCategory(const char category[])
{
    int i;

    printf("\n");
    printf("============================================================\n");
    printf("                    %s\n", category);
    printf("============================================================\n");

    printf("\n%-8s %-25s %-12s %-10s\n",
           "ID",
           "PRODUCT",
           "PRICE",
           "STOCK");

    printf("------------------------------------------------------------\n");

    for (i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].category, category) == 0)
        {
            printf("%-8d %-25s Tk.%-8.2f %-10d\n",
                   products[i].id,
                   products[i].name,
                   products[i].price,
                   products[i].stock);
        }
    }

    printf("------------------------------------------------------------\n");
}


/* =========================
   DISPLAY ALL PRODUCTS
   ========================= */

void displayAllProducts()
{
    int i;

    printf("\n");
    printf("====================================================================\n");
    printf("                         ALL PRODUCTS                               \n");
    printf("====================================================================\n");

    printf("\n%-8s %-22s %-18s %-12s %-8s\n",
           "ID",
           "NAME",
           "CATEGORY",
           "PRICE",
           "STOCK");

    printf("--------------------------------------------------------------------\n");

    for (i = 0; i < productCount; i++)
    {
        printf("%-8d %-22s %-18s %-12.2f %-8d\n",
               products[i].id,
               products[i].name,
               products[i].category,
               products[i].price,
               products[i].stock);
    }
}


/* =========================
   ADD PRODUCT
   ========================= */

void addProduct()
{
    if (productCount >= MAX_PRODUCTS)
    {
        printf("\nProduct storage is full!\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &products[productCount].id);

    clearInputBuffer();

    printf("Enter Product Name: ");

    fgets(products[productCount].name,
          sizeof(products[productCount].name),
          stdin);

    products[productCount].name[
        strcspn(products[productCount].name, "\n")
    ] = '\0';


    printf("Enter Category: ");

    fgets(products[productCount].category,
          sizeof(products[productCount].category),
          stdin);

    products[productCount].category[
        strcspn(products[productCount].category, "\n")
    ] = '\0';


    printf("Enter Price: ");
    scanf("%f", &products[productCount].price);


    printf("Enter Stock: ");
    scanf("%d", &products[productCount].stock);


    if (products[productCount].price < 0 ||
        products[productCount].stock < 0)
    {
        printf("\nPrice and stock cannot be negative!\n");
        return;
    }


    productCount++;

    saveProducts();

    printf("\nProduct added successfully! ✓\n");
}


/* =========================
   UPDATE STOCK
   ========================= */

void updateStock()
{
    int id;
    int newStock;
    int i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct: %s\n",
                   products[i].name);

            printf("Current Stock: %d\n",
                   products[i].stock);

            printf("\nEnter New Stock: ");
            scanf("%d", &newStock);

            if (newStock < 0)
            {
                printf("\nStock cannot be negative!\n");
                return;
            }

            products[i].stock = newStock;

            saveProducts();

            printf("\nStock updated successfully! ✓\n");

            return;
        }
    }

    printf("\nProduct not found!\n");
}


/* =========================
   SEARCH PRODUCT
   ========================= */

void searchProduct()
{
    int id;
    int i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            printf("\n");
            printf("========================================\n");
            printf("             PRODUCT FOUND              \n");
            printf("========================================\n");

            printf("ID       : %d\n",
                   products[i].id);

            printf("Name     : %s\n",
                   products[i].name);

            printf("Category : %s\n",
                   products[i].category);

            printf("Price    : Tk. %.2f\n",
                   products[i].price);

            printf("Stock    : %d\n",
                   products[i].stock);

            return;
        }
    }

    printf("\nProduct not found!\n");
}
