//Deposit Module --> moduel for depositing amount into an account (anyone can deposit to anyones account)

//inclduing header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Manager.h"
#include "Menu.h"
#include "Utilities.h"
#include "Login.h"
#include "Deposit.h"

//Defining functin of Deposit Module
int Deposit(){
    long int depositAccount;
    float depositAmount;
 printf("Enter Account Number to Deposit : ");
 scanf("%ld",&depositAccount);
  printf("Enter the Amount to Deposit (in Rs ,without comma) : ");
 scanf("%f",&depositAmount);
 UpdateAmountInAccount(depositAccount,depositAmount,1);
 
    return 0;
}

int UpdateAmountInAccount(long int depositAccount,float depositAmount,int if_D_W){
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

        while(seekAccount!=depositAccount){
            fseek(fp,0,SEEK_SET);
            for(int i=0;i<recordOnLine;i++){
                 fgets(line,sizeof(line),fp);
                 
            }
            recordOnLine+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
       if(seekAccount==depositAccount){
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

//deposit added
depositFetch+=depositAmount;//deposit performed

    
    int passLines=recordOnLine-1; //lines topass before our desire record

    //rewriting records modifying Balance in account records
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
            if (if_D_W==1){
              fprintf(fp,"%ld-%s-%s-%s-%ld-%ld-%.2f\n",accountNoFetch,passwordFetch,nameFetch,addressFetch,aadharNoFetch,mobileNoFetch,depositFetch);
   
            continue;
        }
        }
        else{
        fprintf(fp,"%s",linesToWrite[i]);
        }

}
fclose(fp);
return 0;
}