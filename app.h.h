#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CART 50
#define MAX_MEMBERS 500

/* =========================
   STRUCTURES
   ========================= */

typedef struct
{
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
} Product;


typedef struct
{
    int productId;
    char name[50];
    float price;
    int quantity;
    float total;
} CartItem;


typedef struct
{
    char code[20];
} Member;


/* =========================
   GLOBAL VARIABLES
   ========================= */

extern Product products[MAX_PRODUCTS];
extern CartItem cart[MAX_CART];
extern Member members[MAX_MEMBERS];

extern int productCount;
extern int cartCount;
extern int memberCount;

extern float totalSales;
extern int totalOrders;


/* =========================
   DATA FUNCTIONS
   ========================= */

void initializeData();

void loadProducts();
void saveProducts();

void loadMembers();
void saveMembers();

void loadSales();
void saveSale(float amount);


/* =========================
   PRODUCT FUNCTIONS
   ========================= */

void displayProductsByCategory(const char category[]);
void displayAllProducts();

void addProduct();
void updateStock();
void searchProduct();


/* =========================
   CUSTOMER FUNCTIONS
   ========================= */

void customerMenu();
void addToCart();
void viewCart();
void removeFromCart();
void checkout();


/* =========================
   MANAGER FUNCTIONS
   ========================= */

void managerLogin();
void managerMenu();
void salesStatistics();


/* =========================
   MEMBERSHIP FUNCTIONS
   ========================= */

void generateMembershipCode();
int validateMembership(const char code[]);


/* =========================
   UTILITY
   ========================= */

void clearInputBuffer();

#endif
