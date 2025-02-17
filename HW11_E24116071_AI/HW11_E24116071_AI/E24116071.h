#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int E24116071(const vector < vector<char> > &, char, char);

int getHeight(const vector < vector<char> > &b, int col)
{
	if (b[0][col] != 0) {
		return -1;
	}
	for (int i = 5; i >= 0; i--) {
		if (b[i][col] == 0) {
			return i;
		}
	}
}

int getMax(vector<int> total) {
	int column = max_element(total.begin(), total.end()) - total.begin();
	return column;
}

vector<int> check(vector < vector<char> > b, int col, char disc)
{
	vector<int> score(3);
	int h = getHeight(b, col);
	
	int count = 0; //��h��disc���s�u�i��
	bool flag = true;

	b[h][col] = disc;

	//��P�_
	for (int i = -3; i <= 0; i++) {
		for (int k = 0; k <= 3; k++) {
			if ((col + i + k) < 0 || (col + i + k) > 6) {
				flag = false;
				break;
			}
			else if (b[h][col + i + k] == disc) {
				count++;
			}
			else if (b[h][col + i + k] == 0) {
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			switch (count)
			{
			case 4:
				score[0]++; break;
			case 3:
				score[1]++; break;
			case 2:
				score[2]++; break;
			}
		}
		count = 0;
		flag = true;
	}

	//�����P�_
	count = 0;
	for (int i = 0; i <= 3; i++) {
		if ((h + i) > 5) {
			break;
		}
		else if (b[h + i][col] == disc) {
			count++;
		}
		else if (b[h + i][col] == 0) {
		}
		else {
			break;
		}
	}

	switch (count)
	{
	case 4:
		score[0]++; break;
	case 3:
		score[1]++; break;
	case 2:
		score[2]++; break;
	}

	//���W��k�U
	count = 0;
	for (int i = -3; i <= 0; i++) {
		for (int k = 0; k <= 3; k++) {
			if ((h + i + k) < 0 || (h + i + k) > 5 || (col + i + k) < 0 || (col + i + k) > 6) {
				flag = false;
				break;
			}
			else if (b[h + i + k][col + i + k] == disc) {
				count++;
			}
			else if (b[h + i + k][col + i + k] == 0) {
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			switch (count)
			{
			case 4:
				score[0]++; break;
			case 3:
				score[1]++; break;
			case 2:
				score[2]++; break;
			}
		}
		count = 0;
		flag = true;
	}

	//�k�W�쥪�U
	count = 0;
	for (int i = -3; i <= 0; i++) {
		for (int k = 0; k <= 3; k++) {
			if ((h + i + k) < 0 || (h + i + k) > 5 || (col - i - k) < 0 || (col - i - k) > 6) {
				flag = false;
				break;
			}
			else if (b[h + i + k][col - i - k] == disc) {
				count++;
			}
			else if (b[h + i + k][col - i - k] == 0) {
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			switch (count)
			{
			case 4:
				score[0]++; break;
			case 3:
				score[1]++; break;
			case 2:
				score[2]++; break;
			}
		}
		count = 0;
		flag = true;
	}

	return score;
}



int E24116071(const vector < vector<char> > &b, char mydisc, char yourdisc) {

	static const char me = mydisc; //Record the disc type main function assigns for this AI. It never changes once assigned
	static const char opponent = yourdisc; //Record the disc type main function assigns for another AI. It never changes once assigned
	int column = -1;
	//Write your AI here

	vector<vector<char>> temp1 = b;
	vector<int> total(7,0);

	for (int i = 0; i <= 6; i++) {

		//�קK��W�X�C������
		if (getHeight(b, i) == -1) continue;

		//�ۤv��b�Ӯ�
		vector<int> score_1 = check(temp1, i, me); //mydisc
		if (score_1[0] > 0) return i;
		///�[��
		total[i] += score_1[1] * 20;
		total[i] += score_1[2] * 10;

		//�ĤH��b�Ӯ�
		vector<int> score_2 = check(temp1, i, opponent); //oppdisc
		if (score_2[0] > 0) return i;
		///�[��
		total[i] += score_2[1] * 10;
		total[i] += score_2[2] * 5;

		//�ۤv��Ӯ�A�ĤH�b�W��
		vector<vector<char>> temp2 = b;
		temp2[getHeight(b, i)][i] = me;
		if (getHeight(temp2, i) == -1) continue;
		vector<int> score_3 = check(temp2, i, opponent); //oppdisc on top
		///����
		total[i] += score_3[1] * (-1000);
		total[i] += score_3[1] * (-10);
		total[i] += score_3[2] * (-5);
	}
	
	total[3] += 8;

	while(1)
	{
		column = getMax(total);
		if (getHeight(b, column) == -1) {
			total[column] = -99999999;
		}
		else {
			break;
		}
	}

	return column;

	//Write your AI here
}