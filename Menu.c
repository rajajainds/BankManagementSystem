//Menu module for displaying menu of system to choose operation 
//including header files
#include<stdio.h>
#include<stdlib.h>
#include "Menu.h"
#include "Utilities.h"
#include "Register.h"
#include "Manager.h"
#include "Login.h"

//function to display menu options and get choosen input 
int Menu(){
    int menuChoice;
    int pass;
    do{
    pass=0;//false logic
    printf("[1]-->Deposit\n");
    printf("[2]-->Withdraw\n");
    printf("[3]-->Existing User(Login)\n");
    printf("[4]-->New User(Regsiter)\n");
    printf("[0]-->Exit\n");
    printf("Enter Your Choice : ");
    scanf("%d",&menuChoice);//input of menu item that is choosed 

    
    //function as per the choosen menu item
    switch (menuChoice){
        case 1:
        printf("You have choosen Deposit\n");
        break;
        case 2:
        printf("You have choosen Withdraw\n");
        break;
        case 3:
        printf("You have choosen to Login\n");
        Login();
        break;
        case 4:
        printf("You have choosen to Register\n");
        Register();
        Menu();
        break;
        case 0:
        printf("You have choosen Exit\n");
        exit(0);
        break;
        case -1:
        printf("You have choosen secret option to login as Manager\n");
        Manager();
        break;
        default:
        printf("Inavlid Choice!!! Choose again !!!\n");  
        pass=1;//true logic
        ClearInputBuffer();//clearing input buffer so that no ambiguity occur
        
    }}while(pass);

 return menuChoice;
}


