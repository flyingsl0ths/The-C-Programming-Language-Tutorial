#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // Used for pow()
#include <ctype.h> // Used for isalpha()

char *convertBase(unsigned int numberToConvert, int base);

/* WORKS UNTIL LETTERS ARE USED*/

// int baseToDecimal(char* number, int baseFrom, int sizeOfNumber);

// WORKS WITH HEXADECIMALS

int baseToDecimal(char *number, int baseFrom, int sizeOfNumber);

int main(void)
{

    unsigned int numberOne = 60; // 111100

    printf("%d in Base 2 = ", numberOne);
    convertBase(numberOne, 2);

    printf("\n%d in Base 8 = ", numberOne);
    convertBase(numberOne, 8);

    printf("\n%d in Base 16 = ", numberOne);
    convertBase(numberOne, 16);

    printf("\n");

    // Work Out the Key Codes for Hexadecimals
    /*
	printf("A : %d\n", 'A');
	printf("b : %d\n", 'b');
	printf("c : %d\n", 'c');
	printf("d : %d\n", 'd');
	printf("e : %d\n", 'e');
	printf("f : %d\n", 'f');
	*/

    char numberToConvert[] = "3C";

    baseToDecimal(numberToConvert, 16, sizeof(numberToConvert));

    return 0;
}

// int baseToDecimal(char* number, int baseFrom, int sizeOfNumber)
// {

//     int result = 0;
//     int toThePowerOf = 0;

//     // Cycle through all letters in the array starting with the last one
//     // We subtract 2 because indexing starts at 0 and to avoid the '\0'

//     for ( int i = (sizeOfNumber - 2); i >= 0; --i ){

//     	// Copying this style
//     	// ... +  ( 4 * 8^1 )  +  ( 5 * 8^0 )

//         result += (number[i] - '0') * pow(baseFrom, toThePowerOf);

//         toThePowerOf++;

//     }

//     printf("%s in base %d equals %d in base 10\n", number, baseFrom, result);

//     return result;
// }

char *convertBase(unsigned int numberToConvert, int base)
{

    char buffer[33];
    char *pConvertedNumber;

    char allValues[] = "0123456789abcdef";

    if (base < 2 || base > 16)
    {
        printf("Enter a Number Between 2 and 16\n");
        exit(1);
    }

    pConvertedNumber = &buffer[sizeof(buffer) - 1];

    *pConvertedNumber = '\0';

    do
    {

        int value = numberToConvert % base;

        pConvertedNumber = pConvertedNumber - 1;

        *pConvertedNumber = allValues[value];

        numberToConvert /= base;

    } while (numberToConvert != 0);

    printf("%s", pConvertedNumber);

    return pConvertedNumber;
}

int baseToDecimal(char *number, int baseFrom, int sizeOfNumber)
{

    int result = 0;
    int toThePowerOf = 0;

    for (int i = (sizeOfNumber - 2); i >= 0; --i)
    {

        // Check if character in the array is a letter

        if (isalpha(number[i]))
        {

            // Convert the letter into the right character code
            // and subtract 87 to make 'a' = 10 along with other
            // letters

            int charCode = ((int)tolower(number[i])) - 87;

            // Copying this style
            // ... +  ( 4 * 8^1 )  +  ( 5 * 8^0 )

            result += charCode * pow(baseFrom, toThePowerOf);
        }
        else
        {

            result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
        }

        toThePowerOf++;
    }

    printf("%s in base %d equals %d in base 10\n", number, baseFrom, result);

    return result;
}