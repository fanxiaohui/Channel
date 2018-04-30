# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

void createLinkedList();
void outputData();



struct product {
    float price;
    char productName[30];
    struct product *next;
};

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

void initData(){

    if(pFirstNode == NULL ){
        createLinkedList();
    } else {
        struct product *pNewStruct = (struct product*) 
        malloc(sizeof(struct  product));

        printf("Enter product name: \n");
        scanf("%s",&(pNewStruct)->productName);

        printf("Enter product price: \n");
        scanf("%f",&(pNewStruct)->price);

        if (pFirstNode == pLastNode) {
            pFirstNode->next = pNewStruct;
            pLastNode = pNewStruct;
            pNewStruct->next =NULL;
        } else {
            pLastNode->next = pNewStruct;
            pNewStruct->next = NULL;
            pLastNode = pNewStruct;
        }
    }
    



}

int main(){
   initData();
   initData();
   initData();
   outputData();
   return 0;
}

void outputData(){
   struct product *pProducts = pFirstNode;
   printf("products entered: \n");

   while(pProducts!=NULL){
       printf("product name %s \tand product price is %.2f\n\n",
        pProducts->productName
        ,pProducts->price);
        pProducts = pProducts->next;
   }  
}

void createLinkedList() {
    struct product *pNewStruct = (struct product*) 
        malloc(sizeof(struct  product));
    pNewStruct->next = NULL;
    printf("Enter product name: \n");
    scanf("%s",&(pNewStruct)->productName);

    printf("Enter product price: \n");
    scanf("%f",&(pNewStruct)->price);

    pFirstNode = pLastNode = pNewStruct;

}
 
