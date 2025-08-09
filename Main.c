//main.c file of Bank Managemnt System
//includng header files
#include<stdio.h>
#include<stdlib.h>
#include "Menu.h"
#include "Utilities.h"
#include "Register.h"
#include "Manager.h"


//main driver functoin of the system
int main(){
printf("*****-----Bank Management System-----*****\n\n");
int choice=Menu();

    return 0;//returning success code
}