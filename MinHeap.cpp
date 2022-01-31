#include "MinHeap.h"


//This function fixes the heap if it is valid except maybe its root 
void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left].pair.priority < data[node].pair.priority))
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if ((right < heapSize) && (data[right].pair.priority < data[min].pair.priority))
	{
		min = right;
	}
	if (min != node)
	{
		Swap(data[node], data[min]);
		FixHeap(min);
	}
}

//This function inserts new Pair to the MinHeap
void MinHeap::Insert(Item* newItem)
{
	if (heapSize == maxSize)
	{
		cout << "wrong input";
		exit(1);
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].pair.priority > newItem->pair.priority))
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = *newItem; 
	
}

