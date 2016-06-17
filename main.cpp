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
	list<int> listEven;
	list<int> listOdd;

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

		//If even, add to listEven
		if (temp % 2 == 0)
		{
			listEven.push_back(temp);
		}
		else
		{
			listOdd.push_back(temp);
		}
	}

	splice(original.begin(), listOdd);
	splice(original.begin(), listEven);

	// End program
	system("PAUSE");
	exit(1);
}