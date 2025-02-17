/*
// HW1_E24116071
// Text-print program
#include <iostream> // allows program to output data to the screen
using namespace std; // program uses names from the std namespace

int main()
{
	cout << "-------------------------------------------" << endl;
	cout << "| Name: Yu-Tzu, Liu                       |" << endl;
	cout << "| School: National Cheng Kung University  |" << endl;
	cout << "| Department: Electrical Engineering      |" << endl;
	cout << "| Email: E24116071@gs.ncku.edu.tw         |" << endl;
	cout << "-------------------------------------------" << endl;
	//display message

	return 0; // indicate that program ended successfully
} // end function main
*/

#include <iostream>
#include <fstream>

int main() {
	int n = 180000; // Number of vertices
	int num_chords = n / 2; // Number of chords

	std::ofstream outfile("testcase_n_180000.txt");

	outfile << n << "\n"; // Write number of vertices

	// Generate non-overlapping chords
	for (int i = 0; i < num_chords; ++i) {
		outfile << i << " " << (i + num_chords) << "\n";
	}

	outfile << "0\n"; // End of input as specified in your requirements

	outfile.close();
	std::cout << "Test case generated as 'testcase_n_180000.txt'.\n";

	return 0;
}
