#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
# include <string.h>

struct product {
    float price;
    char productName[30];
};

int main(){

    struct product myProduct = {
        20.5,"name of the product"
    };

    struct product *pProduct = &myProduct;
    // pProduct->productName = "NEW NAME";
    pProduct->price = 32.21;
    strcpy(pProduct->productName,"some awesome new name!\n");
    printf("memory address is %d\n", &myProduct);
    printf("product price is %.2f\n",myProduct.price);
    printf("product price is %.2f\n",pProduct->price);
    printf("product price is %.2f\n",(*pProduct).price);
    
    printf("my product now has a brand new name %s! ",pProduct->productName);
    
    char theString[] = "the original string ";
    printf("value %s \n ",theString);
    // theString = "modified value for the string";
    strcpy(theString,"modified value is very long very long ");
    printf("value %s \n ",theString);

    char a[] = "Sam";
    printf("sizeof sam is %d: \n",sizeof(a));

    char *pSam = "Sam";
    printf("sizeof sam is %d: \n",sizeof(pSam));
    printf("Sam's memory address is  %d \n\n",pSam);
    printf(pSam);
    printf("\n");
    printf(a);
    
    return 0;
}
