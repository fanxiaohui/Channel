# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

void noMoreNewLine(char * theString){
    char * isANewLine ;
    isANewLine = strrchr(theString,'\n');// first Occurance of 
    if(isANewLine){
        *isANewLine = '\0';
    }
}

void makeLowerCase(char *theString){
    int i=0;
    while(theString[i]){
        theString[i] = tolower(theString[i]);
        i++;
    }
}

int main(){
 char doYouWantToQuit[10];

 
//  noMoreNewLine(doYouWantToQuit);


//  makeLowerCase(doYouWantToQuit);
//  strcpy(doYouWantToQuit,"quit");
//  printf(doYouWantToQuit);
//  int compResult = strcmp(doYouWantToQuit,"quit");
//  printf("the compare result is %d \n\n",compResult);
//  printf("thank you\n");

// 只有用户输入了quit才允许退出。

while(strcmp(doYouWantToQuit,"quit")){
    printf("Enter quit to quit:\n");
    fgets(doYouWantToQuit,10,stdin);
    noMoreNewLine(doYouWantToQuit);
    makeLowerCase(doYouWantToQuit); 
}
printf("Thandk you for typing %s \n\n",doYouWantToQuit);
 
}