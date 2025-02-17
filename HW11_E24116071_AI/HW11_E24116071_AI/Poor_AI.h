#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define WIN 1
#define LOSE 2
#define DRAW 3
#define CONTINUE 0

using namespace std;
int E24104074_is_Gameover(vector < vector<char> >, int, char, char);
bool E24104074_legal_Move(vector < vector<char> >, int);
vector < vector<char> > E24104074_setchess(vector < vector<char> >, int, char);
bool E24104074_is_Full(vector < vector<char> > b2);
bool E24104074_checkwin(vector < vector<char> >, char);
bool E24104074_checkwin_2(vector < vector<char> >, char, int);
bool E24104074_check_easywin(vector < vector<char> > b1, char d1);
bool E24104074_compare(pair<int, int>, pair<int, int>);
int E24104074_checklose_3(vector < vector<char> > b1, char d1, int col);

int poor(const vector < vector<char> > &, char, char);

int poor(const vector < vector<char> > &b, char mydisc, char yourdisc) {
	static const char me = mydisc; //Record the disc type main function assigns for this AI. It never changes once assigned
	static const char opponent = yourdisc; //Record the disc type main function assigns for another AI. It never changes once assigned
	int column = -1;
	vector < vector<char> > board, board_1, board_2;
	board = b;
	int i_win_count = 0;

	vector<pair<int, int>> predict;
	//almost win
	for (int i = 0; i < 7; i++)
	{
		if (E24104074_legal_Move(board, i))
		{
			board = E24104074_setchess(board, i, me);
			if (E24104074_is_Gameover(board, i, me, me) == WIN)
			{
				return i;
			}
		}
		board = b;
	}
	//almost lose
	for (int i = 0; i < 7; i++)
	{
		board = b;
		if (E24104074_legal_Move(board, i))
		{
			board = E24104074_setchess(board, i, opponent);
			if (E24104074_is_Gameover(board, i, opponent, me) == LOSE)
			{
				return i;
			}

		}

	}
#if 1
	//predict the next three steps
	for (int i = 0; i < 7; i++)
	{
		board = b;
		i_win_count = 0;
		if (E24104074_legal_Move(board, i))
		{
			board = E24104074_setchess(board, i, me);
			board_1 = board;

			for (int j = 0; j < 7; j++)
			{
				board = board_1;
				if (E24104074_legal_Move(board, j))
				{
					board = E24104074_setchess(board, j, opponent);
					board_2 = board;
					if (E24104074_is_Gameover(board, j, opponent, me) == LOSE)
					{
						i_win_count = -1000;
						break;
					}
					else
					{
						for (int k = 0; k < 7; k++)
						{
							board = board_2;
							if (E24104074_legal_Move(board, k))
							{
								board = E24104074_setchess(board, k, me);
								if (E24104074_is_Gameover(board, k, me, me) == WIN)
								{
									i_win_count++;
								}

							}

						}

					}
				}

			}
		}
		predict.push_back(make_pair(i, i_win_count));
	}

	if (predict.size() != 0)
	{
		sort(predict.begin(), predict.end(), E24104074_compare);
		if (predict[0].second != 0)
		{

			return predict[0].first;
		}
	}
#endif
	//check if there has the row we i cannot cut
	for (int i = 1; i < 6; i++)
	{
		board = b;
		if (E24104074_legal_Move(board, i))
		{
			board = E24104074_setchess(board, i, opponent);
			if (E24104074_check_easywin(board, opponent))
			{

				return i;
			}

		}
	}
	//check if opponent has almost two lines 
	for (int i = 0; i < 7; i++)
	{
		board = b;
		for (auto k : predict)
		{
			if (i == k.first)
			{
				if (E24104074_legal_Move(board, i) && k.second >= 0)
				{
					board = E24104074_setchess(board, i, opponent);
					if (E24104074_checklose_3(board, opponent, i) >= 2)
					{

						return i;
					}
				}
			}
		}
	}
	//build line
	for (int i = 0; i < 7; i++)
	{
		board = b;
		for (auto k : predict)
		{
			if (i == k.first)
			{
				if (E24104074_legal_Move(board, i) && k.second >= 0)
				{
					board = E24104074_setchess(board, i, me);
					if (E24104074_checkwin_2(board, me, i))
					{

						return i;
					}
				}
			}
		}
	}
	board = b;
	//other conditions

	srand(time(NULL));
	vector<pair<int, int>> legal;
	int count = 0;
	for (auto k : predict)
	{
		if (E24104074_legal_Move(board, k.first))
		{
			legal.push_back(make_pair(k.first, k.second));
		}
	}
	if (legal.size() == 1)
	{
		return legal[0].first;
	}
	for (auto w : legal)
	{
		if (w.second < 0)
		{
			count++;
		}

	}
	if (count == legal.size())
	{
		return legal[0].first;
	}
	while (1)
	{
		bool checkrand = false;
		int r = rand() % 7;
		for (auto k : predict)
		{
			if (r == k.first)
			{
				if (k.second >= 0)
				{
					checkrand = true;
					break;
				}
			}
		}
		if (!checkrand)
		{
			continue;
		}
		if (E24104074_legal_Move(board, r))
		{

			return r;
		}

	}

}
int E24104074_is_Gameover(vector < vector<char> > bb, int c, char d, char mydisc)
{

	if (E24104074_checkwin(bb, d))
	{
		if (d == mydisc)
		{
			return WIN;
		}
		else
		{
			return LOSE;
		}
	}
	if (E24104074_is_Full(bb))
	{
		return DRAW;
	}
	return CONTINUE;

}
bool E24104074_legal_Move(vector < vector<char> > o, int c1)
{
	if (o[0][c1] == '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
vector < vector<char> > E24104074_setchess(vector < vector<char> > b3, int c2, char d2)
{
	int flag = 0;
	for (int i = 0; i < 5; i++)
	{
		if (b3[i][c2] == '\0'&&b3[i + 1][c2] != '\0')
		{
			b3[i][c2] = d2;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		b3[5][c2] = d2;
	}
	return b3;
}
bool E24104074_is_Full(vector < vector<char> > b2)
{
	int count_empty = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b2[i][j] == '\0')
			{
				return 0;
			}
			else
			{
				count_empty++;
			}
		}
	}
	if (count_empty == 42)
	{
		return 1;
	}
	return 0;
}
bool E24104074_checkwin(vector < vector<char> > b1, char d1)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j + 3 < 7)
			{
				if (b1[i][j] == d1 && b1[i][j + 1] == d1 && b1[i][j + 2] == d1 && b1[i][j + 3] == d1)
				{
					return 1;
				}
			}
			if (i + 3 < 6) {
				if (b1[i][j] == d1 && b1[i + 1][j] == d1 && b1[i + 2][j] == d1 && b1[i + 3][j] == d1)
				{
					return 1;
				}
			}
			if ((j + 3 < 7) && (i + 3 < 6))
			{
				if (b1[i][j] == d1 && b1[i + 1][j + 1] == d1 && b1[i + 2][j + 2] == d1 && b1[i + 3][j + 3] == d1)
				{
					return 1;
				}
			}
			if ((j - 3 >= 0) && (i + 3 < 6)) {
				if (b1[i][j] == d1 && b1[i + 1][j - 1] == d1 && b1[i + 2][j - 2] == d1 && b1[i + 3][j - 3] == d1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
bool E24104074_checkwin_2(vector < vector<char> > b1, char d1, int col)
{
	int row;
	for (int i = 0; i < 6; i++)
	{
		if (b1[i][col] != '\0')
		{
			row = i;
			break;
		}

	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j + 1 < 7)
			{
				if (b1[i][j] == d1 && b1[i][j + 1] == d1)
				{
					if (i == row && j == col)
					{
						return 1;
					}
					else if (i == row && (j + 1) == col)
					{
						return 1;
					}
				}
			}
			if (i + 1 < 6)
			{
				if (b1[i][j] == d1 && b1[i + 1][j] == d1)
				{
					if (i == row && j == col)
					{
						if (row > 2)
						{
							return 1;
						}
					}
					else if ((i + 1) == row && j == col)
					{
						if (row > 2)
						{
							return 1;
						}
					}
				}
			}
			if ((j + 1 < 7) && (i + 1 < 6))
			{
				if (b1[i][j] == d1 && b1[i + 1][j + 1] == d1)
				{

					if (i == row && j == col)
					{
						if ((i > 2 && j == 0) || (i > 3 && j == 1))
						{
							return 0;
						}
						else if ((i < 2 && j == 5) || (i < 1 && j == 4))
						{
							return 0;
						}
						return 1;
					}
					else if ((i + 1) == row && (j + 1) == col)
					{
						if (((i + 1) > 3 && (j + 1) == 1) || ((i + 1) > 4 && (j + 1) == 2))
						{
							return 0;
						}
						else if (((i + 1) < 3 && (j + 1) == 6) || ((i + 1) > 2 && (j + 1) == 5))
						{
							return 0;
						}
						return 1;
					}
				}
			}
			if ((j - 1 >= 0) && (i + 1 < 6))
			{
				if (b1[i][j] == d1 && b1[i + 1][j - 1] == d1)
				{
					if (i == row && j == col)
					{
						if ((i < 2 && j == 1) || (i < 1 && j == 2))
						{
							return 0;
						}
						else if ((i > 2 && j == 6) || (i > 3 && j == 5))
						{
							return 0;
						}
						return 1;
					}
					else if ((i + 1) == row && (j - 1) == col)
					{
						if (((i + 1) < 2 && (j - 1) == 1) || ((i + 1) < 3 && (j - 1) == 0))
						{
							return 0;
						}
						else if (((i + 1) > 3 && (j - 1) == 5) || ((i + 1) > 4 && (j - 1) == 4))
						{
							return 0;
						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
bool E24104074_check_easywin(vector < vector<char> > b1, char d1)
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			if (b1[j][i] == d1 && b1[j][i + 1] == d1 && b1[j][i + 2] == d1)
			{
				if (b1[j][i - 1] == '\0'&& b1[j][i + 3] == '\0')
				{
					return true;
				}
			}

		}
	}
	return false;
}
int E24104074_checklose_3(vector < vector<char> > b1, char d1, int col)
{
	int row;
	for (int i = 0; i < 6; i++)
	{
		if (b1[i][col] != '\0')
		{
			row = i;
			break;
		}

	}
	int rem = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j + 2 < 7)
			{
				if (b1[i][j] == d1 && b1[i][j + 1] == d1 && b1[i][j + 2] == d1)
				{
					if (i == row && j == col)
					{
						rem++;
					}
					else if (i == row && (j + 1) == col)
					{
						rem++;
					}
					else if (i == row && (j + 2) == col)
					{
						rem++;
					}
				}
			}
			if (i + 2 < 6)
			{
				if (b1[i][j] == d1 && b1[i + 1][j] == d1 && b1[i + 2][j] == d1)
				{
					if (i == row && j == col)
					{
						rem++;
					}
					else if ((i + 1) == row && j == col)
					{
						rem++;
					}
					else if ((i + 2) == row && j == col)
					{
						rem++;
					}
				}
			}
			if ((j + 2 < 7) && (i + 2 < 6))
			{
				if (b1[i][j] == d1 && b1[i + 1][j + 1] == d1 && b1[i + 2][j + 2] == d1)
				{
					if (i == row && j == col)
					{
						rem++;
					}
					else if ((i + 1) == row && (j + 1) == col)
					{
						rem++;
					}
					else if ((i + 2) == row && (j + 2) == col)
					{
						rem++;
					}
				}
			}
			if ((j - 2 >= 0) && (i + 2 < 6))
			{
				if (b1[i][j] == d1 && b1[i + 1][j - 1] == d1 && b1[i + 2][j - 2] == d1)
				{
					if (i == row && j == col)
					{
						rem++;
					}
					else if ((i + 1) == row && (j - 1) == col)
					{
						rem++;
					}
					else if ((i + 2) == row && (j - 2) == col)
					{
						rem++;
					}
				}
			}
		}
	}
	return rem;
}
bool E24104074_compare(pair<int, int>a, pair<int, int>b)
{
	return a.second > b.second;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int poor(const vector < vector<char> > &, char, char);

int getHeight2(const vector < vector<char> > &b, int col)
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

int getMax2(vector<int> total) {
	int column = max_element(total.begin(), total.end()) - total.begin();
	return column;
}

vector<int> check2(vector < vector<char> > b, int col, char disc)
{
	vector<int> score(3);
	int h = getHeight(b, col);

	int count = 0; //算多少disc有連線可能
	bool flag = true;

	b[h][col] = disc;

	//橫的判斷
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

	//直的判斷
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

	//左上到右下
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

	//右上到左下
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

int poor(const vector < vector<char> > &b, char mydisc, char yourdisc) {
	static const char me = mydisc; //Record the disc type main function assigns for this AI. It never changes once assigned
	static const char opponent = yourdisc; //Record the disc type main function assigns for another AI. It never changes once assigned
	int column = -1;
	//Write a simple AI for testing
	vector<vector<char>> temp1 = b;
	vector<int> total(7, 0);

	for (int i = 0; i <= 6; i++) {

		//避免放超出遊戲版面
		if (getHeight2(b, i) == -1) continue;

		//自己放在該格
		vector<int> score_1 = check2(temp1, i, me); //mydisc
		if (score_1[0] > 0) return i;
		///加分
		total[i] += score_1[1] * 5;
		total[i] += score_1[2] * 2;

		//敵人放在該格
		vector<int> score_2 = check2(temp1, i, opponent); //oppdisc
		if (score_2[0] > 0) return i;
		///加分
		total[i] += score_2[1] * 5;
		total[i] += score_2[2] * 2;

		//自己放該格，敵人在上面
		vector<vector<char>> temp2 = b;
		temp2[getHeight2(b, i)][i] = me;
		if (getHeight(temp2, i) == -1) continue;
		vector<int> score_3 = check2(temp2, i, opponent); //oppdisc on top
		///扣分
		total[i] += score_3[1] * (-100);
		total[i] += score_3[1] * (-10);
		total[i] += score_3[2] * (-5);
	}

	total[3] += 4;

	while (1)
	{
		column = getMax2(total);
		if (getHeight(b, column) == -1) {
			total[column] = -99999999;
		}
		else {
			break;
		}
	}



	return column;
	
	//Write a simple AI for testing
}

/*
	srand(time(NULL));

	do {
		column = rand() % 7;
	} while (getHeight2(b, column) == -1);


	return column;

*/