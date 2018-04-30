# include <stdio.h>
# include <stdlib.h>

int globalVar = 0;

int addTwoInts(int num1, int num2){
    return num1 + num2;
}

int chageVariables(){
    int age = 10;
    globalVar = 20;
}


int main() {

    printf("\n");

    int total = addTwoInts(4,5);
    printf(" %d",total);

    int age = 10;

    globalVar = 50 ;

    printf("age before = %d \n\n",globalVar);
    chageVariables();
    printf("age after = %d \n\n",globalVar);

    return 1;

}