#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
# include <string.h>

struct product {
    float price;
    char productName[30];
    char *changeableName;
};

void getStructAdress(struct product *pProduct);
void allocatingMemory();

int main(){

    struct product myProduct = {
        20.5,"name of the product"
    };

    struct product *pProduct = &myProduct;
    // pProduct->productName = "NEW NAME";
    pProduct->price = 32.21;
    strcpy(pProduct->productName,"some awesome new name!\n");
    // printf("memory address is %d\n", &myProduct);
    // printf("product price is %.2f\n",myProduct.price);
    // printf("product price is %.2f\n",pProduct->price);
    // printf("product price is %.2f\n",(*pProduct).price);
    // getStructAdress(pProduct);

    allocatingMemory();
    
    return 0;
}

void getStructAdress(struct product *pProduct){
    printf("the memory adress is %p \n",pProduct);
    printf("the actual value is %s\n",pProduct);
}
void allocatingMemory(){
    struct product *pPointer = NULL;
    pPointer = (struct product *) malloc(sizeof(struct product));
    if(pPointer!=NULL) {
        strcpy( pPointer->productName,"hateful day");
        printf("the product price can be cahnges %d \n",pPointer->price);
        // pPointer->price =23.56;
        pPointer->price =23.12;
        pPointer->changeableName = "This can be changed";
        
        // pPointer->productName = "error: assignment to expression with array type";
        printf("the product name is :  %s \n ",pPointer->productName);
        printf("the changeable name is :  %s \n ",pPointer->changeableName);
        printf("the product price can be cahnges %.2f \n",pPointer->price);
        free(pPointer);
    }

}
