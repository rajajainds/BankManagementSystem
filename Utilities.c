//Utilities module --> for some helping function for the system

//including header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Utilities.h"


//function for clearing scanf input garbage buffers
void ClearInputBuffer(){
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);

}


//function for generating random number between upper an dlower --> to create account number
int RandomNumber(int lower,int upper){
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}