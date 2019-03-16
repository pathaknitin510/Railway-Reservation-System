#include<stdio.h>
#include<ctype.h>
#include "conio2.h"
#include "rlyres.h"

int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=80;i++)
    {
      printf("-");
    }
    printf("Select an option\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No\n");
    printf("5- View All Bookings\n");
    printf("6- View Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n");
    printf("\nEnter choice:");
    scanf("%d",&choice);

     return choice;
}
  void add_trains()
  {
      FILE *fp=fopen("E:\\myproject\\alltrains.dat","rb");
      if(fp==NULL)
      {
          Train alltrains[4]={
          {
              "123","BPL","GWA",2100,1500
          },
           {
               "546","BPL","DEL",3500,2240
           },
           {
               "345","HBJ","AGR",1560,1135
           },
           {
               "896","HBJ","MUM",4500,3360
           }
          };
           fp=fopen("e:\\myproject\\alltrains.dat","wb");
           fwrite(alltrains,4*sizeof(Train),1,fp);
           fclose(fp);
      }
      else
      {
          fclose(fp);
      }
  }
  void view_trains()
  { int i;
    Train s;
     textcolor(YELLOW);
     printf("\nTRAIN NO\tFROM\tTO\tFIRST AC FAIR\t SECOND AC FAIR\n");
     for(i=1;i<=80;i++)
        printf("-");
        FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
        while(fread(&s,1*sizeof(Train),1,fp)==1)
      printf("\n%s\t\t%s\t%s\t%d\t\t %d",s.train_no,s.from,s.to,s.fac_fare,s.sac_fare);
      fclose(fp);
      textcolor(WHITE);
      printf("\n\n\n\n\nPress any key to go back to the main screen");
      getch();
      clrscr();
  }
 int check_train_no(char* trainno)
 {
     FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
     Train s;
     while(fread(&s,1*sizeof(s),1,fp)==1)
     {
         if(strcmp(s.train_no,trainno)==0)
           { fclose(fp);
               return 1;
           }
    }
     fclose(fp);
     return 0;
 }
  int check_mob_no(char *p_mob)
  {
      if(strlen(p_mob)!=10)
          return 0;
      while(*p_mob!='\0')
      {
          if(isdigit(*p_mob)==0)
            return 0;
            p_mob++;
      }
       return 1;
  }
