//Manager module --> to login and approve or decline applications for creation or deletion of accounts
//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Manager.h"
#include "Menu.h"
#include "Utilities.h"
#include "Login.h"
#include "Deposit.h"

//defining functions of Manager Module

//for moving record into login data files so user can login now
int IfApprovedMove(int passLines,int ifApprove){//passlines means lines to pass before our record arrives (=recordOnLine-1)
    //fetching and deleting record that is approved and to be moved to login records of registerd users
    char line[256];
    char *file="Registrations.txt";
    

    //deleting this record from previous registration file
    int totalLines=readLines(file,0);
    FILE *fp=fopen(file,"r");
    fseek(fp,0,SEEK_SET);
    char linesToWrite[totalLines-1][256];
    for(int i=0;i<totalLines;i++){
        fgets(linesToWrite[i],sizeof(line),fp);
          
    }
    fclose(fp);
    
      
  //rewriting records excluding approved records
    fp=fopen(file,"w");
    fseek(fp,0,SEEK_SET);
    for(int i=0;i<totalLines;i++){
        if (i==passLines){
            if (ifApprove==1){
              FILE *loginfp=fopen("Logins.txt","a");
              fprintf(loginfp,"%s",linesToWrite[i]);
              fclose(loginfp);
            }
            continue;
        }
        else{
        fprintf(fp,"%s",linesToWrite[i]);
        }
    }
    fclose(fp);
   return totalLines;
}

//function for removing record from both DeRegistartions and login file

int IfApprovedRemove(int passLinesLogins,int passLinesDeRegistrations,int ifApprove){//passlines means lines to pass before our record arrives (=recordOnLine-1)
    //fetching and deleting record that is approved and to be removed from login records of registerd users
    char line[256];
    char *file="logins.txt";
    

    //deleting this record from previous logins file
    int totalLines=readLines(file,0);
    FILE *fp=fopen(file,"r");
    fseek(fp,0,SEEK_SET);
    char linesToWrite[totalLines-1][256];
    for(int i=0;i<totalLines;i++){
        fgets(linesToWrite[i],sizeof(line),fp);
          
    }
    fclose(fp);
    
      
  //rewriting records excluding approved records into login files
    fp=fopen(file,"w");
    fseek(fp,0,SEEK_SET);
    for(int i=0;i<totalLines;i++){
        if (i==passLinesLogins && ifApprove==1){
            printf("Account Deleted !!! \n");
            continue;
        }
        else{
        fprintf(fp,"%s",linesToWrite[i]);
        }
    }
    fclose(fp);


    //deleting application from DeRegistrations file

    file="DeRegistrations.txt";

    totalLines=readLines(file,0);
    fp=fopen(file,"r");
    fseek(fp,0,SEEK_SET);
    char linesToWriteDeRegistrations[totalLines-1][256];
    for(int i=0;i<totalLines;i++){
        fgets(linesToWriteDeRegistrations[i],sizeof(line),fp);
          
    }
    fclose(fp);
     
     fp=fopen(file,"w");
    fseek(fp,0,SEEK_SET);
    for(int i=0;i<totalLines;i++){
        if (i==passLinesDeRegistrations ){
            continue;
        }
        else{
        fprintf(fp,"%s",linesToWriteDeRegistrations[i]);
        }
    }
    fclose(fp);
    
   return totalLines;
}


