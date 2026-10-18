#include "app.h"


/* =========================
   SAVE MEMBERS
   ========================= */

void saveMembers()
{
    FILE *file;
    int i;


    file = fopen("members.txt", "w");


    if (file == NULL)
    {
        printf("\nError: Could not save members!\n");
        return;
    }


    for (i = 0; i < memberCount; i++)
    {
        fprintf(file,
                "%s\n",
                members[i].code);
    }


    fclose(file);
}


/* =========================
   LOAD MEMBERS
   ========================= */

void loadMembers()
{
    FILE *file;


    file = fopen("members.txt", "r");


    if (file == NULL)
    {
        return;
    }


    memberCount = 0;


    while (memberCount < MAX_MEMBERS &&
           fscanf(file,
                  "%19s",
                  members[memberCount].code) == 1)
    {
        memberCount++;
    }


    fclose(file);
}


/* =========================
   GENERATE MEMBERSHIP CODE
   ========================= */

void generateMembershipCode()
{
    char code[20];


    if (memberCount >= MAX_MEMBERS)
    {
        printf("\nMembership database is full!\n");
        return;
    }


    sprintf(code,
            "SM%04d",
            1001 + memberCount);


    strcpy(members[memberCount].code,
           code);


    memberCount++;


    saveMembers();


    printf("\n");
    printf("============================================================\n");
    printf("                  MEMBERSHIP REWARD                         \n");
    printf("============================================================\n");


    printf("\nCongratulations! 🎉\n");

    printf("You have qualified for a Smart Mart Membership Card.\n");


    printf("\n");
    printf("YOUR MEMBERSHIP CODE: %s\n",
           code);


    printf("\nMembership Benefit:\n");

    printf("• Extra 5%% discount on future purchases\n");


    printf("\nPlease save your membership code.\n");


    printf("============================================================\n");
}


/* =========================
   VALIDATE MEMBERSHIP
   ========================= */

int validateMembership(const char code[])
{
    int i;


    for (i = 0; i < memberCount; i++)
    {
        if (strcmp(members[i].code, code) == 0)
        {
            return 1;
        }
    }


    return 0;
}
