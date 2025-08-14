//Login Module --> for users to login to your account and manage it or withdraw

//inclduing header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Utilities.h"
#include "Login.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Menu.h"
//defining function of Login Module

int DeRegister(long int accountNoFetch){
    char fetchStatement[21];
    char realStatement[21]="YES CLOSE MY ACCOUNT";
     printf("Please write this below without brackets (YES CLOSE MY ACCOUNT) --\n");
     printf("Confirm Your Account Closing :");
     fgets(fetchStatement,sizeof(fetchStatement),stdin);
     fetchStatement[strcspn(fetchStatement,"\n")]='\0';
     if (strcmp(realStatement,fetchStatement)==0){
        //finding account detals to write to DeRegistrations,txt
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

        while(seekAccount!=accountNoFetch){
            fseek(fp,0,SEEK_SET);
            for(int i=0;i<recordOnLine;i++){
                 fgets(line,sizeof(line),fp);
                 
            }
            recordOnLine+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
       if(seekAccount==accountNoFetch){
               pass=0;
               
            }
        }while(pass);
        
    }
    else{
       printf("No Account Found with these Credentials !!!\n");
       
    }
    fclose(fp);
   //fetching details of the account and verifying password
   fp=fopen(file,"r");
   fseek(fp,0,SEEK_SET);
   for(int i=1;i<recordOnLine;i++){ //stop before the desired record
                 fgets(line,sizeof(line),fp);
        }

   
    fgets(line,sizeof(line),fp);
    fclose(fp);
    
    //writing it in new Deresgiatrations.txt
    fp=fopen("DeRegistrations.txt","a+");
    fprintf(fp,line);
    fclose(fp);
       
    printf("Applied for Account Closing!! Wait for Review\n");
     }
     else {
      printf("You Entered wrong Phrase!! Acount Closing Failed!!!\n");
     }

}


int LoginMenu(long int accountNoFetch){
    int choice;
    printf("**You can Choose from below options to continue**\n");
    printf("[1]-Deposit\n");
    printf("[2]-Withdraw\n");
    printf("[3]-Apply to update Details\n");
    printf("[4]-Apply to close Account\n");
    printf("[0]-Go Back\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice){
     case 1:
     printf("You have selected to deposit--\n");
     //function to deposit amount 
     Deposit();
     break;

     case 2:
     printf("You have selected to Withdraw--\n");
     //function to withdraw amount
     Withdraw();
     break;

     case 3:
     printf("You have selected to Update Details\n");
     // function and menu of updating  details
     UpdateDetails(accountNoFetch);
     break;
    
     case 4:
     printf("You have selected to Close Account\n");
     ClearInputBuffer();
     //function to apply for closing account
     DeRegister(accountNoFetch);
     break;

     case 0:
     Menu();
     break;

     default:
     printf("Wrong Choice !!Choose Again !!\n");
     break;

    }
    ClearInputBuffer();
    LoginMenu(accountNoFetch);
    return choice;
}


//function for updating details
int UpdateDetails(long int accountNo){

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
       printf("No Account Found with these Credentials !!!\n");
       
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


//updating Account Details

    inputUpdatedDetails:
     int updateChoice;
     printf("Choose from below what to update--\n");
     printf("[1]-Account Holder's Name\n");
     printf("[2]-Account Holder's Address\n");
     printf("[3]-Account Holder's Mobile Number\n");
     printf("[4]-Account's Login Password\n");
     printf("[0]-Go Back\n");
     printf("Enter Your Choice : ");
     scanf("%d",&updateChoice);
     switch (updateChoice){
        //get updated input details
    case 1:
    ClearInputBuffer();
    printf("Current Account Holder's Name is : %s\n",nameFetch);
    printf("Change Name to : ");
    ClearInputBuffer();
    fgets(nameFetch,sizeof(nameFetch),stdin);
    nameFetch[strcspn(nameFetch,"\n")]='\0';
    break;

    case 4:
    ClearInputBuffer();
    printf("Current Account Holder's Password is : %s\n",passwordFetch);
    printf("Change Password for Your Account to : ");
    fgets(passwordFetch,sizeof(passwordFetch),stdin);
    passwordFetch[strcspn(passwordFetch,"\n")]='\0';
    break;

    case 2:
    ClearInputBuffer();
    printf("Current Account Holder's Address is : %s\n",addressFetch);
    printf("Change Address to : ");
    fgets(addressFetch,sizeof(addressFetch),stdin);
    addressFetch[strcspn(addressFetch,"\n")]='\0';
    break;

    case 3:
    ClearInputBuffer();
    printf("Current Account Holder's Mobile Number is : %ld\n",mobileNoFetch);
    printf("Change Mobile Number to : ");
    scanf("%ld",&mobileNoFetch);
    break;

    case 0:
    LoginMenu(accountNoFetch);
    break;

    default:
    printf("Invalid Choice !! Choose Again !!\n");
    goto inputUpdatedDetails;
    break;

   }

    
    int passLines=recordOnLine-1; //lines topass before our desire record

    //rewriting records modifying Details in account records
     int totalLines=readLines(file,0);
    fp=fopen(file,"r");
    fseek(fp,0,SEEK_SET);
    char linesToWrite[totalLines-1][256];
    for(int i=0;i<totalLines;i++){
        fgets(linesToWrite[i],sizeof(line),fp);
          
    }
    fclose(fp);
    fp=fopen(file,"w");
    fseek(fp,0,SEEK_SET);
    for(int i=0;i<totalLines;i++){
        if (i==passLines){   
              fprintf(fp,"%ld-%s-%s-%s-%ld-%ld-%.2f\n",accountNoFetch,passwordFetch,nameFetch,addressFetch,aadharNoFetch,mobileNoFetch,depositFetch);
              continue;
        
        }
        else{
        fprintf(fp,"%s",linesToWrite[i]);
        }

}
fclose(fp);
printf("Details Updated !!!\n");
LoginMenu(accountNoFetch);
return 0;
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
        LoginMenu(accountNo);
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
  
   char arraysParsed[7][40];
   char * token=strtok(line,separator);
   strcpy(arraysParsed[0],token);
   token=strtok(NULL,separator);
   strcpy(arraysParsed[1],token);
     token=strtok(NULL,separator);
   strcpy(arraysParsed[2],token);
     token=strtok(NULL,separator);
   strcpy(arraysParsed[3],token);
     token=strtok(NULL,separator);
   strcpy(arraysParsed[4],token);
     token=strtok(NULL,separator);
   strcpy(arraysParsed[5],token);
     token=strtok(NULL,separator);
   strcpy(arraysParsed[6],token);

  // assigning arrays into original data types
accountNoFetch=atol(arraysParsed[0]);
strcpy(passwordFetch,arraysParsed[1]);
strcpy(nameFetch,arraysParsed[2]);
strcpy(addressFetch,arraysParsed[3]);
aadharNoFetch=atol(arraysParsed[4]);
mobileNoFetch=atol(arraysParsed[5]);
depositFetch=atof(arraysParsed[6]);

    
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

        LoginMenu(accountNoFetch);
    }else {
        printf( "you can't login !! Wrong Password !!\n");
        VerifyLogin(accountNo);
    }
    }
    else{
       printf("No Account Found with these Credentials !!!\n");
       Menu();
    }


    }
    else{
        printf("Some Error Occured !! Try after some time\n");
        Menu();
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
if (IfAccountExists("Logins.txt",accountNo)==1){
VerifyLogin(accountNo);
}
else{
    printf("No Account Exists with these credentials !!!\n");
    Menu();
}
return 0;
}