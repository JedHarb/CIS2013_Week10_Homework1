#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<time.h>
using namespace std;

void boardLegnthNumberPrint(int i) {
	cout << i;
	if (i < 10) {
		cout << " ";
	}
}

void boardLegnthLinePrint(int i) {
	cout << "__";
}

int getRandom(int i)
{
	return rand() % i;
}

//When the application is run...
//* Application asks for a board size in the form on x & y.
//* The application then asks for a number of bombs to plant.
//* Using DYNAMIC ARRAYS the applicaiton prints a "blank board" of that size.
//* The number of bombs is randomly "placed" throughout the board but not displayed.


int main() {


	bool gameOver = false;
	int boardXSize = 0;
	int boardYSize = 0;
	int numbBombs = 0;
	char *boardBombs;
	char *userGuesses;
	int checkBombs = 0;
	int randBoardSpace = 0;
	int xGuess = 0;
	int yGuess = 0;
	int bombChecker = 0;

	srand(time(NULL));

	//get game specifics
	cout << endl << "First, how big of a board do you want to play on?" << endl << "Width: ";
	cin >> boardXSize;
	while (boardXSize > 99 || boardXSize < 1) { //board functions properly anywhere between 1x1 and 99x99. Not bad, eh?
		cout << "Sorry, I can't do that. Choose between 1 and 99, please: ";
		cin >> boardXSize;
	}
	cout << "Legnth: ";
	cin >> boardYSize;
	while (boardYSize > 99 || boardYSize < 1) {
		cout << "Sorry, I can't do that. Choose between 1 and 99, please: ";
		cin >> boardYSize;
	}
	cout << "Okay, your board is a total of " << boardXSize * boardYSize << " spaces. And how many bombs are on this board?: ";
	cin >> numbBombs;
	while (numbBombs > boardXSize * boardYSize) {
		cout << "Sorry, there can't be more bombs than spaces. Try again: ";
		cin >> numbBombs;
	}
	while (numbBombs < 1) {
		cout << "Sorry, you need at least 1 bomb. Try again: ";
		cin >> numbBombs;
	}

	//Print an empty board
	cout << endl << "  Welcome to minesweeper!" << endl;
	cout << endl << "        ";
	for (int x = 0; x < boardXSize; x++) {
		boardLegnthNumberPrint(x);
	}
	cout << endl << "       ";
	for (int x = 0; x < boardXSize; x++) {
		boardLegnthLinePrint(x);
	}
	cout << endl;
	for (int y = 0; y<boardYSize; y++) {
		cout << "    " << y;
		if (y < 10) {
			cout << " ";
		}
		cout << "| ";
		for (int x = 0; x<boardXSize; x++) {
			cout << ". ";
		}
		cout << endl;
	}
	
	// set dynamic arrays for placing the bombs and for storing user guesses equal to the board size
	boardBombs = new char[boardXSize * boardYSize];
	userGuesses = new char[boardXSize * boardYSize];
	// I realize after my program is now complete that this could probably be one array....

	// set a number of bombs equal to the user's input randomly in our dynamic array
	while (checkBombs < numbBombs) {
		randBoardSpace = getRandom(boardXSize * boardYSize);
		while (boardBombs[randBoardSpace] == 'X') {
			randBoardSpace = getRandom(boardXSize * boardYSize);
		}
		boardBombs[randBoardSpace] = 'X';
		checkBombs++;
	}

	//for (int x = 0; x<boardXSize * boardYSize; x++) { //comment out when done, verified randomizer works visually
	//	cout << boardBombs[x] << endl;
	//}

	//* Application request a coordinate to check for a bomb.
	//* If coordinate doesn't match a bomb location __space__ (or some other character of your choice) for that location on the board.
	//* Application will redraw board with updates after each turn.
	//* If coordinate matches a bomb location :
	//*a message "YOU ARE DEAD" is printed
	//* Additionally all bomb locations on the board is reprinted with an X on that coordinate
	//* The "selected" bomb location shows on the board with an @ on that coordinatee.

	// start game
	while (gameOver == false) {

		cout << "Choose your X coordintate: ";
		cin >> xGuess;
		while (xGuess > boardXSize - 1 || xGuess < 0) {
			cout << "Sorry, I can't do that. Choose between 0 and " << boardXSize - 1 << ", please: ";
			cin >> xGuess;
		}
		cout << "Choose your Y coordintate: ";
		cin >> yGuess;
		while (yGuess > boardYSize - 1 || yGuess < 0) {
			cout << "Sorry, I can't do that. Choose between 0 and " << boardYSize - 1 << ", please: ";
			cin >> yGuess;
		}

		bombChecker = xGuess + (boardXSize * yGuess); //interpret user x and y guesses as a spot in our dynamic array of random bombs
		if (boardBombs[bombChecker] == 'X') {
			gameOver = true;
		}
		else { //if the guess is safe, redraw the board and repeat
			userGuesses[bombChecker] = 'y';
			cout << endl << "        ";
			for (int x = 0; x < boardXSize; x++) {
				boardLegnthNumberPrint(x);
			}
			cout << endl << "       ";
			for (int x = 0; x < boardXSize; x++) {
				boardLegnthLinePrint(x);
			}
			cout << endl;
			for (int y = 0; y < boardYSize; y++) {
				cout << "    " << y;
				if (y < 10) {
					cout << " ";
				}
				cout << "| ";
				for (int x = 0; x < boardXSize; x++) {
					if (userGuesses[x + (boardXSize * y)] == 'y') {
						cout << "O ";
					}
					else {
						cout << ". ";
					}
				}
				cout << endl;
			}
		}

	}
	//if game over is true, print final "death" board
	userGuesses[bombChecker] = 'b';
	cout << endl << "        ";
	for (int x = 0; x < boardXSize; x++) {
		boardLegnthNumberPrint(x);
	}
	cout << endl << "       ";
	for (int x = 0; x < boardXSize; x++) {
		boardLegnthLinePrint(x);
	}
	cout << endl;
	for (int y = 0; y < boardYSize; y++) {
		cout << "    " << y;
		if (y < 10) {
			cout << " ";
		}
		cout << "| ";
		for (int x = 0; x < boardXSize; x++) {
			if (userGuesses[x + (boardXSize * y)] == 'b') {
				cout << "@ ";
			}
			else if (boardBombs[x + (boardXSize * y)] == 'X') {
				cout << "X ";
			}
			else if (userGuesses[x + (boardXSize * y)] == 'y') {
				cout << "O ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << "You are dead!!" << endl << "@ = bomb you picked. X = other bombs. O = your safe guesses.";
	delete[] boardBombs;

	char keepAlive = 'y';
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}
