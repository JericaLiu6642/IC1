// HW2_E24116071
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

int main()
{
	int num;
	cout << "�п�J0~5�����N�Ʀr:" << endl;
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
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else if (num == 1) {
			cout << "*" << endl;
			cout << endl;
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else if (num == 2) {
			cout << "**" << endl;
			cout << endl;
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else if (num == 3) {
			cout << "***" << endl;
			cout << endl;
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else if (num == 4) {
			cout << "****" << endl;
			cout << endl;
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else if (num == 5) {
			cout << "*****" << endl;
			cout << endl;
			cout << "�п�J0~5�����N�Ʀr:" << endl;
		}
		else {
			cout << "�z��J���Ʀr���~�A�ЦA����J0~5���Ʀr:" << endl;
		}
	}
	
	return 0; // indicate that program ended successfully
}