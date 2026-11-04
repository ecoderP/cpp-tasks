// Written By Paul Onyebuchi
// Title: M09 Lab - C++ POINTERS A
// Description: This project uses pointers to dynamically allocate an array of user-defined test scores, 
				// sorts the scores in ascending order and calculate the average test score.

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double* arrSelectionSort( double *, int);
double calcAverageScore(double *, int);

int main()
{
	// variables
	int numTestScores{}; // This defines the size of our test scoores array
	
	double	*testScores = nullptr, // A pointer to user entered array
		*sortedScores = nullptr, // pointer to the sorted array

		averageScore = 0.0;  // Variable to hold calculated average score
	
	// Ask user to enter number of test scores
	cout << "How many test scores do you want to input? ";
	cin >> numTestScores;

	// Validating user input
	while (cin.fail() || numTestScores <= 0) // If user enters an ivalid input like a char or numbers with spaces, or user types zero
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid. ";
		}
		cout << "Number of test scores must be greater than zero. Please re-enter a valid number: ";
		cin >> numTestScores;
	}
	
	

	// Dynamically allocating an array large enough to hold user-typed array content
	testScores = new double[numTestScores];
	 
	// Receive array values from user
	cout << "Enter test scores below." << endl;

	for (int i = 0; i < numTestScores; i++)
	{
		cout << "Enter test score number " << (i + 1) << ": ";
		cin >> testScores[i];

		// Validating user input
		while (cin.fail() || testScores[i] < 0) // If user enters an ivalid input like a char or numbers with spaces, or user enters negative number
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid. ";
			}
			cout << "Test scores must be greater than or equal to zero. Please re-enter a valid number ";
			cout << "for test score number " << (i + 1) << ": ";
			cin >> *(testScores + i);
		}
	}

	// Call ta selection sort function to sort the array in ascending order and return a pointer to the sorted array

	sortedScores = arrSelectionSort(testScores, numTestScores);

	// Calling the function that calculates average score
	averageScore = calcAverageScore(testScores, numTestScores);

	// Display sorted list of scores
	cout << "======================================================" << endl;
	cout << "List of scores sorted in ascending order" << endl;
	cout << "======================================================" << endl;
	for (int i = 0; i < numTestScores; i++)
	{
		cout << *(sortedScores + i) << " ";
	}
	cout << endl << endl;;

	// Display average score
	cout << "======================================================" << endl;
	cout << "Average test score" << endl;
	cout << "======================================================" << endl;
	cout << fixed << setprecision(1); // For output to show exactly 1 decimal place
	cout << averageScore << endl;


	

	// Cleaning up dynamically alocated memory
	// Delete pointers and assign null value
	delete [] testScores;
	testScores = nullptr;

	return 0;
}


// Function definitions 
// for the selection sort function
double* arrSelectionSort(double* arr, int size)
{
	int minIndex; // index of the minimum value in the array

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;

		for (int index = start + 1; index < size; index++)
		{
			if (arr[index] < arr[minIndex])
			{
				minIndex = index;

			}
		}

		// start the smallest value in unsorted section of the array with the current start element
		swap(arr[minIndex], arr[start]);
	}

	return arr;
}

// Function definition for calculating average score
double calcAverageScore(double* arr, int size)
{
	double average,  // To hold the average
		total = 0.0; // to hold running total

	// loop through the array and add values to running total
	for (int i = 0; i < size; i++)
	{
		total += *(arr +i);
	}

	// Calculate average
	average = total / static_cast<double>(size);

	return average;
}
