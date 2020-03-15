// structs are used when you need more then one
// piece of data to describe one thing.
// We can't use an array because areas only hold one
// type of data.

#include <stdio.h>

// This creates a dog struct with the data needed

struct dog
{

    // Labeled with const because they won't change

    const char *name;
    const char *breed;
    int avgHeightCm;
    int avgWeightLbs;
};

void getDogInfo(struct dog theDog)
{

    printf("\n");

    // Since a struct is initialized like an array you
    // may think you access the data like this theDog[0],
    // but they don't work that way. You need to use the
    // dot operator like this.

    printf("Name: %s\n\n", theDog.name);
    printf("Breed: %s\n\n", theDog.breed);
    printf("Avg Height: %d cm\n\n", theDog.avgHeightCm);
    printf("Avg Weight: %d lbs\n\n", theDog.avgWeightLbs);
}

void getMemoryLocations(struct dog theDog)
{

    printf("Name Location: %d\n\n", theDog.name);
    printf("Breed Location: %d\n\n", theDog.breed);
    printf("Height Location: %d\n\n", &theDog.avgHeightCm);
    printf("Weight Location: %d\n\n", &theDog.avgWeightLbs);
}

int main(void)
{

    // Define a new dog by passing the values specific
    // to this dog.
    // struct is the data type and cujo is the variable name

    struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};

    // Now we can pass all the dog info easily

    getDogInfo(cujo);

    // Keynote Presentation --------------------
    // A struct defines a template for your data type
    // A struct variable defines the memory needed to fit the data

    // What happens if a struct is copied to another?
    // They point to the same memory locations

    struct dog cujo2 = cujo;

    getMemoryLocations(cujo);

    getMemoryLocations(cujo2);
}