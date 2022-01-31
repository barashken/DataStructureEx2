#include "heap.h"


//This function returns the index of node's left child
int heap::Left(int node)
{
	return (2 * node + 1);
}

//This function returns the index of node's right child
int heap::Right(int node)
{
	return (2 * node + 2);
}

//This function returns the index of node's perant
int heap::Parent(int node)
{
	return (node - 1) / 2;
}

//This function creates new MinHeap
void heap::CreateHeap(int size)
{
	data = new Item[size];
	maxSize = size;
	heapSize = 0;
}

//This function returns the root Pair of the heap
Item heap::root()
{
	return data[0];
}

//
void heap::setRoot(Item newRoot)
{
	data[0] = newRoot;
}

//This function returns the root Pair of the heap and deletes it
Item* heap::DeleteRoot()
{
	if (heapSize < 1)
	{
		cout << "wrong input";
		exit(1);
	}

	Item* root = &data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return(root);
}

//This function deletes the itemToDelete from the heap
void heap::deleteFromHeap(Item* itemToDelete)
{
	/*itemToDelete->pair.priority = data[heapSize].pair.priority;
	itemToDelete->pair.val.swap(data[heapSize].pair.val);
	itemToDelete->pointer = data[heapSize].pointer;*/

	heapSize--;
	itemToDelete = &data[heapSize];

}

//Distractor
heap::~heap()
{
	delete[] data;
	data = nullptr;
}
