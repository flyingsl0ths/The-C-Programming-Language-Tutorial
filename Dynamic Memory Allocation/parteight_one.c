#include <stdio.h>
#include <stdlib.h>

// When you define an int, float, or array, you define exactly how
// much memory you need and that is all you can get at run time
// using traditional data types.

// If you need to allocate memory as a program runs you need
// malloc()

// When malloc() is called you pass it the amount of memory required and
// it returns the address to that memory that you can refer to using
// a pointer. If the space couldn't be found null is returned.

int main(void)
{

    int amtOfNumbersToStore;

    printf("How many numbers do you want to store: ");

    scanf("%d", &amtOfNumbersToStore);

    // Create an int pointer and set aside enough space to hold the ints
    // required.
    // pRandomNumbers points to just the first element, but it can
    // access the others.
    // The typecast (int *) isn't required in C, but is in C++

    int *pRandomNumbers;
    pRandomNumbers = (int *)malloc(amtOfNumbersToStore * sizeof(int));

    // Check if memory was allocated by malloc

    if (pRandomNumbers != NULL)
    {

        int i = 0;

        printf("Enter a Number or Quit: ");

        // Receives ints until the memory allocated is full, or
        // until a non int is entered

        // You store values by referring to the pointer using
        // array notation

        while (i < amtOfNumbersToStore && scanf("%d",
                                                &pRandomNumbers[i]) == 1)
        {

            printf("Enter a Number or Quit: ");

            i++;
        }

        printf("\nYou entered the following numbers\n");

        //

        for (int j = 0; j < i; j++)
        {

            printf("%d\n", pRandomNumbers[j]);
        }
    }

    // Make sure you give back the memory allocated by malloc
    // when you are finished with it.

    free(pRandomNumbers);

    // In this program free() isn't required because all allocated
    // memory is returned to the system when the program terminates.

    // free() would be required though if you were allocating large
    // blocks of memory over and over without returning it.

    // Let's say you store 10k of data using malloc, use it and have
    // no further use for it but don't use free.
    // Then you grab another 10k over and over. Eventually you'll
    // run out of memory and get a memory leak.

    return 0;
}