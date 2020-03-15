#include <stdio.h>
#include <stdlib.h>

void generateTwoRandomNums(int rand1, int rand2);

// Improved pointerRandomNumbers()
// If an argument is a pointer put a * after the datatype

void pointerRandomNumbers(int *rand1, int *rand2);

// We refer to the array just like any other array

void editMessageSent(char *message, int size);

int main(void)
{

       int rand1 = 0, rand2 = 0;

       generateTwoRandomNums(rand1, rand2);

       // Why does the following not print the updated values?
       // Because the variable wasn't sent, but instead the value
       // stored in that variable was sent and then stored in
       // the 2 new variables in the function named
       // int rand1, int rand2

       printf("rand1 = %d\n\n", rand1);
       printf("rand2 = %d\n\n", rand2);

       // Why not have everything set as a global variable?
       // 1. Naming conflicts when using other functions
       // 2. It can be hard to figure out where changes are coming from
       // 3. It eliminates flexibility because you don't know if a
       // change will effect another function

       // Solving the problem with pointers

       rand1 = 0, rand2 = 0;

       printf("Main Before Function Call\n\n");

       printf("rand1 = %d : rand2 = %d\n\n", rand1, rand2);

       // To pass the address for the variable in memory use &
       // You already did this above scanf(" %d", &whatToDo);

       pointerRandomNumbers(&rand1, &rand2);

       printf("Main After Function Call\n\n");

       printf("rand1 = %d : rand2 = %d\n\n", rand1, rand2);

       // Passing a String to a Function ----

       char randomMessage[] = "Edit my function";

       printf("Old Message: %s \n\n",
              randomMessage);

       editMessageSent(randomMessage,
                       sizeof(randomMessage));

       printf("New Message: %s \n\n",
              randomMessage);
}

void generateTwoRandomNums(int rand1, int rand2)
{

       // Generates a random number from 1 to 50

       rand1 = rand() % 50 + 1;
       rand2 = rand() % 50 + 1;

       printf("New rand1 in function = %d\n\n", rand1);
       printf("New rand2 in function = %d\n\n", rand2);
}

void pointerRandomNumbers(int *rand1, int *rand2)
{

       // You get the address of a variable by putting & in front
       // You access the data at that address by putting * in front

       // Saves these numbers to the space at the address

       *rand1 = rand() % 50 + 1;
       *rand2 = rand() % 50 + 1;

       // You retrieve the value already stored in the address
       // with star once again

       printf("New rand1 in pointer function = %d\n\n", *rand1);
       printf("New rand2 in pointer function = %d\n\n", *rand2);
}

void editMessageSent(char *message, int size)
{

       char newMessage[] = "New Message";

       if (size > sizeof(newMessage))
       {

              for (int i = 0; i < sizeof(newMessage); i++)
              {

                     message[i] = newMessage[i];
              }
       }
       else
       {

              printf("New Message is to big\n\n");
       }
}