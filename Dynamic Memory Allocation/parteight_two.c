#include <stdio.h>
#include <stdlib.h>

// struct that holds product information

struct product
{
    float price;
    char productName[30];
};

int main(void)
{

    // Pointer to a struct

    struct product *pProducts;

    int i, j;

    int numberOfProducts;

    printf("Enter the Number of Products to Store: ");

    // Dynamically we are defining how much space we need at run time

    scanf("%d", &numberOfProducts);

    // Allocates the memory required to store the structs
    // Type casting isn't needed for C, but is required for C++

    pProducts = (struct product *)malloc(numberOfProducts *
                                         sizeof(struct product));

    for (i = 0; i < numberOfProducts; ++i)
    {

        printf("Enter Product Name: ");

        // This time I use pointer arithmetic to cycle through the data
        // and print it out

        scanf("%s", &(pProducts + i)->productName);

        printf("Enter Product Price: ");

        scanf("%f", &(pProducts + i)->price);
    }

    printf("Products Stored\n");

    for (j = 0; j < numberOfProducts; ++j)
    {

        printf("%s\t%.2f\n", (pProducts + j)->productName, (pProducts + j)->price);
    }

    free(pProducts);

    return 0;
}