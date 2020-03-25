#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2

typedef struct product
{
    float price;
    char productName[30];

    struct product *next;
} product;

// To traverse the struct linked list I just need to
// track the first and last node in the list

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

void askForData(product *p);
void createNewList();
void inputData();
void outputData();

int main(void)
{

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        inputData();
    }

    outputData();

    return 0;
}

void askForData(product *p)
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

    product *temp = (product *)malloc(sizeof(product));

    // We can assign the value directly for the structs
    // reference for the next struct in the linked list

    temp->next = NULL;

    askForData(temp);

    // When the first struct is created all of the following
    // refer to the same struct

    pFirstNode = pLastNode = temp;
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

        product *temp = (product *)malloc(sizeof(product));

        askForData(temp);

        // If the first and last struct are equal we know this
        // is the second struct in the list

        if (pFirstNode == pLastNode)
        {

            // Assign the value of next for the first struct to
            // this new one since the new one is the second struct

            pFirstNode->next = temp;

            // Since this is the second struct we know the last
            // struct is equal to this new one

            pLastNode = temp;

            // Since this is the last struct in the list it has
            // NULL stored in its next

            temp->next = NULL;
        }
        else
        {

            // We know that this is at least the third struct in the
            // list so we don't need to touch the pFirstNode.
            // We instead just change the pLastNode value for next
            // from NULL to our new struct

            pLastNode->next = temp;

            temp->next = NULL;

            pLastNode = temp;
        }
    }
}

void outputData()
{

    // This temporarily takes the location of the structs in the
    // linked list as we cycle through them to the end

    product *temp = pFirstNode;

    printf("Products Entered\n\n");

    // Until the ptr reaches a value of NULL for next we'll
    // keep printing out values

    while (temp != NULL)
    {

        printf("%s costs %.2f\n\n", temp->productName, temp->price);

        // Switch to the next struct in the list

        temp = temp->next;
    }
}