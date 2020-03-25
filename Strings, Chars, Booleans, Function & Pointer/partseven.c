#include <stdio.h>

// Needed if you want to use bool
#include <stdbool.h>

#include <string.h>

#include <ctype.h>

// Used to remove a newline

void noMoreNewline(char *theString)
{

    char *isANewline;

    // strchr() returns a pointer to the first location
    // of the character provided
    // strrchr() returns the last occurance

    isANewline = strrchr(theString, '\n');

    if (isANewline)
    {

        *isANewline = '\0';
    }
}

// Used to make all letters lowercase

void makeLowercase(char *theString)
{

    int i = 0;

    while (theString[i])
    {

        // tolower() converts char to lowercase
        // toupper() does the opposite

        theString[i] = tolower(theString[i]);

        i++;
    }
}

void getCharInfo()
{

    char theChar;

    while ((theChar = getchar()) != '\n')
    {

        printf("Letter or Number %d\n\n", isalnum(theChar));
        printf("Alphabetic Char %d\n\n", isalpha(theChar));
        printf("Standard Blank %d\n\n", isblank(theChar));
        printf("Ctrl Char %d\n\n", iscntrl(theChar));
        printf("Number Char %d\n\n", isdigit(theChar));
        printf("Anything But Space %d\n\n", isgraph(theChar));
        printf("Lowercase %d\n\n", islower(theChar));
        printf("Uppercase %d\n\n", isupper(theChar));
        printf("Anything not a Letter, Number or Space %d\n\n", ispunct(theChar));
        printf("Any Space %d\n\n", isspace(theChar));
    }
}

int main(void)
{
    /* _Bool and bool data type ------
	// _Bool is the C boolean type. It holds either a 1 (true)
	// or a 0 (false)

	_Bool isANumber;
	
	// If #include <stdbool.h> is above you can use bool here
	// It defines true as a constant for 1 and false for 0
	
	int number;
	int sumOfNumbers;
	
	printf("Enter a number: ");
	
	// Checks if data matching the format specifier was entered
	// (0-9) with a + or minus. If true a 1 is returned
	
	isANumber = (scanf("%d", &number) == 1);
	
	// When they enter data that doesn't match the format specifier
	// %d the loop ends
	
	while(isANumber){
	
		sumOfNumbers = sumOfNumbers + number;
		
		printf("Enter another number: ");
	
		isANumber = (scanf("%d", &number) == 1);
	
	}
	
	printf("The Sum is %d\n\n", sumOfNumbers);
	
	*/

    /* Demonstrate getchar, putchar and buffering
	
	char theChar;
	
	// With this compiler getchar() will wait until the enter
	// button is pressed and then push everything to the screen.
	
	// The data is stored in a buffer as it is entered. The buffer
	// is a temporary storage area in memory. The size of the buffer
	// depends on the system. In essence a buffer is just a pointer 
	// without a specified size. This is an example of line
	// buffering because the buffer ends when a newline is entered.
	
	while ((theChar = getchar()) != '~'){
	
		putchar(theChar);
	
	}
	
	*/

    /* Demonstrate gets(), puts(), fgets(), fputs() 
	
	char name[50];
	
	printf("What is your name? ");
	
	// The gets() function recieves a string from the keyboard
	// until a \n is reached. It then replaces the \n with \0
	// Be careful with gets because it doesn't check if the input
	// fits in the 50 character space. That is why I have been
	// using fgets()
	
	gets(name);
	
	// puts() receives a string and prints it out followed by
	// a new line
	
	puts("Hi");
	puts(name);
	
	printf("What is your name? ");
	
	// fgets() reads till the array limit is reached or till \n
	// It appends a \n to the end of the array
	
	fgets(name, 50, stdin);
	
	// fputs() prints strings without a \n
	
	fputs("Hi ", stdout);
	fputs(name, stdout);
	
	*/

    /*
	// Demonstrate a confusing way to print strings
	
	// Create a string array (pointer to first element in array)
	
	char * randomString = "Just some random stuff";
	
	// while continues until it reaches a null character, which
	// with *randomString is equal to 0
	
	while(*randomString){
	
		// Prints a character in the array and then increments
		// to the next
	
		putchar(*randomString++);
	
	}
	
	puts("\n");
	
	*/

    // The above is the same as
    /*
	
	char * randomString = "Just some random stuff";
	
	int i = 0;
	while(randomString[i] != '\0'){
		putchar(randomString[i++]);
	}
	
	*/

    /* Solving more random problems
	
	char doYouWantToQuit[10];
	
	printf("Enter quit to quit: ");
	
	fgets(doYouWantToQuit, 10, stdin);
	
	// fgets() adds a newline at the end. To get rid of it
	// Deletes the newline from the string
	
	noMoreNewline(doYouWantToQuit);
	
	// Make letters lowercase
	
	makeLowercase(doYouWantToQuit);
	
	// strcmp() returns 0 when the strings are equal
	
	while(strcmp(doYouWantToQuit, "quit")){
	
		printf("Enter quit to quit: ");
	
		fgets(doYouWantToQuit, 10, stdin);
		
		noMoreNewline(doYouWantToQuit);
		
		makeLowercase(doYouWantToQuit);
	
	}
	
	printf("Thank you for typing %s\n\n",doYouWantToQuit);
	
	*/

    // Testing ctype.h Functions

    getCharInfo();
}