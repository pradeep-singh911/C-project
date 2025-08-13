#include <stdio.h>
#include <string.h>

#define Buses 3 
#define Seats 50

char username[30];
char password[15];
int acc_created = 0;

void book_ticket();
void cancel_ticket();
void bus_status();
void show_buses();

char bus_names[Buses][30] = {"Abhi Bus ","Red Bus","Flix Bus "};
char bus_pick [Buses][30] = {"Jodhpur","Jaipur","Delhi"};
char bus_dest [Buses][30] = {"Dehradun","Mumbai","Bangalore"};
int seats[Buses][Seats] = {0};

     void show_buses()
      {
            printf("\n--- Buses List ---\n");
   for (int i = 0; i < Buses; i++)
       {
      printf("%d. %s => Pickup: %s*********To*******Destination: %s\n ", i + 1, bus_names[i], bus_pick[i] ,bus_dest[i]);
                }
}

        void interface()
        {
              int choice;
                     while (1)
          {
            printf("**********User Interface**********");
            printf("\n----------------------------------");
            printf("\nPress 1 for Book a Ticket ");
            printf("\nPress 2 for Cancel a ticket ");
            printf("\nPress 3 for Check bus status");
            printf("\nPress 4 for logout");
            printf("\nChoose option from 1-4: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                book_ticket();
            }
            else if (choice ==2)
            {
                cancel_ticket();
            }
            else if (choice ==3)
            {
                bus_status();
            }
            else if (choice ==4)
            {
            printf("Logging Out....");
            return;
            }
            else 
            {
                printf("Please Enter Valid option");
            }
        }
 }
            void book_ticket()
            {
            int bus_no, seat_no;
            char passenger[30];

            show_buses();
            printf("Select bus number (1-%d): ", Buses);
            scanf("%d", &bus_no);

            if (bus_no < 1 || bus_no > Buses)
            {
            printf("Invalid bus number!\n");
            return;
            }

            printf("Enter passenger name: ");
            scanf("%s", passenger);

            printf("Enter seat number to book (1-%d): ", Seats);
            scanf("%d", &seat_no);

            if (seat_no < 1 || seat_no > Seats)
            {
            printf(" Invalid seat number!\n");
            return;
            }

            if (seats[bus_no - 1][seat_no - 1] == 1) 
            {
            printf(" Seat %d in %s is already booked!\n", seat_no, bus_names[bus_no - 1]);
            } 
            else if  (seats[bus_no - 1][seat_no - 1] = 1)
            {
            printf(" Seat number %d booked for %s in %s route:(%s -> %s) \n",
            seat_no, passenger, bus_names[bus_no - 1],bus_pick[bus_no- 1] , bus_dest[bus_no - 1]);
            }
        }

                void cancel_ticket()
                {
                int bus_no, seat_no;
                    char passenger[30];

                    show_buses();
                    printf("Select bus number 1-%d: ", Buses);
                    scanf("%d", &bus_no);

                    if (bus_no < 1 || bus_no > Buses)
                    {
                        printf("Invalid bus number!\n");
                        return;
                    }

                    printf("Enter passenger name to cancel ticket: ");
                    scanf("%s", passenger);

                    printf("Enter seat number to Cancel (1-%d): ", Seats);
                    scanf("%d", &seat_no);

                    if (seat_no < 1 || seat_no > Seats) {
                        printf(" Invalid seat number!\n");
                        return;
                    }

                    if (seats[bus_no - 1][seat_no - 1] == 0) 
                    {
                        printf(" Seat %d in %s is Not Booked Yet!\n", seat_no, bus_names[bus_no - 1]);
                    }
                     else 
                    {
                        (seats[bus_no - 1][seat_no - 1] = 0);
                        printf(" Seat number %d booked for %s in %s Route:(%s -> %s)   is cancelled Succesfully\n",
                            seat_no, passenger, bus_names[bus_no - 1],bus_pick[bus_no- 1] , bus_dest[bus_no - 1]);
                        
                    }
                }
                
            void bus_status()
                    {
                

    }
    int menu()
    {
        int option;
        printf("\n*************Bus Reservation System***********");
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
        scanf(" %[^\n]", username);
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
        scanf(" %[^\n]", user);
        printf("\tEnter your password: ");
        scanf("%s", pass);

    
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
            printf("\n Login successful Welcome %s +_+\n", username);
            interface();
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
