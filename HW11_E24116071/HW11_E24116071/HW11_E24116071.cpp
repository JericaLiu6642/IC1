// HW11_E24116071
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

static int Disc_1 = 21;
static int Disc_2 = 21;


void includeREADME()
{
	string line;

	// Open file
	ifstream myFile;
	myFile.open("README.txt");

	// Print file content
	while (getline(myFile, line)) {
		cout << line << endl;
	}

	// Close file
	myFile.close();
}

bool checkTypo1(int discNum[8], int col)
{
	if (col > 6 || col < 0) {
		return false;
	}
	else if (discNum[col] == 6) {
		return false;
	}
	else {
		return true;
	}
}

bool checkTypo2(int discNum[8], int col)
{
	if (col > 6 || col < 0) {
		return false;
	}
	else if (discNum[col] == 6) {
		return false;
	}
	else {
		return true;
	}
}

void printGameBoard(vector<vector<int>> gameboard)
{
	cout << "  0    1    2    3    4    5    6" << endl;

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 7; j++){
			cout << "| ";
			if (gameboard[i][j] == 0){
				cout << " ";
			}
			else if (gameboard[i][j] == 1){
				cout << "o";
			}
			else if (gameboard[i][j] == 2){
				cout << "x";
			}
			cout << " |";
		}
		cout << "\n";
	}
}

void result(int a)
{
	if (a == -1) {
		cout << "\nWrong input!! Player2 wins!" << endl;
		exit(1);
	}
	else if (a == -2) {
		cout << "\nWrong input!! Player1 wins!" << endl;
		exit(1);
	}
	else if (a == 1) {
		cout << "Player1 wins!" << endl;
		exit(1);
	}
	else if (a == 2) {
		cout << "Player2 wins!" << endl;
		exit(1);
	}
	else if (a == 3) {
		cout << "The game is a draw!" << endl;
		exit(1);
	}
}

void checkCondition(vector<vector<int>> gameboard)
{
	//判斷橫列
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if ((gameboard[i][j] == 1) && (gameboard[i][j + 1] == 1) && (gameboard[i][j + 2] == 1) && (gameboard[i][j + 3] == 1)) {
				result(1);
			}
			if ((gameboard[i][j] == 2) && (gameboard[i][j + 1] == 2) && (gameboard[i][j + 2] == 2) && (gameboard[i][j + 3] == 2)) {
				result(2);
			}
		}
	}
	//判斷直行
	for (int i = 0; i < 7; i++) {
		if ((gameboard[0][i] == 1) && (gameboard[1][i] == 1) && (gameboard[2][i] == 1) && (gameboard[3][i] == 1)) {
			result(1);
		}
		if ((gameboard[1][i] == 1) && (gameboard[2][i] == 1) && (gameboard[3][i] == 1) && (gameboard[4][i] == 1)) {
			result(1);
		}
		if ((gameboard[2][i] == 1) && (gameboard[3][i] == 1) && (gameboard[4][i] == 1) && (gameboard[5][i] == 1)) {
			result(1);
		}
		if ((gameboard[0][i] == 2) && (gameboard[1][i] == 2) && (gameboard[2][i] == 2) && (gameboard[3][i] == 2)) {
			result(2);
		}
		if ((gameboard[1][i] == 2) && (gameboard[2][i] == 2) && (gameboard[3][i] == 2) && (gameboard[4][i] == 2)) {
			result(2);
		}
		if ((gameboard[2][i] == 2) && (gameboard[3][i] == 2) && (gameboard[4][i] == 2) && (gameboard[5][i] == 2)) {
			result(2);
		}
	}
	//判斷左到右斜線
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if ((gameboard[i][j] == 1) && (gameboard[i + 1][j + 1] == 1) && (gameboard[i + 2][j + 2] == 1) && (gameboard[i + 3][j + 3] == 1)) {
				result(1);
			}
			if ((gameboard[i][j] == 2) && (gameboard[i + 1][j + 1] == 2) && (gameboard[i + 2][j + 2] == 2) && (gameboard[i + 3][j + 3] == 2)) {
				result(2);
			}
		}
	}
	//判斷右到左斜線
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 7; j++) {
			if ((gameboard[i][j] == 1) && (gameboard[i + 1][j - 1] == 1) && (gameboard[i + 2][j - 2] == 1) && (gameboard[i + 3][j - 3] == 1)) {
				result(1);
			}
			if ((gameboard[i][j] == 2) && (gameboard[i + 1][j - 1] == 2) && (gameboard[i + 2][j - 2] == 2) && (gameboard[i + 3][j - 3] == 2)) {
				result(2);
			}
		}
	}

	if (Disc_1 == 0 && Disc_2 == 0) {
		result(3);
	}
}

int main()
{
	//記錄每一個column目前裝了多少的disc
	int discNum[8] = { 0 };
	int col = 0;

	//紀錄disc擺放情況，並且指定大小
	vector<vector<int>> gameboard(6);
	for (int i = 0; i < gameboard.size(); i++) {
		gameboard[i].resize(7);
	}

	//include readme
	includeREADME();

	printGameBoard(gameboard);

	//遊戲開始
	while (1) {
		cout << "Player1's round" << endl;
		cout << "Choose a column to put your disc:";
		cin >> col;
		cout << endl;

		bool correct_1 = checkTypo1(discNum, col);

		if (correct_1) {
			discNum[col]++;
			Disc_1--;
			gameboard[6 - discNum[col]][col] = 1;
			printGameBoard(gameboard);
			checkCondition(gameboard);
		}
		else {
			//輸入有錯，直接判輸
			result(-1);
		}

		cout << "Player2's round" << endl;
		cout << "Choose a column to put your disc:";
		cin >> col;

		cout << endl;

		bool correct_2 = checkTypo2(discNum, col);

		if (correct_2) {
			discNum[col]++;
			Disc_2--;
			gameboard[6 - discNum[col]][col] = 2;
			printGameBoard(gameboard);
			checkCondition(gameboard);
		}
		else {
			//輸入有錯，直接判輸
			result(-2);
		}
	}
}
