//Manager module --> to login and approve or decline applications for creation or deletion of accounts
//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Manager.h"
#include "Menu.h"
#include "Utilities.h"

//defining functions of Manager Module
int reviewAccountCreation(){
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
        char line[256];
        FILE *fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        int pass;

        do{
            pass=0;
            long int seekAccount;
            int passLine=0;
            fscanf(fp,"%ld",&seekAccount);
        while(seekAccount!=approveAccountCreation){
            passLine+=1;
            fseek(fp,0,SEEK_SET);
            for(int i=0;i<passLine;i++){
                 fgets(line,sizeof(line),fp);
            }
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
               printf("You have Approved this Account Creation !!!\n");
               break;
               case 2:
               //function to delete this line 
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
    else{
        printf("Some Error Occured !! Try after some time\n");
    }
    return 0;
}

    
    

   

void Manager(){
    //initialising manager credentails for  manager login
    char managerPass[]="Manager@Bank";
    char password[20];
    ClearInputBuffer();
    printf("\n\nLooging in as Manager\n");
    printf("Enetr the Password :");
    fgets(password,sizeof(password),stdin);
    

    //granting access if password is correct 
    int managerChoice;
    if (strcmp(password,managerPass)){
        printf("You have logged in as Manager\n");
        printf("Choose from below options :\n");
        printf("[1]-Approve Account Creation\n");
        printf("[2]-Approve Account Delation\n");
        printf("[3]-Update Accounts Details\n");
        printf("[4]-Update Accounts balance\n");
        printf("[0]-Go Back\n");
        printf("Enter Your Choice : ");
        scanf("%d",&managerChoice);

        switch (managerChoice){
            case 1:
            printf("You have Choosen to Approve Account Creation \n");
            reviewAccountCreation();
            break;
            case 2:
            printf("You have Choosen to Approve Account Delation \n");
            break;
            case 3:
            printf("You have Choosen to Update Account Details \n");
            break;
            case 4:
            printf("You have Choosen to Update Account Balance \n");
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