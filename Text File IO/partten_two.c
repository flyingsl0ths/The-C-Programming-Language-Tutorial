#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *pFile;

    pFile = fopen("randomwords.txt", "r+");

    char buffer[1000];

    // If the file wasn't opened a NULL is returned from fopen()

    if (!pFile)
    {

        printf("Error : Couldn't Write to File\n");

        return 1;
    }

    fputs("Messing With Strings", pFile);

    // Move 12 spaces from the beginning of the file
    // SEEK_SET - Move starting from the beginning of the file
    // SEEK_CUR - Move based off of the current position in the file
    // SEEK_END - Move based off of starting at the end of the file

    fseek(pFile, 12, SEEK_SET);

    // Overwrite characters starting at char number 12

    fputs(" Files  ", pFile);

    printf("Success Writing to File\n");

    // Move back to the beginning of the file

    fseek(pFile, 0, SEEK_SET);

    // 2 : Move to the end of the file

    fseek(pFile, 0, SEEK_END);

    // ftell() tells you how far you are currently from the
    // beginning of the file

    long numberOfBytes = ftell(pFile);

    printf("Number of Bytes in File : %d\n", numberOfBytes);

    // 3 : This moves backwards 20 bytes in the file

    fseek(pFile, -20, SEEK_CUR);

    while (fgets(buffer, 1000, pFile) != NULL)
    {

        printf("%s", buffer);
    }

    printf("\n");

    // Closes the text file
    // This must be done or eventually the program will run
    // out of file handlers or memory

    if (fclose(pFile) != 0)
        printf("Error : File Not Closed\n");

    return 0;
}