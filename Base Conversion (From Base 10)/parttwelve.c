#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// With C we can actually work with individual bits.
// This is very useful if you want to work with hardware.

// What we use for counting is known as base 10.
// Base 10 numbers are calculated by multiplying each
// successive number by an increasing multiple of ten.
// 2 = 2 * 10^0
// 45 = ( 4 * 10^1 ) + ( 5 * 10^0 )

// It is believed we use base 10 because we have 10 fingers.
// To understand computers you must learn to understand the world
// of a machine that has only 2 fingers.

// 1 = 1 * 2^0 = 1
// 10 = ( 1 * 2^1  ) + ( 0 * 2^0  ) = 2
// 111 = ( 1 * 2^2  )   +  ( 1 * 2^1  )   +  ( 1 * 2^0  ) = 7

// Bytes are normally represented as 8 bits which can hold a
// maximum value of 255 because of how binary numbers work.

// Octal is a base 8 system. It includes numbers from 0 to 7
// They are often used because each octal digit represents 3
// binary digits.

// Hexadecimal is a base 16 system. It includes numbers 0 through
// 9 and the letters A through F. In C they can be represented with
// either lowercase or uppercase letters. Hex numbers are used because
// 2 digits can represent a byte.
char *convertBase(unsigned int numberToConvert, int base);

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

    return 0;
}

char *convertBase(unsigned int numberToConvert, int base)
{

    // Buffer that will hold 32 bits + a \0 at the end

    char buffer[33];
    char *pConvertedNumber;

    // NEW : All the potential numbers and letters in the converted
    // number

    char allValues[] = "0123456789abcdef";

    if (base < 2 || base > 16)
    {
        printf("Enter a Number Between 2 and 16\n");
        exit(1);
    }

    // Point to the last index in the character array

    pConvertedNumber = &buffer[sizeof(buffer) - 1];

    // Put \0 in that last index in the char array

    *pConvertedNumber = '\0';

    do
    {

        // Get the right index from allValues[] 0 through f

        int value = numberToConvert % base;

        // Decrement the pointer to the next index to the
        // left in the char array

        pConvertedNumber = pConvertedNumber - 1;

        // Store the proper value in the char array for the
        // final converted number

        // *pConvertedNumber = '0' + value;

        *pConvertedNumber = allValues[value];

        // Divide by the base to check for the next number

        numberToConvert /= base;

    } while (numberToConvert != 0);

    printf("%s", pConvertedNumber);

    return pConvertedNumber;
}
