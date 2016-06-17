#include <iostream>
#include <list>
#include <array>

#include "radixSort.h"

using namespace std;

int main()
{
	int largest;

	array<int, 7> data{0, 5, 20, 33, 15, 699, 7};

	list<int> original;
	list<int> list0;
	list<int> list1;

	cout << "This program uses radix sorting to organize a list of numbers." << endl;
	cout << "The list of numbers being sorted is: ";

	// Display list of numbers and finds the largest int
	for (int i = 0; i < data.size(); i++)
	{
		if (i == 0)
		{
			largest = i;
			cout << data[i];
		}
		else
		{
			if (data[i] > largest)
			{
				largest = data[i];
			}
			cout << ", " << data[i];
		}
	}
	cout << endl << endl;

	//Push numbers from array into the list
	for (int i = 0; i < data.size(); i++)
	{
		original.push_back(data[i]);
	}

	//Split the list between even and odd
	while (original.empty == false)
	{
		int temp;
		temp = original.pop_front;

		//If even, add to list0
		if (temp % 2 == 0)
		{
			list0.push_back(temp);
		}
		else
		{
			list1.push_back(temp);
		}
	}
	
	
	//NEED TO GET THIS WORKING, CODE PROVIDED BY BOOK, doesn't work.
	splice(original.begin(), list1);
	splice(original.begin(), list0);	
	
	//Split and splice based on the boolean expression ((n/X) % 2 == 0).
	//n = the number from the list, X starts at 2 and doubles each loop and 
	//stops when the divisor (X) is larger then the largest number in the list
	
	//Start divisor at 2
	int divisor = 2;
	
	while(divisor < largest)
	{
		while (original.empty == false)
		{
			int temp;
			temp = original.pop_front;
			
			if ((temp/divisor) % 2 == 0)
			{
				list0.push_back(temp);
			}
			else 
			{
				list1.push_back(temp);
			}	
		}
		
		
		//NEED TO GET THIS WORKING, CODE PROVIDED BY BOOK, doesn't work.
		splice(original.begin(), list1);
		splice(original.begin(), list0);
		
		// Double the divisor
		divisor = divisor * 2;
	}
	
	//Print out finished organized list
	cout << "The organized list is: ";
	
	
	
	// End program
	system("PAUSE");
	exit(1);
}