// Written By Paul Onyebuchi
// ID: W2245353
// Title: M05 LAB - ROCK, PAPER, SCISSORS GAME
// Description: This program lets the user play Rock, Paper, Scissors against the computer.

#include <iostream>
#include <string>
#include <random>

using namespace std;

// Global constants
const int ROCK_CHOICE = 1,
	PAPER_CHOICE = 2,
	SCISSORS_CHOICE = 3;

const string ROCK = "ROCK",
	PAPER = "PAPER",
	SCISSORS = "SCISSORS";

// Function prototypes
string getComputerChoice(),
	getUserChoice();
void winnerSelection(string, string);

int main()
{
	// variables
	string computerChoice{},
		userChoice{};

	cout << "==============================" << endl;
	cout << "Play Against Computer. \n"; 
	cout << "Rock, Paper, Scissors." << endl;
	cout << "________________________________" << endl;

	// Loop for replay when there is a tie
	do
	{
		// computer generates random number
		computerChoice = getComputerChoice();

		// Get user choice
		userChoice = getUserChoice();

		// Display computer's choice
		cout << "Computer chose " << computerChoice << endl;

		// Winner selection
		winnerSelection(computerChoice, userChoice);

	} while (computerChoice == userChoice);

	cout << "==============================" << endl;


	return 0;
}

// Function statements
string getComputerChoice()
{
	// local variable
	int num{};

	// Random number engine
	random_device engine;
	// Distribution object
	uniform_int_distribution<int> randNum(ROCK_CHOICE, SCISSORS_CHOICE);
	num = randNum(engine);

	// Dynamically assign compChoice values based on randNum
	if (num == ROCK_CHOICE)
		return ROCK;
	else if (num == PAPER_CHOICE)
		return PAPER;
	else
		return SCISSORS;
}

// User Choice function
string getUserChoice()
{
	char userChar{};

	// Infinite loop to run until user enters a valid selection
	// I choose an infinite loop over a recursive function to avoid memory overload from
	// too many ivalid user inputs
	while (true)
	{
		cout << "To make your choice, enter R for Rock, P for Paper or S for Scissors: ";
		cin >> userChar;
		// Dynamically return the user selection
		switch (userChar)
		{
		case 'R':
		case 'r':
			return ROCK;
		case 'P':
		case 'p':
			return PAPER;
		case 'S':
		case 's':
			return SCISSORS;
		default:
		{
			cout << "You have entered an invalid selection. Please try again" << endl;
			// Ignore any left-over characters in the buffer if the user enters multiple characters or a word
			// SInce cin takes in a char datatype,it causes multiple iterations of the loop for additional characters from the buffer
			cin.ignore(20, '\n');
			break;
		}
		}
	}
}

// Winner selection function statement
void winnerSelection(string choice1, string choice2)
{
	if ((choice1 == ROCK && choice2 == SCISSORS) || (choice1 == SCISSORS && choice2 == ROCK))
	{
		cout << "The Rock smashes the Scissors." << endl;
		if (choice1 == ROCK)   // Check who won
			cout << "Computer Wins." << endl;
		else
			cout << "You Win!" << endl;
	}
		
	else if ((choice1 == SCISSORS && choice2 == PAPER) || (choice1 == PAPER && choice2 == SCISSORS))
	{
		cout << "Scissors cuts Paper." << endl;
		if (choice1 == SCISSORS)  // Check who won
			cout << "Computer Wins!" << endl;
		else
			cout << "You Win!" << endl;
	}
		
	else if ((choice1 == PAPER && choice2 == ROCK) || (choice1 == ROCK && choice2 == PAPER))
	{
		cout << "Paper wraps Rock." << endl;
		if (choice1 == PAPER)   // Check who won
			cout << "Computer Wins!" << endl;
		else
			cout << "You Win!" << endl;
	}	
	else
		cout << "It's a tie. Play again." << endl;

}