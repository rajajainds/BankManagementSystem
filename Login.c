//Login Module --> for users to login to your account and manage it or withdraw

//inclduing header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Utilities.h"
#include "Login.h"
#include "Deposit.h"

//defining function of Login Module

int LoginMenu(){
    int choice;
    double amountD_W;
    printf("**You can Choose from below options to continue**\n");
    printf("[1]-Deposit\n");
    printf("[2]-Withdraw\n");
    printf("[3]-Apply to update Details\n");
    printf("[4]-Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice){
     case 1:
     printf("You have selected to deposit--\n");
     printf("Enter Deposit Amount :");
     scanf("%f",&amountD_W);
     //function to deposit amount 
     break;
     case 2:
     printf("You have selected to Withdraw--\n");
     printf("Enter Withdraw Amount :");
     scanf("%f",&amountD_W);
     //function to withdraw amount
     case 3:
     printf("You have selected to Update Details\n");
     int updateChoice;
     printf("Choose from below what to update--\n");
     //create here the function and menu of updating  details
     //to be done after deposit and withdraw feature
     

    }
    return choice;
}

//function for logging in and fetching details
int VerifyLogin(long int accountNo){
    char *file="logins.txt";
    FILE *fp;
    //global variables
    long int seekAccount;
    int recordOnLine; 
    char line[256];
    int lines=readLines(file,0);
    
    if (lines==-1){
        printf("No Account Found with these Credentials !!!\n");
    }
    else if (lines>0){
        
        fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        int pass;
        
        do{
            pass=1;
            recordOnLine=1; //it denotes lines on which our record is present 
            fscanf(fp,"%ld",&seekAccount);
        while(seekAccount!=accountNo){
            fseek(fp,0,SEEK_SET);
            for(int i=0;i<recordOnLine;i++){
                 fgets(line,sizeof(line),fp);
            }
            recordOnLine+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
       if(seekAccount==accountNo){
               pass=0;
               
            }
        }while(pass);
        
    }
    else{
        printf("Some Error Occured !! Try after some time\n");
    }
    fclose(fp);
    
   //fetching details of the account and verifying password
   fp=fopen(file,"r");
   fseek(fp,0,SEEK_SET);
   for(int i=1;i<recordOnLine;i++){ //stop before the desired record
                 fgets(line,sizeof(line),fp);
        }

    //temporary variables for fetching account details
    char nameFetch[30],addressFetch[40],passwordFetch[20];
    long int mobileNoFetch,aadharNoFetch,accountNoFetch;
    float depositFetch;
    
    fgets(line,sizeof(line),fp);
    fclose(fp);
     //parsing string into orginal data types

    const char * separator="-";
   int i=0;
   char arraysPasred[7][40];
   char * token=strtok(line,separator);
   strcpy(arraysPasred[0],token);
   token=strtok(NULL,separator);
   strcpy(arraysPasred[1],token);
     token=strtok(NULL,separator);
   strcpy(arraysPasred[2],token);
     token=strtok(NULL,separator);
   strcpy(arraysPasred[3],token);
     token=strtok(NULL,separator);
   strcpy(arraysPasred[4],token);
     token=strtok(NULL,separator);
   strcpy(arraysPasred[5],token);
     token=strtok(NULL,separator);
   strcpy(arraysPasred[6],token);

  // assigning arrays into original data types
accountNoFetch=atol(arraysPasred[0]);
strcpy(passwordFetch,arraysPasred[1]);
strcpy(nameFetch,arraysPasred[2]);
strcpy(addressFetch,arraysPasred[3]);
aadharNoFetch=atol(arraysPasred[4]);
mobileNoFetch=atol(arraysPasred[5]);
depositFetch=atof(arraysPasred[6]);

    
    char password[20];//input password if account matches 
    if (seekAccount==accountNo){
    ClearInputBuffer();
    printf("Enter your Password :");
    scanf("%s",password);
    if (strcmp(password,passwordFetch)==0){
        printf("You are logged in !!\n");
        printf("Below are Your Details--\n");
        printf("Name : %s\n",nameFetch);
        printf("Account Number : %ld\n",accountNoFetch);
        printf("Aadhar Number : %ld\n\n",aadharNoFetch);
        printf("***Your Current Balance : %.2f\n\n",depositFetch);

        //loginMenu function
    }else {
        printf( "you can't login !! Wrong Password !!\n");
    }
    }
    else{
       printf("No Account Found with these Credentials !!!\n");
    }

    return 0;

}



//main driver function of this module
int Login(){

long int accountNo;

//input credentials of user to verify and approve login
printf("Use your credentails to Login to your Account \n");
printf("Enter your Account No. :");
scanf("%ld",&accountNo);

//verifyig credentails and password ,details fetching 
VerifyLogin(accountNo);

return 0;
}