#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "definitions.h"
#include "heap.h"


class MaxHeap : public heap
{
private:

	void FixHeap(int node);


public:
	MaxHeap() { }

	void Insert(Item* newItem); 

};



#endif