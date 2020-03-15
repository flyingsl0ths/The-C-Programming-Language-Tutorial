#include <stdio.h>

// Needed for exit(), rand()
#include <stdlib.h>

// I'm a global variable. Every function can see me and change
// my value.

int globalVar = 0;

// Each function has a return type
// (void if nothing is returned)
// Between the parentheses you can define the type and number
// of attributes passed to the function if any

int addTwoInts(int num1, int num2);

void changeVariables();

int main(void)
{

    // FUNCTIONS ------------------

    // If you want to some day make a big program you will
    // have to step out of main().
    // With a complex program you are going to want to write
    // a function for each task required

    // How to call a function and pass data by value to it

    int total = addTwoInts(4, 5);

    printf("The Sum is %d\n\n", total);

    // GLOBAL VS LOCAL VARIABLES ------

    // That brings us to the concept of local versus global
    // variables.

    // This age variable is local to main()

    int age = 10;

    // I changed the global variable globalVar here to 50

    globalVar = 50;

    printf("age before a call to the function = %d\n\n", age);

    printf("globalVar before a call to the function = %d\n\n", globalVar);

    changeVariables();

    printf("age after a call to the function = %d\n\n", age);

    printf("globalVar after a call to the function = %d\n\n", globalVar);
}

void changeVariables()
{

    // This variable is local and doesn't exist outside
    // of this function even if it has the same name
    // as a variable outside of this function

    int age = 40;

    printf("age inside of function = %d\n\n", age);

    // Since globalVar is accessible in any function though
    // can change it for all other functions

    globalVar = 100;

    printf("globalVar inside of function = %d\n\n", globalVar);
}

int addTwoInts(int num1, int num2)
{

    // return the result to the function that called this one

    return num1 + num2;
}