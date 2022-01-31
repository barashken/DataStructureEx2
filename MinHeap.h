#ifndef MINHEAP_H
#define MINHEAP_H

#include "definitions.h"
#include "heap.h"


class MinHeap : public heap
{
private:

	void FixHeap(int node);


public:
	MinHeap() { }

	void Insert(Item* newItem); 

};

#endif