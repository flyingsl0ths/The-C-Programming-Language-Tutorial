#include <stdio.h>

int main(void)
{

    // Use gcc ProgramName.c -o ProgramName to define the name
    // for your program instead of using a.out
    // Execute with ./ProgramName

    // There are many ways to compare data in c
    // >, <, ==, >=, <=, !=
    // Only compare values with the same data type
    // To compare 2 unlike types perform a cast
    // A relational operator always evaluates to 1 for true, or 0 for false

    printf("\n");

    int num1 = 1, num2 = 2;

    printf("Is 1 > 2 : %d\n\n", num1 > num2);

    // If is used to compare values and perform different actions
    // depending on those comparisons.
    // You can check multiple conditions with else if and
    // you can define a default with else
    // Once one condition is true the code in between the curly
    // brackets that follows is executed and then no other
    // condition that follows is checked.

    if (num1 > num2)
    {

        printf("%d is greater then %d\n\n", num1, num2);
    }
    else if (num1 < num2)
    {

        printf("%d is less then %d\n\n", num1, num2);
    }
    else
    {

        printf("%d is equal to %d\n\n", num1, num2);
    }

    // Logical operators are used to combine the above relational
    // operators. && - And, || - Or, ! - Not

    // Computers are Logical they only understand 1s and 0s
    // Relational operators check how values relate

    int custAge = 38;

    if (custAge > 21 && custAge < 35)
        printf("They are welcome\n\n");
    else
        printf("They are not welcome\n\n");

    // ! - Not turns a 1 to 0 and vice versa
    // Surround relations with parentheses when using not
    // This won't work !custAge > 21

    printf("! turns a true into false : %d\n\n", !1);

    // Bob deserves a raise if he has missed less then 10 days work
    // and has over 30000 in sales or has signed up 30 new customers

    int bobMissedDays = 8, bobTotalSales = 24000, bobNewCust = 32;

    if (bobMissedDays < 10 && bobTotalSales > 30000 || bobNewCust > 30)
    {

        printf("Bob gets a raise\n\n");
    }
    else
    {

        printf("Bob doesn't get a raise\n\n");
    }

    // The Conditional Operator is great for replacing simple if statements
    // (comparison) ? happensIfTrue : happensIfFalse;
    // Don't worry about char* for now

    char *legalAge = (custAge > 21) ? "true" : "false";

    printf("Is the customer of legal age? %s\n\n", legalAge);

    // You can change printf with a conditional operator directly

    int numOfProducts = 10;

    printf("I bought %s products\n\n",
           (numOfProducts > 1) ? "many" : "one");

    // How much space are data types taking up?

    printf("A char takes up %d bytes\n\n", sizeof(char));

    printf("An int takes up %d bytes\n\n", sizeof(int));

    printf("A long int takes up %d bytes\n\n", sizeof(long int));

    printf("A float takes up %d bytes\n\n", sizeof(float));

    printf("A double takes up %d bytes\n\n", sizeof(double));

    // What is a byte, bit, etc?
    // A Bit is short for Binary Digit and can be either a 1 or 0
    // A Byte is generally considered to be 8 Bits

    int bigInt = 2147483648;

    printf("I'm bigger then you may have heard %d\n\n", bigInt);

    // Calculate the maximum value based on bits

    int numberHowBig = 0;

    printf("How Many Bits? ");

    scanf(" %d", &numberHowBig);

    printf("\n\n");

    // 0 : Print what was given
    // 1 : Print what was given
    // 2 : 1 + 2 = 3 (Binary : 11)
    // 3 : 3 + 4 = 7 (Binary : 111)
    // 4 : 7 + 8 = 15 (Binary : 1111)

    // Initialize the incrementor before the while loop

    int myIncrementor = 1, myMultiplier = 1, finalValue = 1;

    while (myIncrementor < numberHowBig)
    {

        myMultiplier *= 2;

        finalValue = finalValue + myMultiplier;

        // Test to track and make sure I'm right

        printf("finalValue: %d myMultiplier: %d myIncrementor: %d\n\n",
               finalValue, myMultiplier, myIncrementor);

        // Don't forget to increment so the while loop ends
        // when the condition becomes false (Infinite Loop Otherwise)

        myIncrementor++;
    }

    // Handle if user enters 0 or 1

    if ((numberHowBig == 0) || (numberHowBig == 1))
    {

        printf("Top Value: %d\n\n", numberHowBig);
    }
    else
    {

        printf("Top Value: %d\n\n", finalValue);
    }

    int secretNumber = 10, numberGuessed = 0;

    // Infinite while loop

    while (1)
    {

        printf("Guess My Secret Number: ");
        scanf(" %d", &numberGuessed);

        if (numberGuessed == 10)
        {

            printf("You Got It");

            // break is used to throw you the the first
            // line of code after the loop

            break;
        }
    }

    printf("\n\n");

    // You use a Do While Loop when you need something done
    // at least once, but don't know the number of times you
    // may need to loop

    char sizeOfShirt;

    do
    {

        printf("What Size of Shirt (S,M,L): ");

        scanf(" %c", &sizeOfShirt);

    } while (sizeOfShirt != 'S' && sizeOfShirt != 'M' && sizeOfShirt != 'L');

    // When you know up front exactly how many times you
    // need to loop then use a for loop
    // for(define incrementor; define condition; increment incrementor)

    for (int counter = 0; counter <= 20; counter++)
    {

        printf("%d ", counter);
    }

    printf("\n\n");

    // Print only odd numbers

    for (int counter = 0; counter <= 40; counter++)
    {

        // continue is used to skip this iteration of the loop
        // and instead continue with the next loop cycle

        if ((counter % 2) == 0)
            continue;

        printf("%d ", counter);
    }
}