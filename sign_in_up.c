#include <stdio.h>
#include <string.h>

char username[30];
char password[15];
int acc_created = 0;

int menu()
{
    int option;
    printf("*************Bus Reservation System***********");
    printf("\n----------------------------------------------");
    printf("\nPress 1 for Sign Up ");
    printf("\nPress 2 for Sign In ");
    printf("\nPress 3 for Exit");
    printf("\nChoose option from 1-3: ");
    scanf("%d", &option);
    return option;
}

void sign_up()
{
    printf("\n--- Please Enter Your Details For Sign up ---\n");
    printf("\tEnter your username: ");
    scanf("%s", username);
    printf("\tEnter your password: ");
    scanf("%s", password);
    acc_created = 1;
    printf("\n  Your Account is created successfully \n");
}

void sign_in()
{
    char user[30];
    char pass[15];

    if (acc_created != 1)
    {
        printf("\nNo account found Please sign up first.\n");
        return;
    }

    printf("\n------ Please Enter Your Details For Sign In ------\n");
    printf("\tEnter your username: ");
    scanf("%s", user);
    printf("\tEnter your password: ");
    scanf("%s", pass);

   
    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
    {
        printf("\n Login successful Welcome %s +_+\n", username);
    }
    else
    {
        printf("\n Invalid username or password. Try again.\n");
    }
}

int main()
{
    int Output;

    while (1)
    {
        Output = menu();

        if (Output == 1)
        {
            sign_up();
        }
        else if (Output == 2)
        {
            sign_in();
        }
        else if (Output == 3)
        {
            printf("\nThank you for Choosing our service.\n");
            break;
        }
        else
        {
            printf("\n Invalid option! Please try again.\n");
        }
    }

    return 0;
}
