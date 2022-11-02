// TicTacToeProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

char space[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row;
int column;
char token = 'x';
bool tie = false;
string playerOne;
string playerTwo;

void outputGameState(){
	cout << "    |     |  \n";
	cout << "  " << space[0][0] << " |  " << space[0][1] << "  | " << space[0][2] << "\n";
	cout << "____|_____|____\n";
	cout << "    |     |  \n";
	cout << "  " << space[1][0] << " |  " << space[1][1] << "  | " << space[1][2] << "\n";
	cout << "____|_____|____\n";
	cout << "    |     |  \n";
	cout << "  " << space[2][0] << " |  " << space[2][1] << "  | " << space[2][2] << "\n";
	cout << "    |     |  \n";

}

void playTurn() {
	int digit=0;
	while (true) {
		if (token == 'x')
		{
			cout << playerOne << ", please enter\n";
			cin >> digit;
		}
		else if (token == '0')
		{
			cout << playerTwo << ", please enter\n";
			cin >> digit;
		}
		switch (digit) {
			case 1:
				row = 0;
				column = 0;
				break;
			case 2:
				row = 0;
				column = 1;
				break;
			case 3:
				row = 0;
				column = 2;
				break;
			case 4:
				row = 1;
				column = 0;
				break;
			case 5:
				row = 1;
				column = 1;
				break;
			case 6:
				row = 1;
				column = 2;
				break;
			case 7:
				row = 2;
				column = 0;
				break;
			case 8:
				row = 2;
				column = 1;
				break;
			case 9:
				row = 2;
				column = 2;
				break;
		}


		if (digit < 1 || digit>9 || space[row][column] == 'x' || space[row][column] == '0') {
			cout << "Invalid move" << endl;
		}
		else {
			break;
		}
	}

	if (token == 'x') {
		space[row][column] = 'x';
		token = '0';
	}
	else if (token == '0') {
		space[row][column] = '0';
		token = 'x';
	}
	outputGameState();
}

bool checkWinOrDraw() {
	// diagonal check
	if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0])
		return true;
	// row and column check
	for (int i = 0; i < 3; i++) {
		if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
			return true;
	}
	
	// check if the game can continue
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (space[i][j] != 'x' && space[i][j] != '0') {
				return false;
			}
		}
	}
	tie = true;
	return true;
}
int main()
{
	cout << "Enter the name of Player One : \n";
	getline(cin, playerOne);
	cout << "Enter the name of Player Two : \n";
	getline(cin, playerTwo);
	outputGameState();
	while (!checkWinOrDraw()) {
		playTurn();
	}
	if (tie) {
		cout << "Draw!" << endl;
	}
	else {
		if (token == '0') {
			cout << playerOne << " wins!" << endl;
		}
		else if (token == 'x') {
			cout << playerTwo << " wins!" << endl;
		}
	}
}