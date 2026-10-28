// Written By Paul Onyebuchi
// Title: M08 Lab - CPP Sort Algorithms
// Description: This project demonstrates the implementation of Bubble Sort, & Selection Sort Algorithms

#include <iostream>
using namespace std;

// Glocal constants
const int ARRAY_SIZE = 8;

// Function prototypes
void bubbleSort(int [], int);
void selectionSort(int[], int);
void displayArray(int [], int);

int main()
{
	// Arrays
	int array1[ARRAY_SIZE] = { 12, 14, 5, 7, 3, 2, 20, 4 },
		array2[ARRAY_SIZE] = { 30, 28, 21, 25, 27, 22, 29, 23 };

	// Display contents of first array
	cout << "First Array Contents: " << endl;
	cout << "-----------------------" << endl;
	displayArray(array1, ARRAY_SIZE);


	// Call Bubble sort to sort array in ascending order
	bubbleSort(array1, ARRAY_SIZE);

	// Display contents of Second array
	cout << "Second Array Contents: " << endl;
	cout << "-----------------------" << endl;
	displayArray(array2, ARRAY_SIZE);

	// Call Selection sort to sort array in ascending order
	selectionSort(array2, ARRAY_SIZE);

	return 0;
}



// Functions
// Bubble sort in ascending order
void bubbleSort(int arr[], const int size)
{
	int	maxElement;

	cout << "=================================================" << endl;
	cout << "Bubble sort algorithm Sorted array contents" << endl;
	cout << "=================================================" << endl;

	for (maxElement = (size - 1); maxElement > 0; maxElement--)
	{
		for (int index = 0; index < maxElement; index++)
		{
			if (arr[index] > arr[index + 1])
			{
				swap(arr[index], arr[index + 1]); // swap the current element with the next one

				// Display the array contents
				displayArray(arr, size);
			}
		}
	}
}


// Selection sort in ascending order
void selectionSort(int arr[], int size)
{
	int minIndex, // index of the minimum value in the array
		minValue; // Minimun value in the array

	cout << "=================================================" << endl;
	cout << "Selection sort algorithm Sorted array contents" << endl;
	cout << "=================================================" << endl;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = arr[start];

		for (int index = start + 1; index < size; index++)
		{
			if (arr[index] < minValue)
			{
				minValue = arr[index];
				minIndex = index;

			}
		}

		// start the smallest value in unsorted section of the array with the current start element
		swap(arr[minIndex], arr[start]); 
		// Display the array contents
		displayArray(arr, size);
	}
}


// Display function
void displayArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "   ";
	cout << endl << endl;
}