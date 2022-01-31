#pragma once

#ifndef HEAPSADT_H
#define HEAPSADT_H

#include "MaxHeap.h"
#include "MinHeap.h"

class HeapsADT
{
private:

	int maxSize;
	int heapSize = 0;
	MaxHeap maxBigger;
	MaxHeap maxSmaller;
	MinHeap minBigger;
	MinHeap minSmaller;


public:

	HeapsADT(int n);

	Pair Max();
	Pair DeleteMax(); 
	Pair Min(); 
	Pair DeleteMin(); 
	void CreateEmpty(); 
	void Insert(int priority, string val); 
	Pair Median(); 

};




#endif