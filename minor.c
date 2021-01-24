#include<stdio.h>
#include<string.h>
#define BAL 100000

char *epass;
char user_name2[50];
char choice;
char *encryption(char *str,int x)
  {

   int i;

   //using switch case statements
   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 96;

      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 96;


      break;

   default:
      printf("\nError\n");
   }
   return (char *)str;
}


       int main()                                            // MAIN FUNCTION
{
       menu();                                           // MENU FUNCTION
}


       void Register()                                      // REGISTER FUNCTION TO REGISTER NEW CUSTOMERS
{      char  customer_name[50];
       int  bank_no;
       char  user_name[50];
       char   password[50];
       int tvalue=0;

       printf("Enter information of Customer:\n");
       FILE *fp = fopen("bankdatabase.csv", "a+");


    if (!fp)
	{
        printf("Can't open file\n");
        return 0;
    }

      printf("\nEnter Username : \n");                // REGISTERING USER DETAILS IN THE DATABASE .
 	  gets(user_name);
 	  system("cls");


 	  printf("\nEnter Password : \n");
 	     int i; char ch;

       for(i=0;i<6;i++)
      {
       ch = getch();
       password[i] = ch;
       ch = '*' ;
       printf("%c",ch);
      }
 	  epass = encryption(password,1);

 	  system("cls");

 	  printf("\nEnter Customer Name :\n");

 	  gets(customer_name);
      system("cls");


 	  printf("\n\nSELECT YOUR BANK ACCOUNT\n\n");
      printf("\n\n1.Allahabad Bank\n2.Andhra Bank\n3.Axis Bank\n4.Bank of Bahrain and Kuwait\n5.Bank of Baroda - Corporate Banking\n6.Bank of Baroda - Retail Banking\n7.Bank of India\n8.Bank of Maharashtra\n9.Canara Bank\n10.Central Bank of India\n11.City Union Bank\n12.Corporation Bank\n13.Deutsche Bank\n14.Development Credit Bank\n15.Dhanlaxmi Bank\n16.Federal Bank\n16.Indian Bank\n17.Indian Overseas Bank\n18.IndusInd Bank\n19.ING Vysya Bank\n20.Jammu and Kashmir Bank\n21.Karnataka Bank Ltd\n22.Karur Vysya Bank\n23.Kotak Bank\n23.Laxmi Vilas Bank\n24.Oriental Bank of Commerce\n25.Punjab National Bank - Corporate Banking\n26.Punjab National Bank - Retail Banking\n27.Punjab & Sind Bank\n28.Shamrao Vitthal Co-operative Bank\n29.South Indian Bank\n30.State Bank of Bikaner & Jaipur\n31.State Bank of Hyderabad\n32.State Bank of India\n33.State Bank of Mysore\n34.State Bank of Patiala\n35.State Bank of Travancore\n36.Syndicate Bank\n37.Tamilnad Mercantile Bank Ltd.\n38.UCO Bank\n39.Union Bank of India\n40.United Bank of India\n41.Vijaya Bank\n42.Yes Bank Ltd\n\n");
	  printf("\nEnter Bank Number : \n");
 	  scanf("%d", &bank_no);


 	  if((bank_no>0)&&(bank_no<=42))
      {  fprintf(fp,"%s,%s,%s,%d,%d,%d\n",user_name,epass,customer_name,bank_no,tvalue,BAL);
         fclose(fp);
         system("cls");
         printf("\nNew Account Successfully added to record\n");
         printf("\nIf you want to continue Press [C]\n");


         choice=getch();
         if(choice=='c'||choice=='C')
			{   system("cls");
				menu();
			}



      }
      else
      printf("Invalid Bank No. \n Select between 1 TO 42\n");

}


       int menu()                                           // MENU FUNCTION
{
         system("cls");
		printf("\t\t****** CARDLESS CASH WITHDRAWAL*******\n\n \t\tWelcome To Mobile Banking Interface\n\n\n ");
		printf("\t[A] New Account \t\t [B] Login\n\n\n\t ENTER YOUR OPTION :");

		choice=getch();
		if(choice=='a'||choice=='A')
		{	system("cls");
			Register();                                     // REGISTER HERE
		}
		else if(choice=='b'||choice=='B')
		{
			system("cls");
			Login();                                        // LOGIN HERE

		}
		else
		{
			printf("\nInvalid Choice \nIf you want to continue Press [C]\n");
			choice=getch();
			if(choice=='c'||choice=='C')
			{
                system("cls");
				menu();
			}
		}

}

       void Login()                                         // LOGIN FUNCTION
{
char user_name1[50],password1[50],customer_name1[50];
int bank_no1;
char *epass2;
    FILE *fp = fopen("bankdatabase.csv", "a+");
	int flag=0;
    if (!fp) {
              printf("Can't open file\n");
              return 0;
             }

	printf("USER NAME : \t");
	scanf("%s", &user_name1);
    char buf[1024];
    int row_count = 1;
    int field_count = 0;
    while (fgets(buf, 1024, fp))
	 {
        field_count = 0;
        row_count++;
        char *fd = strtok(buf, ",");
        if(strcasecmp(user_name1,fd)==0)
        {
        printf("User Name found \n\n");
          flag+=1;
        while (fd)
		{
            if (field_count == 0)
               {

              printf("PASSWORD  : \t");
              int j; char chn;
               for(j=0;j<6;j++)
               {
                chn = getch();
                password1[j] = chn;
                chn = '*' ;
                 printf("%c",chn);
                }

               }

            if (field_count == 1)
                { epass2 = encryption(fd,2);
                  if(strcasecmp(password1,epass2)==0)
                {printf("\n\nPASSWORD verified  \n\n");
                 //strcpy(password1,epass);

                printf("CUSTOMER NAME : \t");
                scanf("%s", &customer_name1);
                }
                else
                  {printf("WRONG PASSWORD  \n\n");
                   system("cls");
                   menu();

                   }

                }
             if ((field_count == 2) && (strcasecmp(customer_name1,fd)==0))
                {   printf("CUSTOMER NAME VERIFIED \n\n");
                    system("cls");
                    printf("\n\nSELECT YOUR BANK ACCOUNT\n\n");
                    printf("\n\n1.Allahabad Bank\n2.Andhra Bank\n3.Axis Bank\n4.Bank of Bahrain and Kuwait\n5.Bank of Baroda - Corporate Banking\n6.Bank of Baroda - Retail Banking\n7.Bank of India\n8.Bank of Maharashtra\n9.Canara Bank\n10.Central Bank of India\n11.City Union Bank\n12.Corporation Bank\n13.Deutsche Bank\n14.Development Credit Bank\n15.Dhanlaxmi Bank\n16.Federal Bank\n16.Indian Bank\n17.Indian Overseas Bank\n18.IndusInd Bank\n19.ING Vysya Bank\n20.Jammu and Kashmir Bank\n21.Karnataka Bank Ltd\n22.Karur Vysya Bank\n23.Kotak Bank\n23.Laxmi Vilas Bank\n24.Oriental Bank of Commerce\n25.Punjab National Bank - Corporate Banking\n26.Punjab National Bank - Retail Banking\n27.Punjab & Sind Bank\n28.Shamrao Vitthal Co-operative Bank\n29.South Indian Bank\n30.State Bank of Bikaner & Jaipur\n31.State Bank of Hyderabad\n32.State Bank of India\n33.State Bank of Mysore\n34.State Bank of Patiala\n35.State Bank of Travancore\n36.Syndicate Bank\n37.Tamilnad Mercantile Bank Ltd.\n38.UCO Bank\n39.Union Bank of India\n40.United Bank of India\n41.Vijaya Bank\n42.Yes Bank Ltd\n\n");
                    printf("BANK NUMBER : \t");
                    scanf("%d", &bank_no1);
                }

                if ((field_count == 3) && (bank_no1 == atoi(fd)))
                    printf("Login Successfull \n\n");


            fd = strtok(NULL, ",");
            field_count++;
        }

        }
       else
        {
            continue;

        }
        }
        if(flag==0)
 	{
	printf("\n User not found\n\n");

	menu();
	}
        fclose(fp);
        Transaction(user_name1,password1,customer_name1,bank_no1);
 }

       void Transaction(char user_name1[],char password1[],char customer_name1[],int bank_no1)
{    system("cls");
    printf("\t\t****** CARDLESS CASH WITHDRAWAL*******\n\n \t\tWelcome To Mobile Banking Interface\n\n\n ");
		printf("\t[A] WITHDRAWAL \t\t [B] BALANCE ENQUIRY\n\n\n\t ENTER YOUR OPTION :");

		choice=getch();
		if(choice=='a'||choice=='A')
		{	system("cls");
			Withdraw(user_name1,password1,customer_name1,bank_no1);
		}
		else if(choice=='b'||choice=='B')
		{
			system("cls");
			ebal(user_name1,password1,customer_name1,bank_no1);

		}
		else
		{
			printf("\nInvalid Choice \nIf you want to continue Press [C]\n");
			choice=getch();
			if(choice=='c'||choice=='C')
			{
                system("cls");
				Transaction(user_name1,password1,customer_name1,bank_no1);
			}

        }
}