Passenger* get_passenger_details()
{
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    static Passenger psn;
    printf("Enter Passenger Name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
    printf("Enter Gender(M/F):");
    scanf("%c",&psn.gender);
    if(psn.gender=='0')
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
   }
    while(psn.gender!='M'&&psn.gender!='F')
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Gender should be M or F(in uppercase)");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(19,2);
        printf(" ");
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(19,2);
        scanf("%c",&psn.gender);
        fflush(stdin);
    }
    printf("Enter Train Number:");
    scanf("%s",psn.train_no);
     if(strcmp(psn.train_no,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
     while(check_train_no(psn.train_no)==0)
     {
         gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Invalid Train No.");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(20,3);
        printf("\t\t\t");
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(20,3);
        scanf("%s",psn.train_no);
        fflush(stdin);
     }
     printf("Enter Travelling Class(First AC-F,Second AC-S):");
     fflush(stdin);
     scanf("%c",&psn.p_class);
     if(psn.gender=='0')
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
   }
   while(psn.p_class!='S'&&psn.p_class!='F')
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Class should be F or S(in uppercase)");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(48,4);
        printf(" ");
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(48,4);
        scanf("%c",&psn.p_class);
        fflush(stdin);
    }
     printf("Enter Address:");
     fflush(stdin);
    fgets(psn.address,20,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
    printf("Enter Age:");
    scanf("%d",&psn.age);
    if(psn.age==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
   }
    while(psn.age<0)
    {
         gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Age should be greater than 0");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(11,6);
        printf("\t");
        gotoxy(1,25);
        printf("\t\t\t\t\t");
        gotoxy(11,6);
        scanf("%d",&psn.age);
        fflush(stdin);
    }
    printf("Enter Mobile No:");
    fflush(stdin);
    fgets(psn.mob_no,11,stdin);
    pos=strchr(psn.mob_no,'\n');
    if(pos!=NULL)
        *pos='\0';
    if(strcmp(psn.mob_no,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
     while(check_mob_no(psn.mob_no)==0)
      {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Invalid mobile No.");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(17,7);
        printf("\t\t\t");
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(17,7);
        fgets(psn.mob_no,11,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        fflush(stdin);
      }
       return (&psn);
}
 int get_booked_ticket_count(char* train_no,char tc)
 {
     FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
     if(fp==NULL)
       return 0;
       Passenger pr;
       int count=0;
     while(fread(&pr,sizeof(pr),1,fp)==1)
     {
         if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
            ++count;
     }
      fclose(fp);
      return count;
 }
  int last_ticket_no()
  {
      FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
      if(fp==NULL)
        return 0;
        Passenger pr;
        //if(ftell(fp)==0)
       // return 0;
      fseek(fp,-1*sizeof(pr),SEEK_END);
      fread(&pr,sizeof(pr),1,fp);
      fclose(fp);
      //if(ftell(fp)==0)
       // return 0;
        printf("%d",pr.ticketno);
        if(pr.ticketno>100000)
            return 0;
      return pr.ticketno;
  }
  int book_ticket(Passenger P)
  {
      int result=get_booked_ticket_count(P.train_no,P.p_class);
      if(result==30)
      {
          textcolor(LIGHTRED);
          printf("All seats full in train no %s in %c class!!\n");
          printf("Booking Closed!!");
          return -1;
      }
       int count=last_ticket_no()+1;
       P.ticketno=count;
       FILE *fp=fopen("e:\\myproject\\allbookings.dat","ab");
       if(fp==NULL)
       {
           printf("Sorry!!File can't be opened");
           return -1;
       }
       fwrite(&P,sizeof(P),1,fp);
       fclose(fp);
       return count;
  }
   void view_ticket(int ticket_no)
   {
       int i=0;
       clrscr();
       Passenger P;
     FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
     while(fread(&P,sizeof(P),1,fp)==1)
     {
         if(P.ticketno==ticket_no)
         {
            textcolor(YELLOW);
           printf("TRAIN NO    TICKET NO    CLASS    NAME                    MOBILE\n");
           if(i==0)
           for(i=1;i<=80;i++)
            printf("-");
           printf("\n%s\t\t%d\t   %c\t  %s",P.train_no,P.ticketno,P.p_class,P.p_name);
           gotoxy(59,3);
           printf("%s",P.mob_no);
           fclose(fp);
           textcolor(WHITE);
           gotoxy(1,10);
           printf("Press any key to go back to the main screen");
           break;
         }
     }
}
 void view_all_bookings()
 {
     Passenger P;
     int i=0;
     FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
     while(fread(&P,sizeof(P),1,fp)==1)
     {
         textcolor(YELLOW);
           if(i==0)
           {printf("TRAIN NO    TICKET NO    CLASS    NAME                    MOBILE\n");
            for(i=1;i<=80;i++)
            printf("-");
            i=3;
           }
           printf("\n%s\t\t%d\t   %c\t  %s",P.train_no,P.ticketno,P.p_class,P.p_name);
           gotoxy(59,i);
           printf("%s",P.mob_no);
           i++;
           gotoxy(1,i);

    }
     textcolor(WHITE);
     gotoxy(1,10);
     printf("\nPress any key to go back to the main screen");
      fclose(fp);
 }
  void view_bookings(char* train_no)
  {
      Passenger P;
      int i=0;
     FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
     while(fread(&P,sizeof(P),1,fp)==1)
     {
         if(strcmp(P.train_no,train_no)==0)
         {
             textcolor(YELLOW);

           if(i==0)
          { printf("\nTRAIN NO    TICKET NO    CLASS    NAME                    MOBILE\n");
            for(i=1;i<=80;i++)
            printf("-");
            i=5;
          }
           printf("\n%s\t\t%d\t   %c\t  %s",P.train_no,P.ticketno,P.p_class,P.p_name);
           gotoxy(59,i);
           printf("  %s",P.mob_no);
           i++;
           gotoxy(1,i);
         }
         }
         textcolor(WHITE);
         gotoxy(1,10);
        printf("\nPress any key to go back to the main screen");
       fclose(fp);
  }
   int accept_ticket_no()
   {
       int ticket_no;
       int valid=1;
       printf("Enter ticket no:");
       do
       {
           scanf("%d",&ticket_no);
           if(ticket_no==0)
           {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Process Cancelled!!");
               return 0;
           }
           if(ticket_no<0)
           {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error!!Ticket number should be positive");
               getch();
               valid=0;
               gotoxy(17,1);
               printf("\t\t\t\t\t\t");
               gotoxy(17,1);
               textcolor(YELLOW);
           }
       }
        while(valid==0);
   }
   int cancel_ticket(int ticket_no)
   {
       Passenger P;
       int found=0;
       FILE *fp1=fopen("e:\\myproject\\allbookings.dat","rb+");
       if(fp1==NULL)
       {
           textcolor(LIGHTRED);
           printf("\nNo Bookings Done Yet ");
           return -1;
       }
      FILE *fp2=fopen("e:\\myproject\\temp.dat","wb+");
      while(fread(&P,sizeof(P),1,fp1)==1)
      {
          if(P.ticketno!=ticket_no)
          {
              fwrite(&P,sizeof(P),1,fp2);
          }
          else
          {
              found=1;
          }
      }
       fclose(fp1);
       fclose(fp2);
       if(found==0)
        remove("e:\\myproject\\temp.dat");
       else
       {
           remove("e:\\myproject\\allbookings.dat");
           rename("e:\\myproject\\temp.dat","e:\\myproject\\allbookings.dat");
       }
        return found;
   }
   char* accept_mob_no()
   {
      static char mob_no[11];
    printf("Enter Mobile No:");
    fflush(stdin);
    fgets(mob_no,11,stdin);
   char* pos=strchr(mob_no,'\n');
    if(pos!=NULL)
    *pos='\0';
     if(strcmp(mob_no,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Process Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
     while(check_mob_no(mob_no)==0)
      {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Invalid mobile No.");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(17,1);
        printf("\t\t\t");
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(17,1);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        fflush(stdin);
      }
      char *m=mob_no;
       return (m);
}
int* get_ticket_no(char* p_mob_no)
{
  FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb+");
  if(fp==NULL)
    return NULL;
  int count=0;
  Passenger p;
  while(fread(&p,sizeof(p),1,fp)==1)
  {
      if(strcmp(p.mob_no,p_mob_no)==0)
        count++;
  }
  if(count==0)
    {
      fclose(fp);
     return NULL;
    }
  int *ptr=(int *)malloc(sizeof(int)*(count+1));
  rewind(fp);
  count=0;
   while(fread(&p,sizeof(p),1,fp)==1)
  {
      if(strcmp(p.mob_no,p_mob_no)==0)
      {
          ptr[count]=p.ticketno;
          count++;
      }
  }
      ptr[count]=-1;
      fclose(fp);
      return ptr;
}
void view_all_tickets(char* pmob_no,int* pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("No tickets booked against the mobile number %s",pmob_no);
        return ;
    }
    textcolor(YELLOW);
    printf("Following are tickets booked against the mobile number %s\n\n",pmob_no);
    printf("TICKET NO\n");
    int i;
    for(i=1;i<=9;i++)
        printf("-");
    for(i=0;pticket_no[i]!=-1;i++)
        printf("\n%d",pticket_no[i]);

    textcolor(WHITE);
    printf("\nPress any key to go back to the main screen");
    getch();

}
char* accept_train_no()
{
    static char train_no[10];
      printf("Enter Train Number:");
      scanf("%s",train_no);
     if(strcmp(train_no,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Process Cancelled!!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;

    }
     while(check_train_no(train_no)==0)
     {
         gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Error!! Invalid Train No.");
        fflush(stdin);
         getch();
        textcolor(YELLOW);
        gotoxy(20,3);
        printf("\t\t\t");
        gotoxy(1,25);
        printf("\t\t\t\t");
        gotoxy(20,3);
        scanf("%s",train_no);
        fflush(stdin);
     }

      return (train_no);
}
int cancel_train(char* ptrain_no)
{
      Passenger P;
       int found=0;
       FILE *fp1=fopen("e:\\myproject\\allbookings.dat","rb+");
       if(fp1==NULL)
       {
           textcolor(LIGHTRED);
           printf("\nNo Bookings Done Yet ");
           return -1;
       }
      FILE *fp2=fopen("e:\\myproject\\temp.dat","wb+");
      while(fread(&P,sizeof(P),1,fp1)==1)
      {
          if(strcmp(P.train_no,ptrain_no)!=0)
          {
              fwrite(&P,sizeof(P),1,fp2);
          }
          else
          {
              found=1;
          }
      }
       fclose(fp1);
       fclose(fp2);
       if(found==0)
        remove("d:\\myproject\\temp.dat");
       else
       {
           remove("e:\\myproject\\allbookings.dat");
           rename("e:\\myproject\\temp.dat","e:\\myproject\\allbookings.dat");
       }
        return found;
   }



