# include <stdio.h>
# include <stdlib.h>

int main(){
    // union有时候表示int，有时候表示float


   typedef enum {
        INDIVIDUAL,
        OUNCE,
        POUND
    } quantity;

    typedef union {
        short individual;
        float pound;
        float ounce;
        char* names[20];
        quantity type;
    } amount;

    amount orangeAmount= {.ounce = 16};//使用的更多, designated initializer

     orangeAmount.individual = 4;

     printf("Orange Juice ounce amout: %.2f : Size : %d\n\n",
     orangeAmount.ounce,sizeof(orangeAmount.ounce));


    printf("Number of oranges individual: %d : Size: %d\n\n",
        orangeAmount.individual,
        sizeof(orangeAmount.individual)
    );

    orangeAmount.pound = 1.5;
    printf("Orange Juice pound amout: %.2f : Size : %d\n\n",
     orangeAmount.pound,sizeof(orangeAmount.pound));

    typedef struct {
        char *brand;
        amount theAmout;
    } orangeProduct;

    orangeProduct productOrderd = {
        "Chiquita",
        .theAmout.ounce =16
    };

    printf("you bought %.2f ounces of %s oranges\n\n",
    productOrderd.theAmout.ounce,
    productOrderd.brand
    );

    // orangeAmount.ounce = 24.5; 如果这一段不声明的话，因为union中同时只能存储一种数据，最近的一次存储的是1.5pound,所以会将pound的值直接当作ounce的值返回

   
    quantity quantType = OUNCE;

    orangeAmount.individual = 4;

    if(quantType == INDIVIDUAL) {
        printf("you bought %d oranges\n\n",orangeAmount.individual);
    }else if(quantType == OUNCE) {
        printf("you bought %.2f ounces of oranges\n\n",orangeAmount.ounce);
    }else {
        printf("you bought %.2f pounds of oranges\n\n",orangeAmount.pound);
    }
    printf("=====the size of the union is %d\n\n",sizeof(orangeAmount));
   

    printf("the size of the product is %d\n\n",sizeof(productOrderd));
}