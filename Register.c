//Register module --> module for registration of new user's account  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "Utilities.h"
#include "Register.h"



//register function to get the details and store in datafiles
int Register(){
    //declaring variables 
    char name[30],address[40],password[20];
    long int mobileNo,aadharNo,accountNo;
    float initialDeposit;
    

     
    //get input details
    printf("Enter Account Holder's Name : ");
    ClearInputBuffer();
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    printf("Enter your Password for Your Account : ");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password,"\n")]='\0';
    printf("Enter Account Holder's Address : ");
    fgets(address,sizeof(address),stdin);
    address[strcspn(address,"\n")]='\0';
    printf("Enter Account Holder's Aadhar Number : ");
    scanf("%ld",&aadharNo);
    printf("Enter Account Holder's Mobile Number : ");
    scanf("%ld",&mobileNo);
    printf("Enter Initial Deposit Amount (in Rs,enter without comma) : ");
    scanf("%f",&initialDeposit);
    printf("Application Submitted !!! Wait for Review\n");
    
    
    accountNo=RandomNumber(12345678,87654321);
    printf("You account NUmber is : %ld\n",accountNo);
    //writing account details into data files
    char file[]="Registrations.txt";
    FILE *fp=fopen(file,"a+");
    fseek(fp,0,SEEK_END);
    fprintf(fp,"%ld-%s-%s-%s-%ld-%ld-%.2f\n",accountNo,password,name,address,aadharNo,mobileNo,initialDeposit);
    fclose(fp);
  
    
return 0;
}