#include<iostream>
#include<cstring>
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

	cout << "Welcome to minesweeper!" << endl;
	//start the game
	while (gameOver == false) {

		cout << endl << "First, how big of a board do you want to play on?" << endl << "Width: ";
		cin >> boardXSize;
		while (boardXSize > 99 || boardXSize < 1) {
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
		cout << endl << "      Welcome to minesweeper!" << endl;
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


	}	
	
	
	
	


//* Application request a coordinate to check for a bomb.
//* If coordinate doesn't match a bomb location __space__ (or some other character of your choice) for that location on the board.
//* Application will redraw board with updates after each turn.
//* If coordinate matches a bomb location :
//*a message "YOU ARE DEAD" is printed
//* Additionally all bomb locations on the board is reprinted with an X on that coordinate
//* The "selected" bomb location shows on the board with an @ on that coordinatee.

	char keepAlive = 'y';
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}
