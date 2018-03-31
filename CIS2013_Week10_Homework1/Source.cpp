#include<iostream>
#include<cstring>
using namespace std;

//When the application is run...
//* Application asks for a board size in the form on x & y.
//* The application then asks for a number of bombs to plant.
//* Using DYNAMIC ARRAYS the applicaiton prints a "blank board" of that size, for example:
//*Choose board width : 10
//* Choose board height : 11
//* Choose number of bombs : 5
//* The number of bombs is randomly "placed" throughout the board but not displayed.

int main() {

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
