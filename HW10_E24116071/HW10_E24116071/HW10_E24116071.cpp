// HW10_E24116071
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#define LEFTUP 0
#define LEFT 1
#define LEFTORUP 2
#define UP 3

using namespace std;

typedef struct {
	int num;
	int dir;
	set<string> sub;
}storage;


void LCS(string s1, string s2, vector<vector<storage>>& database)
{
	// 開始記錄
	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				database[i][j].num = database[i - 1][j - 1].num + 1;
				database[i][j].dir = LEFTUP; // left up
				if (database[i-1][j-1].sub.size()) {
					for (auto& k : database[i - 1][j - 1].sub) {
						database[i][j].sub.insert(k + s1[i - 1]); //set not empty, insert common char in s1
					}
				}
				else {
					database[i][j].sub.insert(string(1,s1[i - 1])); 
					// 把s1的char換成string 
					// 左上角的set空，直接把s1該格的char存下來
				}
			}
			else
			{
				if (database[i - 1][j].num > database[i][j - 1].num)
				{
					database[i][j].num = database[i - 1][j].num;
					database[i][j].dir = UP; // up
					database[i][j].sub = database[i - 1][j].sub;
				}
				else if (database[i - 1][j].num == database[i][j - 1].num)
				{
					database[i][j].num = database[i - 1][j].num;
					database[i][j].dir = LEFTORUP; // left=up
					database[i][j].sub = database[i - 1][j].sub;
					database[i][j].sub.insert(database[i][j - 1].sub.begin(), database[i][j - 1].sub.end());
				}
				else
				{
					database[i][j].num = database[i][j - 1].num;
					database[i][j].dir = LEFT;//left
					database[i][j].sub = database[i][j - 1].sub;
				}
			}
		}
	}
}

int main()
{
	string filename;

	// opens the file
	cout << "Please input your file name(ex:Example.txt):";
	cin >> filename;
	ifstream inClientFile(filename, ios::in);
	if (!inClientFile.is_open())
	{
		cerr << filename << " can not be opened" << endl;
		exit(1);
	}
	
	string s1;
	string s2;
	inClientFile >> s1;
	inClientFile >> s2;
	inClientFile.close();
	
	vector<vector<storage>> database(s1.size() + 1);

	// output answers to new file
	ofstream out("result_E24116071.txt", ios::out);

	// 指定二維vector的大小
	for (int i = 0; i < database.size(); i++) {
		database[i].resize(s2.size()+1);
	}

	LCS(s1, s2, database);
	
	int x = s1.size();
	int y = s2.size();
	int len = database[x][y].num;
	out << len << endl;
	out << database[x][y].sub.size() << endl;
	
	for (auto& i : database[x][y].sub) {
		out << i << endl;
	}

	return 0;
}
