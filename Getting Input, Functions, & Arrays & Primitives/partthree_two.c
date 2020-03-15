#include <stdio.h>
#include <string.h>

int main(void)
{

    printf("\n");

    // ARRAYS -------------

    // We have already taken a look at arrays when we stored
    // strings in a character array.
    // An int array is the same type of thing, and array
    // that stores ints.
    // An array can only store elements of the same data type

    char wholeName[12] = "Derek Banas";

    // You can also define an array one element at a time

    int primeNums[3] = {
        2,
        3,
        5,
    };

    // You don't need to define the size if you define
    // the values up front

    int morePrimes[] = {13, 17, 19, 23};

    // Like most other languages the first number in an
    // array is put in the zero index

    printf("The first prime in the list is %d\n\n",
           primeNums[0]);

    // A character array can be created the same way

    char city[7] = {'C', 'h', 'i', 'c', 'a', 'g', 'o'};

    // If I want to print the character array as a string
    // though I have to add \0 at the end

    char anotherCity[5] = {'E', 't', 'n', 'a', '\0'};

    printf("A City %s\n\n", anotherCity);

    // Creating the string like before is easier
    // No quotes and an automatic null at the end

    char thirdCity[] = "Paris";

    // Once an array is defined we can change the value with
    // strcpy() but make sure if you do that that the new
    // array is of the same size, or less. Otherwise you will
    // overwrite other data in memory.
    // You have to make your arrays big enough to hold all
    // potential input, but don't over do it, or you'll consume
    // to much memory.

    char yourCity[30];

    printf("What city do you live in? ");

    // scanf() is kind of limited for adding a string to an array
    // 1. It will allow you to overwrite data past the end of
    //     the space allowed
    // 2. It won't allow you to enter spaces unless you define
    //     exactly how they will be entered
    // fgets() has neither of these problems and it also adds a
    // \0 at the end for you. The only negative is that you must
    // provide a size limit for the data being entered

    fgets(yourCity, 30, stdin);

    printf("Hello %s\n\n", yourCity);

    // fgets() Will read in everything up till the end of the array
    // is reached or until a \n is entered and then it will add
    // a \0 at the end. It leaves in the \n though which can be
    // a bad thing.

    // Let's get rid of the '\n'

    for (int i = 0; i < 30; i++)
    {

        if (yourCity[i] == '\n')
        {

            yourCity[i] = '\0';
            break;
        }
    }

    printf("Hello %s\n\n", yourCity);

    // Some string functions available

    // strcmp() takes 2 strings and returns a negative number
    // if the first string is less then the second. It returns
    // a positive if the opposite occurs. It returns a 0 if
    // they are equal

    printf("Is your city Paris? %d\n\n",
           strcmp(yourCity, thirdCity));

    // strcat() adds the second string to the end of the first

    char yourState[] = ", Pennsylvania";

    strcat(yourCity, yourState);

    printf("You live in %s\n\n", yourCity);

    // strlen() returns the length of the string plus the \0

    printf("Letters in Paris : %d\n\n", strlen(thirdCity));

    // As mentioned before strcpy() is bad for copying strings
    // because it can overwrite memory.
    // That is were strncpy() comes in.
    // It won't overwrite memory and it always adds a \0

    strncpy(yourCity,
            "El Pueblo del la Reina de Los Angeles",
            sizeof(yourCity));

    printf("The new name is %s\n\n", yourCity);
}