#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{
    add_trains();
    int choice;
    char *ptrain_no;
    char *pmob_no;
    int *pticket_no;
    int *ptr;
    int value;
    while(1)
    { int ticket_no;
      Passenger* ptr;
      char train_no[20];
       choice=enterchoice();
       if(choice==9)
         exit(0);
         switch(choice)
         {
         case 1:
             view_trains();
            break;
         case 2:
             clrscr();
             ptr=get_passenger_details();
             clrscr();
             if(ptr!=NULL)
             {
                 ticket_no=book_ticket(*ptr);
                 if(ticket_no==-1)
                 {
                     textcolor(LIGHTRED);
                     printf("Booking Failed!!");
                     textcolor(WHITE);
                printf("\n\n\nPress any key to go back to main screen");
                     getch();
                     clrscr();
                 }

              if(ticket_no!=-1)
              {
                  textcolor(YELLOW);
                  printf("Booking Successful!!\n");
                  textcolor(LIGHTGREEN);
                  printf("Your Ticket No is %d",ticket_no);
                  textcolor(YELLOW);
                  printf("\nHappy Journey!!");
                  textcolor(WHITE);
             printf("\n\n\nPress any key to go back to main screen");
                  getch();
                  clrscr();
              }
             }
            break;
         case 3:
             clrscr();
             ticket_no=accept_ticket_no();
             if(ticket_no!=0)
             view_ticket(ticket_no);
             getch();
             clrscr();
             break;
         case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                 ptr=get_ticket_no(pmob_no);
                 view_all_tickets(pmob_no,ptr);
            }
            getch();
            clrscr();
            break;
         case 5:
            clrscr();
            view_all_bookings();
            getch();
            clrscr();
            break;
         case 6:
            clrscr();
            printf("Enter train no to see all bookings of train:");
            scanf("%s",train_no);
            view_bookings(train_no);
            getch();
            clrscr();
            break;
         case 7:
             clrscr();
             ticket_no=accept_ticket_no();
             if(ticket_no!=0)
             value=cancel_ticket(ticket_no);
             if(value==0)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!No tickets booked against the ticket number %d",ticket_no);
             }
             else
             {
                 textcolor(LIGHTGREEN);
                 printf("Ticket number %d successfully cancelled!!",ticket_no);
             }
              textcolor(WHITE);
             printf("\n\n\nPress any key to go back to main screen");
             getch();
             clrscr();
            break;
         case 8:
             clrscr();
             ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
             value=cancel_train(ptrain_no);
             if(value==0)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!No tickets booked in the train number %s",ptrain_no);
             }
             else
             {
                 textcolor(LIGHTGREEN);
                 printf("Train number %s successfully cancelled!!",ptrain_no);
             }
             textcolor(WHITE);
             printf("\n\n\nPress any key to go back to main screen");
             getch();
             clrscr();
            break;
         default:
            textcolor(LIGHTRED);
            printf("Wrong Choice!Try again\n");
            getch();
            clrscr();
         }

         }
      return 0;
}
