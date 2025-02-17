// HW3_E24116071
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

int main()
{
	double n;
	int F_0 = 0;
	int F_1 = 1;
	int F_2;
	int counter = 1;

	cout << "請輸入一個整數以輸出該項的費式數列數值:" << endl;
	cin >> n;

	if (n == 0)
	{
		cout << F_0 << endl;
	}
	else if (n == 1)
	{
		cout << F_1 << endl;
	}
	else if (n > 1)
	{
		while (counter < n)
		{
			F_2 = F_1 + F_0;
			F_0 = F_1;
			F_1 = F_2;
			counter++;
		}
		cout << "費式數列的第" << n << "項為" << F_2 << endl;
	}
	else
	{
		cout << "輸入數值錯誤!" << endl;
	}
	return 0; // indicate that program ended successfully
}