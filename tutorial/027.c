# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>


struct product {
    float price;
    char productName[30];
};

int main(){
    struct product *pProduct;
    int i,j;
    int numberOfProducts;
    printf("Enter the number of products you want to store :\n");

    scanf("%d",&numberOfProducts);
    pProduct = (struct product *)malloc(numberOfProducts *sizeof(struct product));
    if(pProduct != NULL){
        for(i=0; i< numberOfProducts ;++i){ 
            printf("Enter a product name: \n");
            scanf("%s",&(pProduct+i)->productName);
            printf("Enter a product price: \n");
            scanf("%f",&(pProduct+i)->price);
        }
        printf("total products:  \n");
        for(j =0 ;j<numberOfProducts;j++){
            printf("%s\t%.2f\n",(pProduct+j)->productName,(pProduct+j)->price);
        }
        free(pProduct);
    }
   
   return 0;

}
 
