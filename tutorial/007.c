# include <stdio.h>
# include <stdlib.h>

int main(){

    printf("\n");
    int primeNums[3] = {2,3,5}; //可以这样声明数组

    int morePrimes[] = {13,17,19}; //这样声明数组也行

    char wholeNam[12] = "Derek Banas";

    char city[7] = {'C','h','i'};

    char thirdCity[] = "Paris";

    char yourCity[30];

    printf("The city you live in \n");

    fgets(yourCity,30,stdin);


    for(int i =0 ; i< 30 ;i++){
        if (yourCity[i] == '\n'){
            yourCity[i] = '\0';
            break;
        }
        printf(" %s \n ",yourCity[i]);
    }
    // printf("Hello %s \n\n",yourCity);
    

    exit(0);


}