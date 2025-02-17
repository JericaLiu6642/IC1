// HW3_E24116071
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

void tower(int disk, char A, char B, char C)
{
	if (disk == 1) // �u���@�ӽL�l�M��disk��1������
	{
		cout << "Plate " << disk << " move from tower " << A << " to tower " << C << endl;
	}
	else{
		tower(disk - 1, A, C, B); //�ܧ�L�l�ѵ�����M�ت��a����
		cout << "Plate " << disk << " move from tower " << A << " to tower " << C << endl;
		tower(disk - 1, B, A, C);
	}
}

int main()
{
	int disk;
	cout << "Please input the number of disks: ";
	cin >> disk;
	// ��ܪ�l���A
	cout << "There are " << disk << " plates on tower 1, 0 on tower 2, and 0 on tower 3." << endl;
	// ��1,2,3��ܶ�W
	tower(disk, '1', '2', '3');
	cout << "WIN!" << endl;
	return 0;
}

