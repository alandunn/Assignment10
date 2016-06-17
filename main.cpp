#include <iostream>
#include <list>
#include <array>

using namespace std;

void printList(list<int>& originalList );

int main()
{
	int largest;

	array<int, 16> data{81, 5, 20, 33, 15, 699, 7, 12, 0, 66, 43, 72, 90, 400, 350, 1};

	list<int> original;
	list<int> list0;
	list<int> list1;

	cout << "Nathanael Meyers and Alan Dunn" << endl;
	cout << "CS 2420" << endl;
	cout << "Assignment 10" << endl << endl;

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
	while (original.empty() == false)
	{
		int temp = original.front();
		original.pop_front();

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
	original.splice(original.begin(), list1);
	original.splice(original.begin(), list0);	
	
	cout << "Sorted by even and odd: ";
	
	printList(original);
	
	cout <<endl << "---------------------------------------------------------------------------"<< endl;
	
	//Split and splice based on the boolean expression ((n/X) % 2 == 0).
	//n = the number from the list, X starts at 2 and doubles each loop and 
	//stops when the divisor (X) is larger then the largest number in the list
	
	//Start divisor at 2
	int divisor = 2;
	
	while(divisor < largest)
	{
		while (original.empty() == false)
		{
			int temp = original.front();
			original.pop_front();
			
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
		original.splice(original.begin(), list1);
		original.splice(original.begin(), list0);
		
		cout << "List after being split and spliced by the divisor: " << divisor << endl;
		printList(original);
		cout <<endl << "---------------------------------------------------------------------------"<< endl;

		
		// Double the divisor
		divisor = divisor * 2;
	}
	
	//Print out finished organized list
	cout << "The organized list is: ";
	
	printList(original);
	
	cout << endl << endl;
	
	
	// End program
	system("PAUSE");
	exit(1);
}

void printList(list<int>& originalList )
{
	for (list<int>::const_iterator it = originalList.begin(); it != originalList.end(); ++it)
	{
		if(it == originalList.end())
		{
			cout << *it;
		}
		else
		{
    		cout << *it << "  ";
		}
	}
}
