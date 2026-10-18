// Written By Paul Onyebuchi
// Title: CPP Search Algorithms
// Description: This project demonstrates the implementation of Linear and Binary Search Algorithms

#include <iostream>
using namespace std;

// Global constant
const int ARRAY_SIZE = 25;

// Function prototypes
void linearSearch(const int [], int, int);
void binarySearch(const int [], int, int);


int main()
{
//variables:
	int searchValue = 507; // The item being searched for


	int numbers[ARRAY_SIZE] = { 12, 16, 17, 23, 25, 
								45, 48, 52, 54, 57, 
								63, 76, 79, 81, 85, 
								87, 90, 99, 101, 103, 
								104, 111, 123, 187, 200 
								};

	// Call Linear search function
	cout << "====================" << endl;
	cout << "Linear search algorithm result\n";
	cout << "====================" << endl;

	linearSearch(numbers, ARRAY_SIZE, searchValue);

	cout << "\n\n\n";  // 3 lines of space

	// Call Binary search function
	cout << "====================" << endl;
	cout << "Binary search algorithm result\n";
	cout << "====================" << endl;
	
	binarySearch(numbers, ARRAY_SIZE, searchValue);
	

	return 0;
}

// Linear Search function
void linearSearch(const int arr[], int arrSize, int value)
{
	// local variables
	int index = 0,
		count = 0;

	bool found = false;

	while (!found && index < arrSize)
	{

		if (arr[index] == value)  // If search item is found
		{
			found = true;
			count = index + 1;  // Add one to index because we started from index = 0
			cout << "Item found after: " << count << " iterations" << endl;
		}

		index++;
	}

	if (!found)  // If search item is not found
		cout << "Not found after: " << index << " iteartions" << endl;
}


// Binary Search Function
void binarySearch(const int arr[], int arrSize, int value)
{
	// local variables
	int count = 0,
		first = 0,
		middle = 0,
		last = arrSize - 1;

	bool found = false;

	while (!found && first <= last)
	{
		count++;
		middle = (first + last) / 2;

		if (arr[middle] == value)  // If item is found
		{
			found = true;
			cout << "Item found after: " << count << " iterations." << endl;
		}
		else if (arr[middle] < value)
			first = middle + 1;
		else
			last = middle - 1;
	}

	if (!found)  // If item is not found
		cout << "Not found after: " << count << " iterations" << endl;
}