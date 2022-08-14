#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;
FILE *fp1;
FILE *fp2;
struct costumer
{
 char id[20];
 char name[30];
 char mobileno[12];
 char pin[8];
 char balance[8];
 char expdate[8];
}s[2];
char id1[20];
void main()
{
void balenquiry();
void withdrawal();
void changepin();
void deposit();
void mobileno();
void billpayment();
char op[5], ch;
int option;
clrscr();
do
{
  fp = fopen("user.txt","w");
  fp2 = fopen("user2.txt","r");
  while((ch = fgetc(fp2))!=EOF)
	fputc(ch,fp);
  fclose(fp);
  fclose(fp2);
  printf("\nEnter one of the following options:\n1:BALANCE ENQUIRY\n2:WITHDRAWAL\n3:CHANGE PIN\n4:DEPOSIT\n5:MOBILE NUMBER CHANGE\n6:BILL PAYMENT\n7: to exit ");
  scanf("%d",&option);
  if(option!=7)
  {
    printf("enter account number: ");
    fflush(stdin);
    gets(id1);
    fp=fopen("user.txt","r");
    do
    {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[0].id,s[0].name,s[0].mobileno,s[0].pin,s[0].balance,s[0].expdate);
    }while(strcmp(s[0].id,id1)!=0);
    fclose(fp);
    switch(option)
    {
	case 1:balenquiry();break;
	case 2:withdrawal();break;
	case 3:changepin();break;
	case 4:deposit();break;
	case 5:mobileno();break;
	case 6:billpayment();break;
    }
  }
  printf("Thank you for using our services\n");
  printf("Have a great day :)\n");
  getch();
}while(option!=7);
}


void balenquiry()
{
 char cpin[8];
 printf("enter pin: ");
 fflush(stdin);
 gets(cpin);
 if(strcmp(cpin,s[0].pin)==0)
{
  fp1=fopen("atmres.txt","w");
  fprintf(fp1,"        STATE BANK OF INDIA\n");
  fprintf(fp1,"Card number      : XXXX XXXX XXXX XXXX\n");
  fprintf(fp1,"Account holder name : %s\n",s[0].name);
  fprintf(fp1,"Mobile number       : %s\n",s[0].mobileno);
  fprintf(fp1,"Your current account balance is %s\n",s[0].balance);
  fprintf(fp1,"             THANK YOU \n");
  fclose(fp1);
}
 else
  printf("Incorrect pin\n");
}

void mobileno()
{
  char nmobile[12], cpin[8];
  printf("Enter your pin: ");
  fflush(stdin);
  gets(cpin);
  if(strcmp(cpin,s[0].pin)==0)
  {
    printf("Enter new mobile number: ");
    fflush(stdin);
    gets(nmobile);
    strcpy(s[0].mobileno,nmobile);
    printf("Mobile number updated successfully\n");
    fp = fopen("user.txt","r");
    fp2 = fopen("user2.txt","w");
    do
    {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
    }while(strcmp(s[0].id,s[1].id)!=0);
    fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[0].id,s[0].name,s[0].mobileno,s[0].pin,s[0].balance,s[0].expdate);
    do
    {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
    }while(!feof(fp));
    fclose(fp);
    fclose(fp2);
  }
  else
    printf("Incorrect pin\n");
}

void changepin()
{
  char cpin[8],npin[8];
  printf("Enter old pin: ");
  fflush(stdin);
  gets(cpin);
  if(strcmp(cpin,s[0].pin)==0)
  {
    printf("Enter new pin: ");
    fflush(stdin);
    gets(npin);
    strcpy(s[0].pin,npin);
    printf("Pin changed successfully\n");
    fp = fopen("user.txt","r");
    fp2 = fopen("user2.txt","w");
    do
    {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
    }while(strcmp(s[0].id,s[1].id)!=0);
    fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[0].id,s[0].name,s[0].mobileno,npin,s[0].balance,s[0].expdate);
    do
    {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
    }while(!feof(fp));
    fclose(fp);
    fclose(fp2);
  }
  else
    printf("Incorrect pin\n");
}