int Withdraw(char user_name1[],char password1[],char customer_name1[],int bank_no1)
{   int draw_amt;

int balance,tvalue,z;
    tvalue = etval(user_name1,password1,customer_name1,bank_no1);
    balance = ebal(user_name1,password1,customer_name1,bank_no1);
    system("cls");

               FILE *fop = fopen("bankdatabase.csv", "a+");
                printf("\nEnter amount to withdraw\n");
                  scanf("%d",&draw_amt);
                  system("cls");
                  if (balance >= draw_amt)
                  {z = rand();
                   //printf("\n This OTP is to be used at ATM machine to withdraw cash.....\n\n");
                  }
                  else
                    menu();
                  if(z>0)
                  balance = balance - draw_amt;
                  tvalue++;
                  system("cls");
                  printf("TRANSACTION SUCCESSFULL\n");
                  printf("Current BAL : %d\n\n",balance);
                  //printf("TVALUE IS : %d",tvalue);

                  fprintf(fop,"%s,%s,%s,%d,%d,%d\n",user_name1,epass,customer_name1,bank_no1,tvalue,balance);
                  fclose(fop);

 }

int etval(char user_name1[],char password1[],char customer_name1[],int bank_no1)
{
int balance,tvalue,z;
    system("cls");

FILE *fp = fopen("bankdatabase.csv", "a+");


	int flag=0;
    if(!fp)
        {
              printf("Can't open file\n");
              return 0;
             }
    char buf[1024];
    int row_count = 1;
    int field_count = 0;
    while (fgets(buf, 1024, fp))
	 {
        field_count = 0;
        row_count++;



        char *field = strtok(buf, ",");
        if(strcasecmp(user_name1,field)==0)
        {

        while (field)
		{
               if (field_count == 0)
               {

               }

               if ((field_count == 1) && (strcasecmp(password1,field)==0))
               {

               }
               if ((field_count == 2) && (strcasecmp(customer_name1,field)==0))
               {

               }
               if ((field_count == 3) && (bank_no1 == atoi(field)))
               {

               }
               if (field_count == 4)
               { tvalue= atoi(field);

               }
               if(field_count==5)
               {
			   balance = atoi(field);

                }
                field = strtok(NULL, ",");
                field_count++;

        }

        }
        else
        {
            continue;

        }
        }
        fclose(fp);
        //printf("%d",tvalue);
        return tvalue;
}
int ebal(char user_name1[],char password1[],char customer_name1[],int bank_no1)
{
int balance,tvalue,z;
    system("cls");

FILE *fp = fopen("bankdatabase.csv", "a+");


	int flag=0;
    if(!fp)
        {
              printf("Can't open file\n");
              return 0;
             }
    char buf[1024];
    int row_count = 1;
    int field_count = 0;
    while (fgets(buf, 1024, fp))
	 {
        field_count = 0;
        row_count++;

        char *field = strtok(buf, ",");
        if(strcasecmp(user_name1,field)==0)
        {

        while (field)
		{
               if (field_count == 0)
               {


               }

               if ((field_count == 1) && (strcasecmp(password1,field)==0))
               {


               }
               if ((field_count == 2) && (strcasecmp(customer_name1,field)==0))
               {

               }
               if ((field_count == 3) && (bank_no1 == atoi(field)))
               {

               }
               if (field_count == 4)
               { tvalue= atoi(field);

               }
               if(field_count==5)
               {

			   balance = atoi(field);

                }
                field = strtok(NULL, ",");
                field_count++;

        }

        }
        else
        {
            continue;

        }
        }
        fclose(fp);
        printf("YOUR CURRENT BALANCE IS : %d\n",balance);
        return balance;
}