//reviewing for account creation application
int ReviewAccountCreation(){
    char *file="Registrations.txt";
    int lines=readLines(file,0);
    if (lines==-1){
        printf("No Application Pending !!!\n");
    }
    else if (lines>0){
        printf("Choose which Application to review :\n");
        readLines(file,1);
        long int  approveAccountCreation;
        printf("\nEnter Account Number :");
        scanf("%ld",&approveAccountCreation);

        //verifying if account exists
      if(IfAccountExists("Registrations.txt",approveAccountCreation)==1) { 
        char line[256];
        FILE *fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        int pass;

        do{
            pass=0;
            long int seekAccount;
            int recordOnLine=0; //it denotes lines on which our record is present 
            fscanf(fp,"%ld",&seekAccount);
        while(seekAccount!=approveAccountCreation){
            fseek(fp,0,SEEK_SET);
            for(int i=-1;i<recordOnLine;i++){
                 fgets(line,sizeof(line),fp);
            }
            recordOnLine+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
        
        fclose(fp);
        if (seekAccount==approveAccountCreation){
            printf("Review for this account\n");
            printf("[1]-Approve Application\n");
            printf("[2]-Decline Application\n");
            printf("[0]-Go Back\n");
            int reviewAccount;
            ClearInputBuffer();
            printf("Enter Choice :");
            scanf("%d",&reviewAccount);
            switch (reviewAccount){
               case 1:
               //function to transfer that line to login files
               IfApprovedMove(recordOnLine,1); //1 --> to write to logins
               printf("You have Approved this Account Creation !!!\n");
               
               break;
               case 2:
               //function to delete this line 
               IfApprovedMove(recordOnLine,0); //0 --> to not write it in logins
               printf("You have Declined this Account Creation !!!\n");
               break;
               case 0:
               Manager();
               break;
               default:
               printf("Invalid Choice !! Choose Again\n");
               pass=1;
               
            }
        }
        }while(pass);

    }
    else {
        printf("No Appliication for these account credentials !!");
        
    }
    }
    else{
        printf("Some Error Occured !! Try after some time\n");
    }
    return 0;
}

//for reviewing account closing application
int ReviewAccountDeletion(){
    char *file="DeRegistrations.txt";
    int lines=readLines(file,0);
    if (lines==-1){
        printf("No Application Pending !!!\n");
    }
    else if (lines>0){
        printf("Choose which Application to review :\n");
        readLines(file,1);
        long int  approveAccountDeletion;
        printf("\nEnter Account Number :");
        scanf("%ld",&approveAccountDeletion);

        if(IfAccountExists("DeRegistrations.txt",approveAccountDeletion)){
        char line[256];
        
         //for finding recordline in DeRegistrations file
        file="DeRegistrations.txt";//now we are searching in logins for our desired record
        FILE *fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        long int seekAccount;
        int recordOnLineDeRegistrations=0; //it denotes lines on which our record is present 
        fscanf(fp,"%ld",&seekAccount);
    while(seekAccount!=approveAccountDeletion){
        fseek(fp,0,SEEK_SET);
        for(int i=-1;i<recordOnLineDeRegistrations;i++){
                fgets(line,sizeof(line),fp);
        }
        recordOnLineDeRegistrations+=1;
        fscanf(fp,"%ld",&seekAccount);
    }
    
    fclose(fp);


        //for finding recordline in logins
        file="logins.txt";//now we are searching in logins for our desired record
        fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        int pass;

        do{
            pass=0;
            long int seekAccount;
            int recordOnLineLogins=0; //it denotes lines on which our record is present 
            fscanf(fp,"%ld",&seekAccount);
        while(seekAccount!=approveAccountDeletion){
            fseek(fp,0,SEEK_SET);
            for(int i=-1;i<recordOnLineLogins;i++){
                 fgets(line,sizeof(line),fp);
            }
            recordOnLineLogins+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
        
        fclose(fp);


        //if got the account then proceed for approve or deny
        if (seekAccount==approveAccountDeletion){
            printf("Review for this account\n");
            printf("[1]-Approve Application\n");
            printf("[2]-Decline Application\n");
            printf("[0]-Go Back\n");
            int reviewAccount;
            ClearInputBuffer();
            printf("Enter Choice :");
            scanf("%d",&reviewAccount);
            switch (reviewAccount){
               case 1:
               //function to remove record from login files
               IfApprovedRemove(recordOnLineLogins,recordOnLineDeRegistrations,1); //1 --> to remove record from logins
               printf("You have Approved this Account deletion !!!\n");
               break;
               case 2:
               //function to delete this line 
               IfApprovedRemove(recordOnLineLogins,recordOnLineDeRegistrations,0); //0 --> to not remove from logins
               printf("You have Declined this Account deletion !!!\n");
               break;
               case 0:
               Manager();
               break;
               default:
               printf("Invalid Choice !! Choose Again\n");
               pass=1;
               
            }
        }
        }while(pass);

         }
       else {
        printf("No Appliication for these account credentials !!");
      }
        
    }

    else{
        printf("Some Error Occured !! Try after some time\n");
    }
    return 0;
}


//driver manager function for manager module
void Manager(){
    //initialising manager credentails for  manager login
    char managerPass[]="Manager@Bank";
    char password[20];
    ClearInputBuffer();
    printf("\n\nLooging in as Manager\n");
    printf("Enetr the Password :");
    scanf("%s",password);
    

    //granting access if password is correct 
    int managerChoice;
    if (strcmp(password,managerPass)==0){
        printf("You have logged in as Manager\n");
        printf("Choose from below options :\n");
        printf("[1]-Approve Account Creation\n");
        printf("[2]-Approve Account Deletion\n");
        printf("[0]-Go Back\n");
        printf("Enter Your Choice : ");
        scanf("%d",&managerChoice);

        switch (managerChoice){
            case 1:
            printf("You have Choosen to Approve Account Creation \n");
            ReviewAccountCreation();
            break;
            case 2:
            printf("You have Choosen to Approve Account Deletion \n");
            ReviewAccountDeletion();
            break;
            case 0:
            printf("You have Choosen to Go Back \n");
            Menu();
            break;
            default:
            Manager();
        }
    } 
    else{
        printf("You have entered Wrong Password\n");
        Menu();
    }
}