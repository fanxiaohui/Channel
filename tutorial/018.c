# include <stdio.h>
# include <stdlib.h>


typedef struct product {
    const char *name;
    float price;
    struct product *next;

} product;

void printLinkedList(product *pProduct){
    while(pProduct!=NULL){
        // (*product).
        printf(" A %s costs %.2f \n\n",
        (*pProduct).name,
        pProduct->price);
        pProduct = pProduct->next;
    }
}
int main() {
    product tomato = {"Tomato",.51,NULL};
    product potato = {"potato",1.29,NULL};
    product lemon = {"Lemon",2.11,NULL};
    product milk = {"Milk",3.11,NULL};
    product juice = {"Juice",0.11,NULL};

    tomato.next = &potato;
    potato.next = &lemon;
    lemon.next = &milk;
    milk.next = &juice;

    product apple = {"Apple", 4.3,NULL};

    lemon.next = &apple;
    apple.next = &milk;

    printLinkedList(&tomato);


    
}