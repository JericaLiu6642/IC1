// HW3_E24116071
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

void tower(int disk, char A, char B, char C)
{
	if (disk == 1) // 只有一個盤子和當disk為1的情形
	{
		cout << "Plate " << disk << " move from tower " << A << " to tower " << C << endl;
	}
	else{
		tower(disk - 1, A, C, B); //變更盤子供給的塔和目的地的塔
		cout << "Plate " << disk << " move from tower " << A << " to tower " << C << endl;
		tower(disk - 1, B, A, C);
	}
}

int main()
{
	int disk;
	cout << "Please input the number of disks: ";
	cin >> disk;
	// 顯示初始狀態
	cout << "There are " << disk << " plates on tower 1, 0 on tower 2, and 0 on tower 3." << endl;
	// 用1,2,3表示塔名
	tower(disk, '1', '2', '3');
	cout << "WIN!" << endl;
	return 0;
}

