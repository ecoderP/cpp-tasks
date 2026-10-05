// Written By Paul Onyebuchi
// ID: W2245353
// Title: M06 LAB - TIC-TAC-TOE GAME
// Description: This program two players play a game of tic-tac-toe.

#include <iostream>
using namespace std;


// Global constants
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

const int ROWS = 3;
const int COLS = 3;

// function prototypes
void displayBoard(char [][3]);
bool playerWon(const char [][3], char);
bool checkForTie(const char [][3]);

int main()
{
	cout << "=======================\n\n";
	cout << "TIC-TAC-TOE GAME!\n";
	cout << "Player 1 is X\n";
	cout << "Player 2 is O\n\n";
	cout << "=======================\n";


	// variables
	char board[ROWS][COLS] = { {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} };

	bool gameOn = true;
	char currentPlayer{PLAYER1};
	short pRow{}, pCol{};


	// PROCESS:
	//-while gameOn, start game
	while (gameOn) {
		//- Display board and players
		displayBoard(board);

		//- Display current player
		cout << "\n";  // For proper spacing below game board
		cout << "It's " << currentPlayer << "'s turn to play now.\n\n";
		
		// Ask current player for input pRow and pCol
		cout << "Enter two number between 1 and 3 separated by a single space. \n";
		cout << "First number is the row and second number would be the column of your choice: ";
		cin >> pRow >> pCol;
		
		//- validate input.
		//- If user types letters, a large chunk of text or numbers outside the specified range
		if (cin.fail() || (pRow < 1 || pRow > 3) || (pCol < 1 || pCol > 3))
		{
			cin.clear(); // to clear error flags if user types in texts
			cin.ignore(1000, '\n');
			cout << "Invalid choice! Pick two numbers between from 1 to 3 separating by a single space.";
			continue;
		}
		
		pRow--;
		pCol--; // To match array element positions: 0, 1, 2

		
		// check if chosen cell is taken
		if (board[pRow][pCol] == '*') // if cell is not taken
		{
			// -update board and display it;
			board[pRow][pCol] = currentPlayer;
			displayBoard(board);
			//-check if currentPlayer won - end game if player won
			if (playerWon(board, currentPlayer))
			{
				cout << currentPlayer << " won. \n";
				cout << "CONGRATULATIONS " << currentPlayer << "\n";
				gameOn = false;
			}
			else if (checkForTie(board))
			{
				//- check if there are empty arrays elements
				//- if there are no empty array elements, it is a tie, end game
				cout << "It's a tie.";
				gameOn = false;

			}
			else
			{
				//- else update currentPlayer
				if (currentPlayer == PLAYER1)
					currentPlayer = PLAYER2;
				else
					currentPlayer = PLAYER1;

			}
			continue;
			
		}
		else
		{ 
			// inform player that cell is not open
			cout << "That spot is taken. Try again.";
		}
		
		
	}
		

	return 0;
}


// Function statements
void displayBoard(char board[3][3])
{
	cout << "\n";
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";


}

// Function to check if player won
bool playerWon(const char arr[3][3], char player)
{
	// possible wins are: Rows - 00,01 & 02 | 10,11 & 12 | 20,21 & 22
	// Columns - 				00,10 & 20 | 01,11 & 21 | 02,12 & 22
	// Diagonals - 			00, 11, 22 | 02, 11, 20

	if (((arr[0][2] == player) && (arr[1][1] == player) && (arr[2][0] == player)) ||
		((arr[0][0] == player) && (arr[1][1] == player) && (arr[2][2] == player))
		) // for one of the diagonals
		return true;
	else
	{
		for (short num{}; num <= 2; num++)
		{
			if (((arr[0][num] == player) && (arr[1][num] == player) && (arr[2][num] == player)) ||
				((arr[num][0] == player) && (arr[num][1] == player) && (arr[num][2] == player))
				)  // other possible cases
				return true;
		}
	}

	return false;
	
}

// Function to check for empty array cells
bool checkForTie(const char arr[][3])
{
	for (int row{}; row <= 2; row++)
	{
		for (int col{}; col <= 2; col++)
		{
			if (arr[row][col] == '*')
				return false;
		}
	}
		
	return true;
}


