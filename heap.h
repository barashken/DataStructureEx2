#ifndef HEAP_H
#define HEAP_H

#include "definitions.h"


class heap
{
protected:

	Item* data;
	int maxSize;
	int heapSize;

	virtual int Left(int node);
	virtual int Right(int node);
	virtual int Parent(int node);

	virtual void FixHeap(int node) = 0;


public:
	heap() { data = nullptr, maxSize = 0, heapSize = 0; }

	virtual void CreateHeap(int size);
	virtual Item root();
	virtual void setRoot(Item newRoot);
	virtual Item* DeleteRoot();
	virtual void Insert(Item* newItem) = 0;
	virtual void deleteFromHeap(Item* itemToDelete); 

	~heap();
};


#endif