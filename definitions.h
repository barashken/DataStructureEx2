#pragma once

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <iostream>
#include <string.h>

using namespace std;

using std::string;
using std::cout;
using std::cin;


//Pair 
typedef struct
{
	int priority;
	string val;
}Pair;

//Heap's item
typedef struct _Item
{
	Pair pair;
	struct _Item* pointer;
}Item;


//This function swap between 2 items
void Swap(Item& a, Item& b);

#endif 