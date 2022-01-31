#pragma once
#include "HeapsADT.h"
#include <string>

int main()
{
	int n;
	cin >> n;
	
	HeapsADT heaps(n);

	char let, a;
	cin >> let;

	if (let != 'e')
	{
		cout << "wrong input";
		exit(1);
	}
	heaps.CreateEmpty();


	int priority;
	string val; 
	Pair temp;

	for (int i = 1; i < n; i++)
	{
		cin >> let;
		
		switch (let)
		{
		case 'a':
			temp = heaps.Max();
			cout << temp.priority << " ";
			cout << temp.val << endl;
			break;

		case 'b':
			temp = heaps.DeleteMax();
			cout << temp.priority << " ";
			cout << temp.val << endl;
			break;

		case 'c':
			temp = heaps.Min();
			cout << temp.priority << " ";
			cout << temp.val << endl;
			break;

		case 'd':
			temp = heaps.DeleteMin();
			cout << temp.priority << " ";
			cout << temp.val << endl;
			break;

		case 'f':
			cin >> priority;
			cin.get(a);
			std::getline(cin, val);
			//val.erase(0, 1);
			heaps.Insert(priority, val);
			break;

		case 'g':
			temp = heaps.Median();
			cout << temp.priority << " ";
			cout << temp.val << endl;
			break;

		default:
			cout << "wrong input";
			exit(1);
			break;
		}
	}
	
	if (!cin.eof())
	{
		cout << "wrong input";
		exit(1);
	}

}
