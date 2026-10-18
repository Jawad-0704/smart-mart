#include "app.h"


/* =========================
   CUSTOMER MENU
   ========================= */

void customerMenu()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("============================================================\n");
        printf("                    SMART MART                              \n");
        printf("                  CUSTOMER PANEL                            \n");
        printf("============================================================\n");

        printf("\nWelcome to Smart Mart! 🛒\n");
        printf("What would you like to shop for?\n\n");

        printf("[1] Groceries\n");
        printf("[2] Frozen Items\n");
        printf("[3] Vegetables\n");
        printf("[4] Protein Section\n");
        printf("[5] Skin Care\n");
        printf("[6] Clothing\n");
        printf("[7] View Cart\n");
        printf("[8] Remove From Cart\n");
        printf("[9] Checkout\n");
        printf("[0] Exit Customer Mode\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                displayProductsByCategory("Groceries");
                addToCart();

                break;


            case 2:

                displayProductsByCategory("Frozen");
                addToCart();

                break;


            case 3:

                displayProductsByCategory("Vegetables");
                addToCart();

                break;


            case 4:

                displayProductsByCategory("Protein");
                addToCart();

                break;


            case 5:

                displayProductsByCategory("Skin Care");
                addToCart();

                break;


            case 6:
            {
                int clothingChoice;

                printf("\n");
                printf("========================================\n");
                printf("             CLOTHING SECTION            \n");
                printf("========================================\n");

                printf("\n[1] Men's Clothing\n");
                printf("[2] Women's Clothing\n");
                printf("[0] Back\n");

                printf("\nEnter choice: ");
                scanf("%d", &clothingChoice);


                if (clothingChoice == 1)
                {
                    displayProductsByCategory("Men Clothing");
                    addToCart();
                }
                else if (clothingChoice == 2)
                {
                    displayProductsByCategory("Women Clothing");
                    addToCart();
                }

                break;
            }


            case 7:

                viewCart();

                break;


            case 8:

                removeFromCart();

                break;


            case 9:

                checkout();

                break;


            case 0:

                cartCount = 0;

                return;


            default:

                printf("\nInvalid choice!\n");
        }
    }
}


/* =========================
   ADD TO CART
   ========================= */

void addToCart()
{
    int id;
    int quantity;
    int i;


    printf("\nEnter Product ID to add to cart");
    printf(" (0 = Back): ");

    scanf("%d", &id);


    if (id == 0)
    {
        return;
    }


    for (i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct       : %s\n",
                   products[i].name);

            printf("Price         : Tk. %.2f\n",
                   products[i].price);

            printf("Available     : %d\n",
                   products[i].stock);


            printf("\nEnter quantity: ");
            scanf("%d", &quantity);


            if (quantity <= 0)
            {
                printf("\nInvalid quantity!\n");
                return;
            }


            if (quantity > products[i].stock)
            {
                printf("\nNot enough stock available!\n");
                return;
            }


            if (cartCount >= MAX_CART)
            {
                printf("\nCart is full!\n");
                return;
            }


            cart[cartCount].productId =
                products[i].id;


            strcpy(cart[cartCount].name,
                   products[i].name);


            cart[cartCount].price =
                products[i].price;


            cart[cartCount].quantity =
                quantity;


            cart[cartCount].total =
                products[i].price * quantity;


            products[i].stock -= quantity;


            cartCount++;


            saveProducts();


            printf("\n");
            printf("========================================\n");
            printf("       ✓ PRODUCT ADDED TO CART          \n");
            printf("========================================\n");


            return;
        }
    }


    printf("\nProduct not found!\n");
}


/* =========================
   VIEW CART
   ========================= */

void viewCart()
{
    int i;

    float subtotal = 0;


    if (cartCount == 0)
    {
        printf("\nYour cart is empty!\n");
        return;
    }


    printf("\n");
    printf("============================================================\n");
    printf("                         YOUR CART                          \n");
    printf("============================================================\n");


    printf("\n%-8s %-22s %-7s %-10s %-10s\n",
           "ID",
           "PRODUCT",
           "QTY",
           "PRICE",
           "TOTAL");


    printf("------------------------------------------------------------\n");


    for (i = 0; i < cartCount; i++)
    {
        printf("%-8d %-22s %-7d %-10.2f %-10.2f\n",
               cart[i].productId,
               cart[i].name,
               cart[i].quantity,
               cart[i].price,
               cart[i].total);


        subtotal += cart[i].total;
    }


    printf("------------------------------------------------------------\n");

    printf("Subtotal: Tk. %.2f\n",
           subtotal);
}


/* =========================
   REMOVE FROM CART
   ========================= */

