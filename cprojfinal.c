//
//  cprojfinal.c
//  
//
//  Created by LEKHAN SAATHVIK on 11/06/22.
//



#include <stdio.h>
#include<stdlib.h>
int user();
int balenq();
int withdrawl();
int pinchange();
int deposit();
int admin();
int adbalenq();
int adwithdrawl();
int adpinchange();
int addeposit();

struct bank{
    int num;
    int pin;
    int bal;
};
int main()
{
    int choice_1;
    printf("*****Welcome To ATM****** \n");
    printf("1.login as user\n");
    printf("2.login as an admin\n");
    scanf("%d",&choice_1);
    switch(choice_1){
        case 1:
        user();
        break;
        case 2:
        admin();
        break;
        default:
        printf("INVALID OPTION");
            
    }
    
    return 0;
}
int user(void)
{
  
    int choice_2;
      printf("1. Balance Enquiry\n2. Cash Withdrawl\n3. Pin Change\n4. Deposit\n5. Exit\n");
      scanf("%d",&choice_2);
      switch(choice_2){
          case 1:
          balenq();
              break;
          break;
          case 2:
          withdrawl();
              break;
          case 3:
              pinchange();
              break;
          case 4:
              deposit();
              break;
          case 5:
            exit(0);
          default:
            printf("INVALID OPTION");

        
      }
    return 0;
  }

