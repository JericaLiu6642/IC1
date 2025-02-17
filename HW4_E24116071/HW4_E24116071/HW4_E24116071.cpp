// HW4_E24116071
#include <iostream> // allows program to output data to the screen
#include <cstdlib>  // for displaying random number
#include <ctime> // for generate random number
using namespace std; 


int AnswerGenerator()
{
	int a1, a2, a3, a4; // the four digits of answer
	int answer;

	do {
		srand(time(0));
		a1 = rand() % 9 + 1;
		a2 = rand() % 9 + 1;
		a3 = rand() % 9 + 1;
		a4 = rand() % 9 + 1;
	} while ((a1 == a2) || (a1 == a3) || (a1 == a4) || (a2 == a3) || (a2 == a4) || (a3 == a4)); // ensure digits are all different

	answer = (a1 * 1000 + a2 * 100 + a3 * 10 + a4);
	return answer;
}

int main()
{
	bool again = true; // a loop for user to play more rounds
	int newround = 0;

	while (again) {
		int answer = AnswerGenerator();
		int input = 0;
		unsigned seed;
		int counterA = 0, counterB = 0;

		for (int i = 1; i <= 20; i++) {
			cout << "Please input 4 digits number:";
			cin >> input;

			int i1 = input / 1000;
			int i2 = input % 1000 / 100;
			int i3 = input % 100 / 10;
			int i4 = input % 10;

			if ((i1 == i2) || (i1 == i3) || (i1 == i4) || (i2 == i3) || (i2 == i4) || (i3 == i4) || input < 1000 || input > 9999) {
				cout << input << ": " << "Input error! different please!" << endl; // avoid error
			}
			else {
				int a1 = answer / 1000;
				int a2 = answer % 1000 / 100;
				int a3 = answer % 100 / 10;
				int a4 = answer % 10;

				if (i1 == a1)
					counterA++;
				if (i2 == a2)
					counterA++;
				if (i3 == a3)
					counterA++;
				if (i4 == a4)
					counterA++;

				if (i1 == a2 || i1 == a3 || i1 == a4)
					counterB++;
				if (i2 == a1 || i2 == a3 || i2 == a4)
					counterB++;
				if (i3 == a1 || i3 == a2 || i3 == a4)
					counterB++;
				if (i4 == a1 || i4 == a2 || i4 == a3)
					counterB++;

				cout << input << ":" << counterA << "A" << counterB << "B" << endl;

				if (counterA == 4) {
					cout << "\nyou win!" << endl;
					cout << "\nDo you want to play again? Press 1 to play or press 0 to leave:";
					cin >> newround;
					if (newround != 1) {
						again = false; // leave the loop
					}
					break;
				}

				else {
					counterA = 0;
					counterB = 0;
				}

				if (i == 20) {
					cout << "You lose! The correct answer is " << answer << endl;
					cout << "\nDo you want to play again? Press 1 to play or press 0 to leave:";
					cin >> newround;
					if (newround != 1) {
						again = false; // leave the loop
					}
					break;
				}
			}
		}
	}
	return 0; // indicate that program ended successfully
}