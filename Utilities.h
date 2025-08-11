//Utilities.h -->header file of Utilities module
#ifndef UTILITIES_H
#define UTILITIES_H

//declaring methods of Utilities modules
void ClearInputBuffer();

int RandomNumber(int lower,int upper);

int readLines(char *file,int ifPrint);

int IfAccountExists(char *file,long int accountNo);
#endif