int balenq(){
    struct bank s[100];
  int numbers[100];
  int i = 0,j=0;
  FILE *file;

  if (file = fopen("user_data.txt", "r"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    fclose(file);

    numbers[i] = '\0';
      while(j<1){
     for (i = 0; numbers[i] != '\0'; i+=3){
          
      
      
       s[j].num=numbers[i];
         s[j].pin=numbers[i+1];
         s[j].bal=numbers[i+2];
              j++;
          }
  }
     
      int bno,pin,choice_3;
      printf("enter your banknumber\n");
      scanf("%d",&bno);
      printf("enter your pin\n");
      scanf("%d",&pin);
      for(int r=0;r<4;r++){
          if(bno==s[r].num && pin==s[r].pin){
              printf("%d\n",s[r].bal);
              break;
          }
          
      }
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_3);
      switch(choice_3){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
  }
    return 0;
}
int withdrawl()
{
    struct bank s[100];
  int numbers[100];
  int i = 0,j=0;
  FILE *file;

  if (file = fopen("user_data.txt", "r+"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    

    numbers[i] = '\0';
      while(j<1){
     for (i = 0; numbers[i] != '\0'; i+=3){
          
      
      
       s[j].num=numbers[i];
         s[j].pin=numbers[i+1];
         s[j].bal=numbers[i+2];
              j++;
          }
  }
      
     
      int bno,pin,wtdamt,choice_4;
      char buff[20];
      printf("enter your banknumber\n");
      scanf("%d",&bno);
      printf("enter your pin\n");
      scanf("%d",&pin);
     // printf("enter the withdraw amt\n");
     // scanf("%d",&wtdamt);
      for(int r=0;r<4;r++){
          if(bno==s[r].num && pin==s[r].pin){
              printf("enter the withdraw amt\n");
              scanf("%d",&wtdamt);
              if(wtdamt<=s[r].bal){
              fseek( file, (7+12*r), SEEK_SET );
              sprintf(buff, "%d",(s[r].bal-wtdamt) );
              fputs(buff, file);

                  printf("New amt:%d\n",(s[r].bal-wtdamt));
                  break;
              }
              else{
                  printf("Insufficient balance\n");
                  break;
              }
          }
        
      }
      fclose(file);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_4);
      switch(choice_4){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }
int pinchange()
{
    struct bank s[100];
  int numbers[100];
  int i = 0,j=0;
  FILE *file;

  if (file = fopen("user_data.txt", "r+"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    

    numbers[i] = '\0';
      while(j<1){
     for (i = 0; numbers[i] != '\0'; i+=3){
          
      
      
       s[j].num=numbers[i];
         s[j].pin=numbers[i+1];
         s[j].bal=numbers[i+2];
              j++;
          }
  }
      
     
      int bno,pin,new_pin,choice_5;
      char bufff[20];
      printf("enter your banknumber\n");
      scanf("%d",&bno);
      printf("enter your pin\n");
      scanf("%d",&pin);
      //printf("enter the new pin\n");
    //  scanf("%d",&new_pin);
      for(int r=0;r<4;r++){
          if(bno==s[r].num && pin==s[r].pin){
              printf("enter the new pin\n");
              scanf("%d",&new_pin);
              fseek( file, (4+12*r), SEEK_SET );
              sprintf(bufff, "%d",new_pin );
              fputs(bufff, file);
              printf("New pin:%d\n",(new_pin));
              break;
          }
         
      }
      fclose(file);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_5);
      switch(choice_5){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }

int deposit()
{
    struct bank s[100];
  int numbers[100];
  int i = 0,j=0;
  FILE *file;

  if (file = fopen("user_data.txt", "r+"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    

    numbers[i] = '\0';
      while(j<1){
     for (i = 0; numbers[i] != '\0'; i+=3){
          
      
      
       s[j].num=numbers[i];
         s[j].pin=numbers[i+1];
         s[j].bal=numbers[i+2];
              j++;
          }
  }
      
     
      int bno,pin,dp_amt,choice_6;
      char buf[20];
      printf("enter your banknumber\n");
      scanf("%d",&bno);
      printf("enter your pin\n");
      scanf("%d",&pin);
    //  printf("enter the deposit amt\n");
     // scanf("%d",&dp_amt);
      for(int r=0;r<4;r++){
          if(bno==s[r].num && pin==s[r].pin){
              printf("enter the deposit amt\n");
              scanf("%d",&dp_amt);

              fseek( file, (7+12*r), SEEK_SET );
              sprintf(buf, "%d",(s[r].bal+dp_amt) );
              fputs(buf, file);
              printf("New amt:%d\n",(s[r].bal+dp_amt));
              break;
          }
         
      }
      fclose(file);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_6);
      switch(choice_6){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }
/*********************************************************************ADMIN PART******************************************************************************************/
struct adbank{
    int adnum;
    int adpin;
    int adbal;
};
int admin(void)
{
  
    int choice_7;
      printf("1. Balance Enquiry\n2. Cash Withdrawl\n3. Pin Change\n4. Deposit\n5. Exit\n");
      scanf("%d",&choice_7);
      switch(choice_7){
          case 1:
          adbalenq();
              break;
          break;
          case 2:
          adwithdrawl();
              break;
          case 3:
              adpinchange();
              break;
          case 4:
              addeposit();
              break;
          case 5:
            exit(0);
          default:
            printf("INVALID OPTION");

        
      }
    return 0;
  }
int adbalenq(){
    struct adbank ads[100];
  int adnumbers[100];
  int adi = 0,adj=0;
  FILE *adfile;

  if (adfile = fopen("admin_data.txt", "r+"))
  {
    while (fscanf(adfile, "%d", &adnumbers[adi]) != EOF)
    {
      adi++;
    }
    fclose(adfile);

    adnumbers[adi] = '\0';
      while(adj<1){
     for (adi = 0; adnumbers[adi] != '\0'; adi+=3){
          
      
      
       ads[adj].adnum=adnumbers[adi];
         ads[adj].adpin=adnumbers[adi+1];
         ads[adj].adbal=adnumbers[adi+2];
              adj++;
          }
  }
     
      int adbno,adpin,choice_8;
      printf("enter your banknumber\n");
      scanf("%d",&adbno);
      printf("enter your pin\n");
      scanf("%d",&adpin);
      for(int adr=0;adr<4;adr++){
          if(adbno==ads[adr].adnum && adpin==ads[adr].adpin){
              printf("%d\n",ads[adr].adbal);
              break;
          }
          
      }
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_8);
      switch(choice_8){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
  }
    return 0;
}
int adwithdrawl()
{
    struct adbank ads[100];
  int adnumbers[100];
  int adi = 0,adj=0;
  FILE *adfile;

  if (adfile = fopen("admin_data.txt", "r+"))
  {
    while (fscanf(adfile, "%d", &adnumbers[adi]) != EOF)
    {
      adi++;
    }
    

    adnumbers[adi] = '\0';
      while(adj<1){
     for (adi = 0; adnumbers[adi] != '\0'; adi+=3){
          
      
      
       ads[adj].adnum=adnumbers[adi];
         ads[adj].adpin=adnumbers[adi+1];
         ads[adj].adbal=adnumbers[adi+2];
              adj++;
          }
  }
      
     
      int adbno,adpin,adwtdamt,choice_9;
      char adbuff[20];
      printf("enter your banknumber\n");
      scanf("%d",&adbno);
      printf("enter your pin\n");
      scanf("%d",&adpin);
     // printf("enter the withdraw amt\n");
     // scanf("%d",&wtdamt);
      for(int adr=0;adr<4;adr++){
          if(adbno==ads[adr].adnum && adpin==ads[adr].adpin){
              printf("enter the withdraw amt\n");
              scanf("%d",&adwtdamt);
              if(adwtdamt<=ads[adr].adbal){
              fseek( adfile, (7+12*adr), SEEK_SET );
              sprintf(adbuff, "%d",(ads[adr].adbal-adwtdamt) );
              fputs(adbuff, adfile);

                  printf("New amt:%d\n",(ads[adr].adbal-adwtdamt));
                  break;
              }
              else{
                  printf("Insufficient balance\n");
                  break;
              }
          }
          
      }
      fclose(adfile);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_9);
      switch(choice_9){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }
int adpinchange()
{
    struct adbank ads[100];
  int adnumbers[100];
  int adi = 0,adj=0;
  FILE *adfile;

  if (adfile = fopen("admin_data.txt", "r+"))
  {
    while (fscanf(adfile, "%d", &adnumbers[adi]) != EOF)
    {
      adi++;
    }
    

    adnumbers[adi] = '\0';
      while(adj<1){
     for (adi = 0; adnumbers[adi] != '\0'; adi+=3){
          
      
      
       ads[adj].adnum=adnumbers[adi];
         ads[adj].adpin=adnumbers[adi+1];
         ads[adj].adbal=adnumbers[adi+2];
              adj++;
          }
  }
      
     
      int adbno,adpin,adnew_pin,choice_11;
      char adbufff[20];
      printf("enter your banknumber\n");
      scanf("%d",&adbno);
      printf("enter your pin\n");
      scanf("%d",&adpin);
      //printf("enter the new pin\n");
    //  scanf("%d",&new_pin);
      for(int adr=0;adr<4;adr++){
          if(adbno==ads[adr].adnum && adpin==ads[adr].adpin){
              printf("enter the new pin\n");
              scanf("%d",&adnew_pin);
              fseek( adfile, (4+12*adr), SEEK_SET );
              sprintf(adbufff, "%d",adnew_pin );
              fputs(adbufff, adfile);
              printf("New pin:%d\n",(adnew_pin));
              break;
          }
          
      }
      fclose(adfile);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_11);
      switch(choice_11){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }

int addeposit()
{
    struct adbank ads[100];
  int adnumbers[100];
  int adi = 0,adj=0;
  FILE *adfile;

  if (adfile = fopen("admin_data.txt", "r+"))
  {
    while (fscanf(adfile, "%d", &adnumbers[adi]) != EOF)
    {
      adi++;
    }
    

    adnumbers[adi] = '\0';
      while(adj<1){
     for (adi = 0; adnumbers[adi] != '\0'; adi+=3){
          
      
      
       ads[adj].adnum=adnumbers[adi];
         ads[adj].adpin=adnumbers[adi+1];
         ads[adj].adbal=adnumbers[adi+2];
              adj++;
          }
  }
      
     
      int adbno,adpin,addp_amt,choice_13;
      char adbuf[20];
      printf("enter your banknumber\n");
      scanf("%d",&adbno);
      printf("enter your pin\n");
      scanf("%d",&adpin);
    //  printf("enter the deposit amt\n");
     // scanf("%d",&dp_amt);
      for(int adr=0;adr<4;adr++){
          if(adbno==ads[adr].adnum && adpin==ads[adr].adpin){
              printf("enter the deposit amt\n");
              scanf("%d",&addp_amt);

              fseek( adfile, (7+12*adr), SEEK_SET );
              sprintf(adbuf, "%d",(ads[adr].adbal+addp_amt) );
              fputs(adbuf, adfile);
              printf("New amt:%d\n",(ads[adr].adbal+addp_amt));
              break;
          }
         
      }
      fclose(adfile);
      printf("Do you want to continue 1.YES 2.NO\n");

      scanf("%d",&choice_13);
      switch(choice_13){
          case 1:
          main();
          break;
          case 2:
          
          break;
          default:
          printf("INVALID OPTION");
              
      }
          }
    return 0;
      }
 

