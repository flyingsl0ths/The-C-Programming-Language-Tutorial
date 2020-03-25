#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 4

struct product
{
    float price;
    char productName[30];

    struct product *next;
};

// To traverse the struct linked list I just need to
// track the first and last node in the list

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

// NEW : Added For removeProduct
struct product *pProductBeforeProductToDelete = NULL;

void createNewList();

void askForData(struct product *p);
void inputData();

void outputData();

// PART 2 ---------------------------

// Searches for a struct of a given name and returns it if found

struct product *searchForProduct(char *productName);

// PART 3 ---------------------------

void removeProduct(char *productName);

int main(void)
{

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        inputData();
    }

    // PART 2

    searchForProduct("Tomato");

    // PART 3

    removeProduct("Egg");

    removeProduct("Tomato");

    outputData();

    free(pFirstNode);

    free(pLastNode);
}

void askForData(struct product *p)
{
    printf("Enter Product Name: ");

    // The & is needed only because scanf() is used

    scanf("%s", &(p)->productName);

    printf("Enter Product Price: ");

    scanf("%f", &(p)->price);
}

void createNewList()
{

    // Set aside enough space in memory for this struct

    struct product *pNewStruct = (struct product *)malloc(sizeof(struct product));

    // We can assign the value directly for the structs
    // reference for the next struct in the linked list

    pNewStruct->next = NULL;

    askForData(pNewStruct);

    // When the first struct is created all of the following
    // refer to the same struct

    pFirstNode = pLastNode = pNewStruct;
}

void inputData()
{

    if (pFirstNode == NULL)
    {

        createNewList();
    }
    else
    {

        // Set aside enough space in memory for this struct

        struct product *pNewStruct = (struct product *)malloc(sizeof(struct product));

        printf("Enter Product Name: ");

        // The & is needed only because scanf() is used

        scanf("%s", &(pNewStruct)->productName);

        printf("Enter Product Price: ");

        scanf("%f", &(pNewStruct)->price);

        // If the first and last struct are equal we know this
        // is the second struct in the list

        if (pFirstNode == pLastNode)
        {

            // Assign the value of next for the first struct to
            // this new one since the new one is the second struct

            pFirstNode->next = pNewStruct;

            // Since this is the second struct we know the last
            // struct is equal to this new one

            pLastNode = pNewStruct;

            // Since this is the last struct in the list it has
            // NULL stored in its next

            pNewStruct->next = NULL;
        }
        else
        {

            // We know that this is at least the third struct in the
            // list so we don't need to touch the pFirstNode.
            // We instead just change the pLastNode value for next
            // from NULL to our new struct

            pLastNode->next = pNewStruct;

            pNewStruct->next = NULL;

            pLastNode = pNewStruct;
        }
    }
}

void outputData()
{

    // This temporarily takes the location of the structs in the
    // linked list as we cycle through them to the end

    struct product *pProducts = pFirstNode;

    printf("Products Entered\n\n");

    // Until the ptr reaches a value of NULL for next we'll
    // keep printing out values

    while (pProducts != NULL)
    {

        printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);

        // Switch to the next struct in the list

        pProducts = pProducts->next;
    }
}

struct product *searchForProduct(char *productName)
{

    // Will hold the current struct as we cycle through them

    struct product *pProductIterator = pFirstNode;

    // Cycle through the structs in the list until next returns
    // NULL which means we reached the end of the list

    while (pProductIterator != NULL)
    {

        // Compare the first 30 characters of the 2 product names

        int areTheyEqual = strncmp(pProductIterator->productName,
                                   productName, 30);

        // If strings are equal areTheyEqual will have a value
        // of 0, so not is used to make 0 into 1 in that situation

        if (!areTheyEqual)
        {

            printf("%s was found and it costs %.2f\n\n",
                   pProductIterator->productName,
                   pProductIterator->price);

            // Return the product struct if found

            return pProductIterator;
        }

        // NEW : Added For removeProduct
        pProductBeforeProductToDelete = pProductIterator;

        // Cycle to the next product struct in the list

        pProductIterator = pProductIterator->next;
    }

    printf("%s wasn't found\n\n", productName);

    return NULL;
}

void removeProduct(char *productName)
{

    struct product *pProductToDelete = NULL;

    pProductToDelete = searchForProduct(productName);

    if (pProductToDelete != NULL)
    {

        printf("%s Was Deleted\n\n", productName);

        // If we want to delete the first product we
        // must assign the next product in the list
        // to the firstNode

        // If we want to delete the last product we
        // must assign the previous product in the list
        // as the lastNode

        if (pProductToDelete == pFirstNode)
        {

            pFirstNode = pProductToDelete->next;
        }
        else if (pProductToDelete == pLastNode)
        {
            pProductBeforeProductToDelete->next = pProductToDelete->next;
            pLastNode = pProductBeforeProductToDelete;
        }
        else
        {

            // Get the product to delete and assign its next
            // to the product before the product that is deleted

            pProductBeforeProductToDelete->next = pProductToDelete->next;
        }

        free(pProductToDelete);
    }
    else
    {

        printf("%s Was Not Found\n\n", productName);
    }
}