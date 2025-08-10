//Login.h --> header file of Login module
#ifndef LOGIN_H
#define LOGIN_H

//declaring function fof Login Module 
int Login();//driver function of this module
int LoginMenu(long int accountNoFetch);//menu to choose operations to do after successfull login
int VerifyLogin(long int accountNo);
int UpdateDetails(long int accountNo);//for updating Account Details 
int DeRegister(long int accountNoFetch);//for applying for closing account
#endif