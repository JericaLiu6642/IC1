// HW7_E24116071
#include <iostream> // for system input / output
#include <iomanip> // for numbers to display clearly on the screen
#include <ctime> // the use of random
using namespace std;

void matrixMaximum(int **matrix, int m, int n, int &maxLeft, int &maxRight, int &maxUp, int &maxDown, int &maxSum_answer, int &upBound, int &downBound);
void tmpMaximum(int *tmp, int m, int n, int &maxUp, int &maxDown, int &maxSum);


// р–︽tmp耞程オ
void matrixMaximum(int **matrix, int m, int n, int &maxLeft, int &maxRight, int &maxUp, int &maxDown, int &maxSum_answer, int &upBound, int &downBound)
{
	int *tmp = new int[m];
	int maxSum = -100000;

	for (int left = 0; left < n; left++) {
		for (int i = 0; i < m; i++) {
			tmp[i] = 0;
		}
		for (int right = left; right < n; right++) {
			for (int i = 0; i < m; i++) {
				tmp[i] += matrix[i][right];
			}
			tmpMaximum(tmp, m, n, upBound, downBound, maxSum);
			if (maxSum > maxSum_answer) {
				// т穝程传オ
				maxSum_answer = maxSum;
				maxRight = right;
				maxLeft = left;
				maxUp = upBound;
				maxDown = downBound;
			}
		}
	}
}

// tmpず羆程т
void tmpMaximum(int *tmp, int m, int n, int &upBound, int &downBound, int &maxSum)
{
	int currentUp = 0;
	int currentSum = 0;

	for (int i = 0; i < m; i++) {
		currentSum += tmp[i];
		if (currentSum < 0) {
			currentSum = 0;
			currentUp = i + 1;
		}
		if (currentSum > maxSum) {
			upBound = currentUp;
			downBound = i;
			maxSum = currentSum;
		}
	}	
}


int main()
{
	int m, n;
	cout << "How many rows are there in your matrix:";
	cin >> m;
	cout << "How many columns are there int your matrix:";
	cin >> n;

	int **matrix;
	matrix = new int *[m]; //Τmrow

	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
		// –Τncolumns
	}

	// ㄢ贺家Α匡拒
	int choice = 0;
	cout << "Press 1 to set the number of your matrix. Press 2 to produce it randomly: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Please input the numbers in your matrix (from left to right, up to down):";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		break;
	case 2:
		srand(time(NULL));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = rand() % 11 - 5;
			}
		}
		break;
	}
	

	cout << "The original matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}

	int maxLeft = 0;
	int maxRight = 0;
	int maxUp = 0;
	int maxDown = 0;
	int maxSum_answer = -100000;
	int upBound = 0;
	int downBound = 0;

	matrixMaximum(matrix, m, n, maxLeft, maxRight, maxUp, maxDown, maxSum_answer, upBound, downBound);
	
	cout << "\nThe maximum sum of numbers in a submatrix is: " << maxSum_answer << endl;
	cout << "The submatrix is:" << endl;
	for (int i = maxUp; i <= maxDown; i++) {
		for (int j = maxLeft; j <= maxRight; j++) {
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}

	// 埃笆篈痻皚
	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
		// –Τncolumns
	}
	delete[] matrix;
}

