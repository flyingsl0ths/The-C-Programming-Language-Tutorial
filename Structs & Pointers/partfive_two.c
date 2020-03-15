#include <stdio.h>

// This struct will be stored in the dog struct

struct dogsFavs
{

    char *food;
    char *friend;
};

// You can use typedef to shorten struct dog to
// just dog by doing this instead

typedef struct dog
{

    const char *name;
    const char *breed;
    int avgHeightCm;
    int avgWeightLbs;

    struct dogsFavs favoriteThings;
} dog;

void getDogFavs(dog theDog)
{

    printf("\n");

    // To get the data in the struct you just chain
    // dot operators.
    // Since struct dogsFavs favoriteThings; is in dog
    // you use that after theDog variable name like
    // any other variable

    printf("%s loves %s and his friend is named %s\n\n", theDog.name,
           theDog.favoriteThings.food,
           theDog.favoriteThings.friend);
}

void setDogWeight(dog theDog, int newWeight)
{

    theDog.avgWeightLbs = newWeight;

    printf("The weight was changed to %d\n\n",
           theDog.avgWeightLbs);
}

// struct dog *theDog means the function expects a pointer
// of type struct dog

void setDogWeightPtr(dog *theDog, int newWeight)
{

    // You use *theDog to get the value at the pointers address
    // You have to surround a struct with parentheses

    (*theDog).avgWeightLbs = newWeight;

    printf("The weight was changed to %d\n\n",
           (*theDog).avgWeightLbs);

    // You can use either (*theDog).avgWeightLbs or
    // theDog->avgWeightLbs

    // theDog->avgWeightLbs means the variable named
    // avgWeightLbs in the struct theDog

    printf("The weight with -> %d\n\n",
           theDog->avgWeightLbs);
}

int main(void)
{

    // We can also store structs in structs

    dog benji = {"Benji", "Silky Terrier", 25, 9, {"Meat", "Joe Camp"}};

    getDogFavs(benji);

    // How do you change a value in a struct

    setDogWeight(benji, 11);

    printf("The weight in main() %d\n\n",
           benji.avgWeightLbs);

    // It prints the old weight because when a struct is
    // passed to a function a new struct is passed to the
    // function with Benjis values

    // You need to pass the structs pointer with &

    setDogWeightPtr(&benji, 11);

    printf("The weight in main() %d\n\n",
           benji.avgWeightLbs);
}