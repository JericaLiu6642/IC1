// HW8_E24116071
#include <iostream>
#include <math.h>

int firstDwarfRow = 0;
int firstDwarfColumn = 0;
const int n = 7;
int answer[7]; // �����p�G�H�b�����
bool sameColumn[7] = { false }; //�P�_�p�G�H�O�_�b�P�@��
using namespace std;
// �ΨӶ�Ҧ����ת��G��array
int allAnswer[40][7];
// ����Ҧ����פG��array���C�� �@�C�O�@�ӵ���
int a = 0;
int counter = 0;


void findAnswer(int row)
{
	if (row == 7)
	{
		bool flag = true; // �׹﨤���S���p�G�H
		for (int i = 0; i < 7; i++) {
			for (int j = i+1; j < 7; j++) {
				// ��۴�==�C�۴�
				if (abs(i - j) == abs(answer[i] - answer[j])) {
					flag = false; // �p�G�b�﨤�u�W�A�Ѥ����
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
		if (sameColumn[x] == false) //�p�G�H�S���bx�o�@��
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

	findAnswer(0); // �q��0�C�}�l�M��p�G�H�i�b����m

	bool answerExist = false;
	
	cout << "Answer:" << endl;

	// ��40�ص��פ����S���M��J�ۦP����
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

