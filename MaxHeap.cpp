#include "MaxHeap.h"


//This function fixes the heap if it is valid except maybe its root 
void MaxHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left].pair.priority > data[node].pair.priority))
	{
		max = left;
	}
	else
	{
		max = node;
	}
	if ((right < heapSize) && (data[right].pair.priority > data[max].pair.priority))
	{
		max = right;
	}
	if (max != node)
	{
		Swap(data[node], data[max]);
		FixHeap(max);
	}
}

//This function inserts new Pair to the MaxHeap
void MaxHeap::Insert(Item* newItem)
{
	if (heapSize == maxSize)
	{
		cout << "wrong input";
		exit(1);
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].pair.priority < newItem->pair.priority))
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = *newItem;

}

