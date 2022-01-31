#pragma once
#include "HeapsADT.h"

//Constractor
HeapsADT::HeapsADT(int n)
{
	maxSize = n;
}

//This function returns the maximum Pair in the HeapsADT
Pair HeapsADT::Max()
{
	if (heapSize == 1)
		return maxSmaller.root().pair;
	else
	return maxBigger.root().pair;
}

//This function returns the maximum Pair in the HeapsADT and deletes it
Pair HeapsADT::DeleteMax()
{
	Item temp;
	if (heapSize < 1)
	{
		cout << "wrong input";
		exit(1);
	}
	else if (heapSize == 1)
	{
		//Delete from maxSmaller
		temp = *(maxSmaller.DeleteRoot());
		//Delete from minSmaller
		minSmaller.DeleteRoot();
	}
	else
	{
		//Delete from maxBigger
		temp = *(maxBigger.DeleteRoot());

		//Delete from minBigger
		minBigger.deleteFromHeap(temp.pointer);

		//heapSize is odd => number of items in smaller heaps is 1 more than the number of items in the bigger heaps 
		if (heapSize % 2 == 1)
		{
			//remove the bigger item in the smaller heaps to the bigger heaps
			Item* maxSmall = maxSmaller.DeleteRoot();
			maxBigger.Insert(maxSmall);
			minBigger.Insert(maxSmall);
			minSmaller.deleteFromHeap(maxSmall->pointer);
		}

	}
	heapSize--;

	return temp.pair;
}

//This function returns the minimum Pair in the HeapsADT
Pair HeapsADT::Min()
{
	return minSmaller.root().pair;
}

//This function returns the minimum Pair in the HeapsADT and deletes it
Pair HeapsADT::DeleteMin()
{
	Item temp;
	if (heapSize < 1)
	{
		cout << "wrong input";
		exit(1);
	}
	else if (heapSize == 1)
	{
		//Delete from maxSmaller
		temp = *(minSmaller.DeleteRoot());
		//Delete from minSmaller
		maxSmaller.DeleteRoot();
	}
	else
	{
		//Delete from maxSmaller
		temp = *(minSmaller.DeleteRoot());
		//Delete from minSmaller
		maxSmaller.DeleteRoot();

		//heapSize is even => same items in bigger heaps and smaller heaps
		if (heapSize % 2 == 0)
		{
			//Remove the smaller item in the bigger heaps to the smaller heaps
			Item* minBig = minBigger.DeleteRoot();
			maxSmaller.Insert(minBig);
			minSmaller.Insert(minBig);
			maxBigger.deleteFromHeap(minBig->pointer);
		}

	}

	heapSize--;

	return temp.pair;
}

//This function creates new HeapsADT
void HeapsADT::CreateEmpty()
{
	maxBigger.CreateHeap(maxSize / 2);
	minBigger.CreateHeap(maxSize / 2);

	maxSmaller.CreateHeap((maxSize / 2) + 1);
	minSmaller.CreateHeap((maxSize / 2) + 1);

}

//This function inserts new Pair to the HeapsADT
void HeapsADT::Insert(int priority, string val)
{
	Item* newItem1 = new Item;
	newItem1->pair.priority = priority;
	newItem1->pair.val = val;
		
	Item* newItem2 = new Item;
	*newItem2 = *newItem1;

	newItem1->pointer = newItem2;
	newItem2->pointer = newItem1;


	//First insert
	if (heapSize == 0)
	{
		minSmaller.Insert(newItem1);
		maxSmaller.Insert(newItem2);
	}

	else
	{
		//heapSize is even => same items in bigger heaps and smaller heaps
		if (heapSize % 2 == 0)
		{
			//The new item belongs to the bigger heaps
			if (priority > minBigger.root().pair.priority)
			{
				//Remove the smaller item in the bigger heaps to the smaller heaps
				Item* minBig = minBigger.DeleteRoot();
				maxSmaller.Insert(minBig);
				minSmaller.Insert(minBig);
				maxBigger.deleteFromHeap(minBig->pointer);

				maxBigger.Insert(newItem1);
				minBigger.Insert(newItem2);
			}

			//The new item belongs to the smaller heaps
			else
			{
				maxSmaller.Insert(newItem1);
				minSmaller.Insert(newItem2);
			}
		}
		//heapSize is odd => number of items in smaller heaps is 1 more than the number of items in the bigger heaps
		else
		{
			//The new item belongs to the smaller heaps
			if (priority < maxSmaller.root().pair.priority)
			{
				//remove the bigger item in the smaller heaps to the bigger heaps
				Item* maxSmall = maxSmaller.DeleteRoot();
				maxBigger.Insert(maxSmall);
				minBigger.Insert(maxSmall);
				minSmaller.deleteFromHeap(maxSmall->pointer);

				maxSmaller.Insert(newItem1);
				minSmaller.Insert(newItem2);

			}

			//The new item belongs to the bigger heaps
			else
			{
				maxBigger.Insert(newItem1);
				minBigger.Insert(newItem2);
			}

		}

	}

	heapSize++;

}

//This function returns the median Pair
Pair HeapsADT::Median()
{
	return maxSmaller.root().pair;
}



