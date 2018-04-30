# include <stdio.h>
# include <stdlib.h>

// pointers 
int main() {
    int rand1 = 12 ,rand2  =15;

    printf("rand1 =%p : rand2 = %p \n\n", &rand1,&rand2); // 输出hexdecimal形式的地址
    //  rand1 =0061FF2C : rand2 = 0061FF28
    printf("rand1 =%d : rand2 = %d \n\n", &rand1,&rand2); //输出十进制的内存地址
    // rand1 =6422316 : rand2 = 6422312
    printf("Size of int %d\n\n",sizeof(rand1));


    int * pRand1 = &rand1; //指针直接指向了上面提到的内存位置 ,指针一般命名的时候以小写字母p开头
    printf("Pointer %p\n\n",pRand1);
    printf("Pointer %d\n\n",pRand1);
    
    printf("value of the pointer %d\n\n",*pRand1);

}