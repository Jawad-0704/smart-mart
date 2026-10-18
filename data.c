#include "app.h"


/* =========================
   GLOBAL VARIABLES
   ========================= */

Product products[MAX_PRODUCTS];

CartItem cart[MAX_CART];

Member members[MAX_MEMBERS];

int productCount = 0;
int cartCount = 0;
int memberCount = 0;

float totalSales = 0;
int totalOrders = 0;


/* =========================
   DEFAULT PRODUCTS
   ========================= */

static void loadDefaultProducts()
{
    productCount = 0;


    /* =========================
       GROCERIES
       ========================= */

    products[productCount++] =
        (Product){101, "Rice", "Groceries", 80, 100};

    products[productCount++] =
        (Product){102, "Lentils", "Groceries", 120, 100};

    products[productCount++] =
        (Product){103, "Sugar", "Groceries", 140, 100};

    products[productCount++] =
        (Product){104, "Cooking Oil", "Groceries", 180, 100};

    products[productCount++] =
        (Product){105, "Salt", "Groceries", 40, 100};


    /* =========================
       FROZEN ITEMS
       ========================= */

    products[productCount++] =
        (Product){201, "Frozen Chicken", "Frozen", 350, 50};

    products[productCount++] =
        (Product){202, "Frozen Nuggets", "Frozen", 450, 50};

    products[productCount++] =
        (Product){203, "Frozen Paratha", "Frozen", 180, 50};

    products[productCount++] =
        (Product){204, "Frozen Samosa", "Frozen", 200, 50};

    products[productCount++] =
        (Product){205, "Frozen French Fries", "Frozen", 250, 50};


    /* =========================
       VEGETABLES
       ========================= */

    products[productCount++] =
        (Product){301, "Potato", "Vegetables", 40, 100};

    products[productCount++] =
        (Product){302, "Tomato", "Vegetables", 80, 100};

    products[productCount++] =
        (Product){303, "Carrot", "Vegetables", 70, 100};

    products[productCount++] =
        (Product){304, "Onion", "Vegetables", 90, 100};

    products[productCount++] =
        (Product){305, "Capsicum", "Vegetables", 150, 100};


    /* =========================
       PROTEIN
       ========================= */

    products[productCount++] =
        (Product){401, "Beef", "Protein", 850, 50};

    products[productCount++] =
        (Product){402, "Chicken", "Protein", 220, 50};

    products[productCount++] =
        (Product){403, "Mutton", "Protein", 950, 50};

    products[productCount++] =
        (Product){404, "Fish", "Protein", 450, 50};

    products[productCount++] =
        (Product){405, "Eggs", "Protein", 140, 100};


    /* =========================
       SKIN CARE
       ========================= */

    products[productCount++] =
        (Product){501, "Face Wash", "Skin Care", 350, 50};

    products[productCount++] =
        (Product){502, "Moisturizer", "Skin Care", 500, 50};

    products[productCount++] =
        (Product){503, "Sunscreen", "Skin Care", 650, 50};

    products[productCount++] =
        (Product){504, "Face Cream", "Skin Care", 450, 50};

    products[productCount++] =
        (Product){505, "Body Lotion", "Skin Care", 400, 50};


    /* =========================
       MEN'S CLOTHING
       ========================= */

    products[productCount++] =
        (Product){601, "Men T-Shirt", "Men Clothing", 650, 30};

    products[productCount++] =
        (Product){602, "Men Shirt", "Men Clothing", 950, 30};

    products[productCount++] =
        (Product){603, "Men Jeans", "Men Clothing", 1200, 30};

    products[productCount++] =
        (Product){604, "Men Jacket", "Men Clothing", 1800, 20};

    products[productCount++] =
        (Product){605, "Men Panjabi", "Men Clothing", 1500, 30};


    /* =========================
       WOMEN'S CLOTHING
       ========================= */

    products[productCount++] =
        (Product){701, "Women T-Shirt", "Women Clothing", 650, 30};

    products[productCount++] =
        (Product){702, "Women Dress", "Women Clothing", 1200, 30};

    products[productCount++] =
        (Product){703, "Saree", "Women Clothing", 1800, 20};

    products[productCount++] =
        (Product){704, "Kurti", "Women Clothing", 900, 30};

    products[productCount++] =
        (Product){705, "Women Jeans", "Women Clothing", 1100, 30};
}


/* =========================
   INITIALIZE DATA
   ========================= */

void initializeData()
{
    FILE *file;

    file = fopen("products.txt", "r");

    if (file == NULL)
    {
        loadDefaultProducts();
        saveProducts();
    }
    else
    {
        fclose(file);
        loadProducts();
    }

    loadMembers();

    loadSales();
}
