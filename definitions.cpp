#include "definitions.h"

//This function swaps between 2 items
void Swap(Item& a, Item& b)
{
	Item temp;
	temp = a;
	a = b;
	b = temp;
}