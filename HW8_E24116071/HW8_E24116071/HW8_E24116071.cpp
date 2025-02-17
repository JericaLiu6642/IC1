// HW8_E24116071
#include <iostream>
#include <math.h>

int firstDwarfRow = 0;
int firstDwarfColumn = 0;
const int n = 7;
int answer[7]; // 紀錄小矮人在的行數
bool sameColumn[7] = { false }; //判斷小矮人是否在同一行
using namespace std;
// 用來填所有答案的二維array
int allAnswer[40][7];
// 控制所有答案二維array的列數 一列是一個答案
int a = 0;
int counter = 0;


void findAnswer(int row)
{
	if (row == 7)
	{
		bool flag = true; // 斜對角有沒有小矮人
		for (int i = 0; i < 7; i++) {
			for (int j = i+1; j < 7; j++) {
				// 行相減==列相減
				if (abs(i - j) == abs(answer[i] - answer[j])) {
					flag = false; // 如果在對角線上，解不能用
				}
			}
		}
		if (flag) {
			for (int k = 0; k < 7; k++) {
				allAnswer[a][k] = answer[k];
			}
			a++;
		}
	}

	for (int x = 0; x < 7; x++)
	{
		if (sameColumn[x] == false) //小矮人沒有在x這一行
		{
			answer[row] = x;
			sameColumn[x] = true;
			findAnswer(row + 1);
			sameColumn[x] = false;
		}
	}
}

int main()
{
	cout << "Please input the initial position of the first dwarf (strats at (0,0)):";
	cin >> firstDwarfRow >> firstDwarfColumn;

	findAnswer(0); // 從第0列開始尋找小矮人可在的位置

	bool answerExist = false;
	
	cout << "Answer:" << endl;

	// 找40種答案中有沒有和輸入相同的解
	for (int t = 0; t < 40; t++) {
		if (allAnswer[t][firstDwarfRow] == firstDwarfColumn) {
			answerExist = true;
			for (int s = 0; s < 6; s++) {
				cout << allAnswer[t][s] << ", ";
			}
			cout << allAnswer[t][6];
			cout << endl;
		}
	}

	if (answerExist == false) {
		cout << "No possible solution!";
	}

	return 0;
}

