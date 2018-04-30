# include <stdio.h>
# include <stdlib.h> 


struct dogsFavs {
    char *food;
    char *friend;
};

typedef struct dog {
    const char* name;
    const char* breed;
    int avgHeightCm;
    int avgWeightLbs;
    struct dogsFavs favoriteThings;
} Dog;


void getDogInfo(struct dog theDog) {
    printf("\n");

    printf("Name: %s\n\n",theDog.name);
    printf("Breed: %s\n\n",theDog.breed);
    printf("avgHeight: %d\n\n",theDog.avgHeightCm);
    printf("avgWeightLbs: %d\n\n",theDog.avgWeightLbs);
    
}

void getMemoryLocations(struct dog theDog){
    printf("Name location: %d\n\n",theDog.name);
    printf("breed location: %d\n\n",theDog.breed);
    printf("avgHeight location: %d\n\n",&theDog.avgHeightCm);
    printf("avgWeight location: %d\n\n",&theDog.avgWeightLbs);
    
}

void getDogFavs(Dog theDog){
    printf("\n");
    printf("%s loves %s and his frined is %s\n\n",
    theDog.name,
    theDog.favoriteThings.food,
    theDog.favoriteThings.friend);
}

void setDogWeight(Dog theDog, int newWeight){
    theDog.avgWeightLbs = newWeight;
    printf("The Weight wa changed to %d\n\n",
    theDog.avgWeightLbs);

}

void setDogWeightPtr(Dog *theDog,int newWeight){
    (*theDog).avgWeightLbs = newWeight;
     printf("The Weight wa changed in ptr function to %d\n\n",
    (*theDog).avgWeightLbs);
    printf("we can also use right arrow to reference stuff in struct %d\n\n",
    theDog->avgWeightLbs);
}


int main() {
    struct dog cujo = {
        "Cujo","Sint Bernard",
        90,264
    };
    getDogInfo(cujo);

    struct dog cujo2 = cujo;

    getMemoryLocations(cujo);
    getMemoryLocations(cujo2);

    Dog benji = {"Benji","Silky Terrier",
    25,9,
    {"Meat","Joe Camp"}};

    // getDogFavs(benji);

    setDogWeight(benji,20);

    printf("Now the weight should be %d\n\n",benji.avgWeightLbs);
    setDogWeightPtr(&benji,20);
    printf("Now the weight should be %d\n\n",benji.avgWeightLbs);
    
}