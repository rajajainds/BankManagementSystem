//Deposit.h --> header file for Deposit module 
#ifndef DEPOSIT_H
#define DEPOSIT_H

//Delaring functions of Deposit Module 
int Deposit();//main driver function of Deposit module 

int UpdateDepositAmount(long int depositAccount,float depositAmount,int if_D_W); //updating amount by  Deposit(without login) and withdraw (with login )
#endif
