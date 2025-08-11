//Utilities module --> for some helping function for the system

//including header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Utilities.h"
#include<string.h>

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

//function to read line by line from text file
int readLines(char *file,int ifPrint){
   FILE *fp=fopen(file,"r");
    char line[256];
    int lines=0;
    if (fp == NULL) {
        return -1;
    }
     
    while (fgets(line, sizeof(line), fp)) {
      if (strlen(line)>0){
         lines+=1;//counts total lines
         if (ifPrint==1){
         printf("%s", line); // Print each line if needed
         } 

        }
      }
      
    fclose(fp);

  return lines;
}


int IfAccountExists(char *file,long int accountNo){

    FILE *fp=fopen(file,"r");
        fseek(fp,0,SEEK_SET);
        int pass;
        int recordOnLine;
        long int seekAccount;
        char line[256];
        do{
            pass=1;
            recordOnLine=1; //it denotes lines on which our record is present 
            fscanf(fp,"%ld",&seekAccount);

         while(seekAccount!=accountNo){
            fseek(fp,0,SEEK_SET);
            for(int i=0;i<recordOnLine;i++){
                if(fgets(line,sizeof(line),fp)){
                  
                }
                else{
                  goto outsideLoop;
                }
                 
            }
            recordOnLine+=1;
            fscanf(fp,"%ld",&seekAccount);
        }
        outsideLoop:
       if(seekAccount==accountNo){
               pass=0;
               return 1;
               
            }
            else{
              return 0;
            }
        }while(pass);

}
