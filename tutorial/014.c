# include <stdio.h>
# include <stdlib.h> 


void generateTwoRandomNumbers(int rand1,int rand2) {
    rand1 = rand()%50 +1;// 产生0到49的随机数加上一
    rand2 = rand()%50 +1;
    printf("rand1 in function is %d\n\n", rand1);
    printf("rand2 in function is %d\n\n", rand2);
}

void pointerRandomNumbers(int* rand1, int* rand2){
     *rand1 = rand()%50 +1;// 产生0到49的随机数加上一
    *rand2 = rand()%50 +1;
    printf("rand1 in pointer function is %d\n\n", *rand1);
    printf("rand2 in pointer function is %d\n\n", *rand2);
}

int main() {
    int rand1 =0 ,rand2 =0;

    // printf("rand1 address is  %d \n",&rand1);
    // printf("rand2 address is  %d \n",&rand2);
    // rand1 address is  6422316
    // rand2 address is  6422312
    //虽然二者的值相同，但其内存位置还是不同的
    generateTwoRandomNumbers(rand1,rand2);
    printf("rand1 after function call is %d\n\n", rand1);
    printf("rand2 after function call is %d\n\n", rand2);

    printf("Now we use pointers\n");
    pointerRandomNumbers(&rand1,&rand2);// &用于传递地址
    printf("rand1 after pointer function call is %d\n\n", rand1);
    printf("rand2 after pointer function call is %d\n\n", rand2);
}