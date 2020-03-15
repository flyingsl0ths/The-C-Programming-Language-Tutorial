#include <stdio.h>

// Needed for exit()
#include <stdlib.h>

int main(void)
{

	int whatToDo = 0;

	do
	{
		printf("\n");
		printf("1. What Time is It?\n");
		printf("2. What is Todays Date?\n");
		printf("3. What Day is It?\n");
		printf("4. Quit\n");

		scanf(" %d", &whatToDo);
	} while (whatToDo < 1 || whatToDo > 4);

	// How to handle the input with if

	if (whatToDo == 1)
	{

		printf("Print the time\n");
	}
	else if (whatToDo == 2)
	{

		printf("Print the date\n");
	}
	else if (whatToDo == 3)
	{

		printf("Print the day\n");
	}
	else
	{

		printf("Bye Bye\n");

		// Exit the program with a non error state
		// Almost always better to use return

		exit(0);
	}

	printf("\n");

	// How to handle the input with switch
	// Switch checks the value provided and executes
	// accordingly. (Value must be char or int)
	// break is used to stop checking input against the
	// other options. Without break other options would
	// be checked

	switch (whatToDo)
	{

	case (1):
		printf("Print the time\n");
		break;

	case (2):
		printf("Print the date\n");
		break;

	case (3):
		printf("Print the day\n");
		break;

	default:
		printf("Bye Bye\n");
		exit(0);
		break;
	}
}