void withdrawal()
{
 char amount[8],cpin[8],receipt[5],string[10];
 printf("Enter amount to be withdrawn : ");
 fflush(stdin);
 gets(amount);
 printf("Enter pin : ");
 fflush(stdin);
 gets(cpin);
 if(strcmp(cpin,s[0].pin)==0)
 {
  if((strcmp(amount,s[0].balance)>0)&& (strlen(amount)>=strlen(s[0].balance)))
   printf("Withdrawal amount is greater than your current account balance\n");
  else if(atoi(amount)>20000)
   printf("Withdrawal amount is greater than per day limit");
  else
  {
   printf("Do you want a printed receipt.Enter yes or no\n");
   fflush(stdin);
   gets(receipt);
   if(strcmp(receipt,"yes")==0)
   {
     fp1=fopen("atmres.txt","w");
     fprintf(fp1,"        STATE BANK OF INDIA\n");
     fprintf(fp1,"Card number      : XXXX XXXX XXXX XXXX\n");
     fprintf(fp1,"Account holder name : %s\n",s[0].name);
     fprintf(fp1,"Mobile number       : %s\n",s[0].mobileno);
     fprintf(fp1,"Amount withdrawn    : %s\n",amount);
     fprintf(fp1,"Available Balance   : %s\n",itoa((atoi(s[0].balance))-(atoi(amount)),string,10));
     fprintf(fp1,"           THANK YOU \n");
     fclose(fp1);
   }
   fp = fopen("user.txt","r");
   fp2 = fopen("user2.txt","w");
   do
   {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(strcmp(s[0].id,s[1].id)!=0);
   fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[0].id,s[0].name,s[0].mobileno,s[0].pin,itoa((atoi(s[0].balance)-atoi(amount)), string, 10),s[0].expdate);
   do
   {
     fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
     if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(!feof(fp));
   fclose(fp);
   fclose(fp2);
   printf("Bill payment successful");
  }
 }
}

void deposit()
{
 char amount[10],  cpin[8], string[10];
 printf("Enter your pin: ");
 fflush(stdin);
 gets(cpin);
 if(strcmp(cpin,s[0].pin)==0)
 {
   printf("Enter amount to be deposited: ");
   fflush(stdin);
   gets(amount);
   fp1=fopen("atmres.txt","w");
   fprintf(fp1,"        STATE BANK OF INDIA\n");
   fprintf(fp1,"Card number      : XXXX XXXX XXXX XXXX\n");
   fprintf(fp1,"Account holder name : %s\n",s[0].name);
   fprintf(fp1,"Mobile number       : %s\n",s[0].mobileno);
   fprintf(fp1,"Amount deposited    : %s\n",amount);
   fprintf(fp1,"Available Balance   : %s\n",itoa((atoi(s[0].balance))+(atoi(amount)),string,10));
   fprintf(fp1,"           THANK YOU \n");
   fclose(fp1);
   fp = fopen("user.txt","r");
   fp2 = fopen("user2.txt","w");
   do
   {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(strcmp(s[0].id,s[1].id)!=0);
   fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[0].id,s[0].name,s[0].mobileno,s[0].pin,itoa((atoi(s[0].balance)+atoi(amount)), string, 10),s[0].expdate);
   do
   {
     fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
     if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(!feof(fp));
   fclose(fp);
   fclose(fp2);
 }
 else
   printf("Incorrect pin\n");
}

void billpayment()
{
 char amount[8],cpin[8],receipt[5],string[10];
 printf("Enter amount to be payed : ");
 fflush(stdin);
 gets(amount);
 printf("Enter pin : ");
 fflush(stdin);
 gets(cpin);
 if(strcmp(cpin,s[0].pin)==0)
 {
  if(atoi(amount)>atoi(s[0].balance))
   printf("Amount to be payed is greater than your current account balance\n");
  else {
   printf("Do you want a printed receipt.Enter yes or no\n");
   fflush(stdin);
   gets(receipt);
   if(strcmp(receipt,"yes")==0)
   {
     fp1=fopen("atmres.txt","w");
     fprintf(fp1,"        STATE BANK OF INDIA\n");
     fprintf(fp1,"Card number      : XXXX XXXX XXXX XXXX\n");
     fprintf(fp1,"Account holder name : %s\n",s[0].name);
     fprintf(fp1,"Mobile number       : %s\n",s[0].mobileno);
     fprintf(fp1,"Amount payed        : %s\n",amount);
     fprintf(fp1,"Available Balance   : %s\n",itoa((atoi(s[0].balance))-(atoi(amount)),string,10));
     fprintf(fp1,"           THANK YOU \n");
     fclose(fp1);
   }
   fp = fopen("user.txt","r");
   fp2 = fopen("user2.txt","w");
   do
   {
      fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
      if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(strcmp(s[0].id,s[1].id)!=0);
   fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[0].id,s[0].name,s[0].mobileno,s[0].pin,itoa((atoi(s[0].balance)-atoi(amount)), string, 10),s[0].expdate);
   do
   {
     fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
     if(strcmp(s[0].id,s[1].id)!=0)
	fprintf(fp2,"%s\n%s\n%s\n%s\n%s\n%s\n",s[1].id,s[1].name,s[1].mobileno,s[1].pin,s[1].balance,s[1].expdate);
   }while(!feof(fp));
   fclose(fp);
   fclose(fp2);
  }
 }
}
