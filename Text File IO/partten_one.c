#include <stdio.h>
#include <stdlib.h>

// C provides numerous methods for working with files
// A file is just a block of memory with a name
// The file can be stored across many blocks in memory,
// but the C compiler acts as if it is in sequence.

// In this tutorial I will cover how to work with files
// if we represent them as text files. next time I'll cover how
// to use Binary File I/O

/*
int main(void){

	int randomNumber;
	
	// Will store the pointer to the file
	
	FILE *pFile;
	
	// Opens a text file so we can write data to it.
	// It returns a pointer to the file
	// w - If a file doesn't exist create it. If it does overwrite it
	// a - Open or create text file and append to original content
	// r - Open a file to read from it
	// r+ - Open for reading and writing
	// w+ - Open or create, delete original and read and write
	// a+ - Open or create, append for writing and reading
	
	pFile = fopen("randomnumbers.txt", "w");
	
	// If the file wasn't opened a NULL is returned from fopen()
	
	if(!pFile){
	
		printf("Error : Couldn't Write to File\n");
		
		return 1;
	
	}
	
	// Print 10 random numbers to the file
	
	for(int i = 0; i < 10; i++){
	
		randomNumber = rand() % 100;
		
		// fprintf() prints to the file supplied just like
		// printf() prints to the screen
		
		fprintf(pFile, "%d\n", randomNumber);
	
	}
	
	printf("Success Writing to File\n");
	
	// Closes the text file
	// This must be done or eventually the program will run 
	// out of file handlers or memory
	

	if(fclose(pFile) != 0)
		printf("Error : File Not Closed\n");

	return 0;
}
*/

int main(void)
{

    // Defining that we only expect there to be a maximum of 1,000
    // characters per lines read.

    char buffer[1000];

    FILE *pFile;

    // Opens the file for reading

    pFile = fopen("randomnumbers.txt", "r");

    // fopen returns NULL if an error occurred

    if (!pFile)
    {

        printf("Error : Couldn't Read the File\n");

        return 1;
    }

    // fgets() reads up to 1,000 characters per line until
    // fgets() returns the value of NULL when it reaches
    // the end of the file.

    // while(fgets(buffer, 1000, pFile) != NULL){

    //	printf("%s", buffer);

    // }

    // You can also read from a file using fscanf
    // You pass the file, data type to read and the buffer
    // to store it in. You can check for valid data because
    // fscanf() returns a number other then 1 if it isn't
    // a string

    while (fscanf(pFile, "%s", buffer) == 1)
    {

        // Puts outputs the string plus a newline.
        // Returns a nonnegative integer if it was successful
        // and EOF if there was an error

        puts(buffer);
    }

    printf("Success Reading from File\n");

    // Closes the text file

    if (fclose(pFile) != 0)
        printf("Error : File Not Closed\n");

    return 0;
}