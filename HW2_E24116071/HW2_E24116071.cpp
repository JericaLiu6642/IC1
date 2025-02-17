// HW2_E24116071
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

int main()
{
	int num;
	cout << "請輸入0~5的任意數字:" << endl;
	while (cin >> num)
	{
		if (num == 0) {
			cout << "-------------------------------------------" << endl;
			cout << "| Name: Yu-Tzu, Liu                       |" << endl;
			cout << "| School: National Cheng Kung University  |" << endl;
			cout << "| Department: Electrical Engineering      |" << endl;
			cout << "| Email: E24116071@gs.ncku.edu.tw         |" << endl;
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else if (num == 1) {
			cout << "*" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else if (num == 2) {
			cout << "**" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else if (num == 3) {
			cout << "***" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else if (num == 4) {
			cout << "****" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else if (num == 5) {
			cout << "*****" << endl;
			cout << endl;
			cout << "請輸入0~5的任意數字:" << endl;
		}
		else {
			cout << "您輸入的數字錯誤，請再次輸入0~5的數字:" << endl;
		}
	}
	
	return 0; // indicate that program ended successfully
}