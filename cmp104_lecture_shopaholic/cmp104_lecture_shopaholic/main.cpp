#include <iostream>
using namespace std;

void shopaholic() {
	int prices[6] = { 0 };
	for (int i = 0; i < 6; i++) {
		cout << "enter price of item " << i + 1 << " (pls no decimal point): "; cin >> prices[i];
	}
	// sort array
	int temp;
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			if (prices[i] > prices[j]) {
				temp = prices[j];
				prices[j] = prices[i];
				prices[i] = temp;
			}
		}
	}
	int smallDiscount = prices[0];
	int largeDiscount = prices[3];
	int totalDiscount = smallDiscount + largeDiscount;
	int finalPrice = 0;
	for (int price : prices) {
		finalPrice += price;
	}
	finalPrice -= totalDiscount;
	cout << "smaller discount:     £" << smallDiscount << endl;
	cout << "larger discount:      £" << largeDiscount << endl;
	cout << "total discount:       £" << totalDiscount << endl;
	cout << "price after discount: £" << finalPrice << endl;
}

const int NUM_ROWS = 3;
char ticTacToeGrid[NUM_ROWS][NUM_ROWS] = { 
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};
char checkWinner(char player) {
	// first check for horizontal win
	for (int row = 0; row < NUM_ROWS; row++) {
		int matches = 0;
		for (int col = 0; col < NUM_ROWS; col++) {
			if (ticTacToeGrid[row][col] == player) {
				matches++;
				if (matches >= NUM_ROWS) {
					return player;
				}
			}
		}
	}
	// then vertical
	for (int col = 0; col < NUM_ROWS; col++) {
		int matches = 0;
		for (int row = 0; row < NUM_ROWS; row++) {
			if (ticTacToeGrid[row][col] == player) {
				matches++;
				if (matches >= NUM_ROWS) {
					return player;
				}
			}
		}
	}
	// now diagonal
	if (
		(ticTacToeGrid[0][0] == player && ticTacToeGrid[1][1] == player && ticTacToeGrid[2][2] == player) ||
		(ticTacToeGrid[2][0] == player && ticTacToeGrid[1][1] == player && ticTacToeGrid[0][2] == player)
		) {
		return player;
	}
	// can't forget about drawing
	bool spaceFound = false;
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_ROWS; col++) {
			if (ticTacToeGrid[row][col] == ' ') {
				spaceFound = true;
				break;
			}
		}
		if (spaceFound) break;
	}
	if (!spaceFound) return 'd';
	// if none of the above, no one won yet
	return ' ';
}

void ticTacToe() {
	char blankRow[NUM_ROWS] = { ' ' };
	char gridline[10] = "--+---+--";
	char currentPlayer = 'x';
	int rowNum, colNum;
	bool gameOver = false;
	char winner;
	while (!gameOver) {
		cout << "\nplayer " << currentPlayer << "'s turn" << endl;
		cout << "enter row number: "; cin >> rowNum;
		cout << "enter column number: "; cin >> colNum;

		while (ticTacToeGrid[rowNum][colNum] != ' ') {
			cout << "don't even think about it, cheater" << endl;
			cout << "enter row number: "; cin >> rowNum;
			cout << "enter column number: "; cin >> colNum;
		}
		ticTacToeGrid[rowNum][colNum] = currentPlayer;
		cout << endl;
		cout << ticTacToeGrid[0][0] << " | " << ticTacToeGrid[0][1] << " | " << ticTacToeGrid[0][2] << endl;
		cout << gridline << endl;
		cout << ticTacToeGrid[1][0] << " | " << ticTacToeGrid[1][1] << " | " << ticTacToeGrid[1][2] << endl;
		cout << gridline << endl;
		cout << ticTacToeGrid[2][0] << " | " << ticTacToeGrid[2][1] << " | " << ticTacToeGrid[2][2] << endl;
		winner = checkWinner(currentPlayer);
		gameOver = (winner != ' ');
		if (!gameOver) currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
	}
	cout << endl;
	if (winner == 'd') cout << "draw" << endl; else cout << winner << " wins" << endl;
	return;
}

int main() {
	//shopaholic();
	ticTacToe();

}