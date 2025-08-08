//Login Module --> for users to login to your account and manage it or withdraw

//inclduing header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Manager.h"
#include "Menu.h"
#include "Utilities.h"
#include "Login.h"

//defining function of Login Module


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
    fscanf(fp,"%ld-%s-%s-%s-%ld-%ld-%.2f\n",&accountNoFetch,passwordFetch,nameFetch,addressFetch,&aadharNoFetch,&mobileNoFetch,&depositFetch);
    fclose(fp);
     printf("Till here");//temporary
    char password[20];//input password if account matches 
    if (seekAccount==accountNo){
    printf("Enter your Password :");
    scanf("%s",&password);
    if (strcmp(password,passwordFetch)){
        printf("You are logged in !!\n");
        printf("Below are Your Details--\n");
        printf("Name : %s\n",nameFetch);
        printf("Account Number : %ld\n",accountNoFetch);
        printf("Aadhar Number : %ld\n\n"aadharNoFetch);
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