#include<stdio.h>
union sizeTest{
        int a[10];
        double b;
};
int main(){
        union sizeTest unionA;
        union sizeTest unionB;
        union sizeTest unionC;
 
        printf("the initial address of unionA is %p\n",&unionA);
        printf("the initial address of unionB is %p\n",&unionB);
        printf("the initial address of unionC is %p\n",&unionC);

        
        printf("the sizeof unionA is %ld\n",sizeof(unionA));
        printf("the sizeof of unionB is %ld\n",sizeof(unionB));
        printf("the sizeof of unionC is %ld\n",sizeof(unionC));
        return 0;

}


