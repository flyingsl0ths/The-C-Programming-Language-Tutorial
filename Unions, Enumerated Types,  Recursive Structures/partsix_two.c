#include <stdio.h>

typedef struct product
{

	const char *name;
	float price;

	// Added to make a Recursive Structure
	// product also must be listed above with
	// a Recursive Structure

	struct product *next;

} product;

// Cycles through the Linked List and prints it

void printLinkedList(product *pProduct);

int main(void)
{

	// If you had a bunch of products in your store
	// you could store them in an array, but that
	// limits you because they have a fixed length

	// product theProducts[20];

	// A Linked List however can store an unlimited
	// number of items.
	// It is called a linked List because it contains
	// an item and a link to the next item in a list.

	// Another benefit to a Linked List is that you can
	// insert new items any place in the list.

	// To make a Linked List of Structs requires each
	// Struct to contain a link to the next.
	// (Recursive Structure)

	// I'm creating the products and setting each
	// next to null

	product tomato = {"Tomato", .51, NULL};
	product potato = {"Potato", 1.21, NULL};
	product lemon = {"Lemon", 1.69, NULL};
	product milk = {"Milk", 3.09, NULL};
	product turkey = {"Turkey", 1.86, NULL};

	// Now assign a pointer to the value of next

	tomato.next = &potato;
	potato.next = &lemon;
	lemon.next = &milk;
	milk.next = &turkey;

	// What do we do if we want to insert Apples after
	// the lemon?

	product apple = {"Apple", 1.58, NULL};

	// Change the values for next

	lemon.next = &apple;
	apple.next = &milk;

	printLinkedList(&tomato);
}

void printLinkedList(product *pProduct)
{

	// While the value for next isn't NULL
	// which signals the end of the list keep going

	product *temp = pProduct;
	while (temp != NULL)
	{

		// Printing values using (*) and ->

		printf("A %s costs %.2f\n\n",
			   (*temp).name,
			   temp->price);

		// Switch to the next item in the Linked List

		temp = temp->next;
	}
}