void removeFromCart()
{
    int id;
    int i;
    int j;


    if (cartCount == 0)
    {
        printf("\nYour cart is empty!\n");
        return;
    }


    viewCart();


    printf("\nEnter Product ID to remove: ");
    scanf("%d", &id);


    for (i = 0; i < cartCount; i++)
    {
        if (cart[i].productId == id)
        {
            /* Return quantity to stock */

            for (j = 0; j < productCount; j++)
            {
                if (products[j].id == id)
                {
                    products[j].stock +=
                        cart[i].quantity;

                    break;
                }
            }


            /* Shift cart */

            for (j = i; j < cartCount - 1; j++)
            {
                cart[j] = cart[j + 1];
            }


            cartCount--;


            saveProducts();


            printf("\n✓ Product removed from cart!\n");

            return;
        }
    }


    printf("\nProduct not found in cart!\n");
}


/* =========================
   CHECKOUT
   ========================= */

void checkout()
{
    int i;

    int membershipChoice;
    int paymentChoice;

    char code[20];

    float subtotal = 0;
    float automaticDiscount = 0;
    float membershipDiscount = 0;
    float finalPrice;


    /* Check empty cart */

    if (cartCount == 0)
    {
        printf("\nYour cart is empty!\n");
        return;
    }


    /* Calculate subtotal */

    for (i = 0; i < cartCount; i++)
    {
        subtotal += cart[i].total;
    }


    printf("\n");
    printf("============================================================\n");
    printf("                         CHECKOUT                           \n");
    printf("============================================================\n");


    printf("\nSubtotal: Tk. %.2f\n",
           subtotal);


    /* =========================
       10% DISCOUNT
       ========================= */

    if (subtotal > 15000)
    {
        automaticDiscount =
            subtotal * 0.10;

        printf("\n🎉 You qualify for a 10%% discount!\n");
    }


    /* =========================
       MEMBERSHIP
       ========================= */

    printf("\n");
    printf("Do you have a Membership Card?\n");

    printf("[1] Yes\n");
    printf("[2] No\n");

    printf("\nEnter choice: ");
    scanf("%d", &membershipChoice);


    if (membershipChoice == 1)
    {
        printf("\nEnter Membership Code: ");

        scanf("%19s", code);


        if (validateMembership(code))
        {
            membershipDiscount =
                subtotal * 0.05;

            printf("\n✓ Valid Membership Card!\n");
            printf("✓ Extra 5%% discount applied!\n");
        }
        else
        {
            printf("\n✗ Invalid Membership Code!\n");
        }
    }


    /* =========================
       FINAL PRICE
       ========================= */

    finalPrice =
        subtotal
        - automaticDiscount
        - membershipDiscount;


    /* =========================
       FINAL BILL
       ========================= */

    printf("\n");
    printf("============================================================\n");
    printf("                       FINAL BILL                           \n");
    printf("============================================================\n");


    for (i = 0; i < cartCount; i++)
    {
        printf("%-25s x%-3d Tk. %.2f\n",
               cart[i].name,
               cart[i].quantity,
               cart[i].total);
    }


    printf("------------------------------------------------------------\n");


    printf("Subtotal              : Tk. %.2f\n",
           subtotal);


    printf("Automatic Discount    : Tk. %.2f\n",
           automaticDiscount);


    printf("Membership Discount   : Tk. %.2f\n",
           membershipDiscount);


    printf("------------------------------------------------------------\n");


    printf("FINAL PRICE           : Tk. %.2f\n",
           finalPrice);


    printf("============================================================\n");


    /* =========================
       PAYMENT
       ========================= */

    printf("\nPayment Method:\n");

    printf("[1] Cash\n");
    printf("[2] Card\n");
    printf("[3] Mobile Banking\n");


    printf("\nEnter choice: ");
    scanf("%d", &paymentChoice);


    if (paymentChoice < 1 ||
        paymentChoice > 3)
    {
        printf("\nInvalid payment method!\n");

        return;
    }


    printf("\n✓ Payment successful!\n");


    /* =========================
       SAVE SALE
       ========================= */

    totalSales += finalPrice;

    totalOrders++;


    saveSale(finalPrice);


    /* =========================
       MEMBERSHIP REWARD
       ========================= */

    if (subtotal > 5000)
    {
        generateMembershipCode();
    }


    /* =========================
       THANK YOU
       ========================= */

    printf("\n");
    printf("============================================================\n");
    printf("                                                            \n");
    printf("               THANK YOU FOR SHOPPING!                      \n");
    printf("                       SMART MART                            \n");
    printf("                                                            \n");
    printf("============================================================\n");


    cartCount = 0;
}
