//Manager.h -->header file for Manager module
#ifndef MANAGAER_H
#define MANAGAER_H


//declaring methods of Manager module
int ReviewAccountCreation();
int IfApprovedMove(int passLine,int ifApprove);
int ReviewAccountDeletion();
int IfApprovedRemove(int passLinesLogins,int passLinesDeRegistrations,int ifApprove);
void Manager();
#endif