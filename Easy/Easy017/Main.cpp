/*	Triangle Program
*/

#include <iostream>
#include <string>
#include <iomanip>

// function declarations
void printTriangle(int, int, int);

int main(int argc, char* argv[]) {

	// integer to store the user inputs
	int h, d, j;	// input, height, direction, justification
	
	// ask the user for the data
	std::cout << "What height do you want the triangle to be?" << std::endl;
	std::cin >> h;
	std::cout << "What direction do you want the triangle to be?" << std::endl;
	std::cout << "[0] rightside up, [1] upside down" << std::endl;
	std::cin >> d;
	std::cout << "What justification do you want the triangle to be?" << std::endl;
	std::cout << "[0] left, [1] right" << std::endl;
	std::cin >> j;

	// print the result
	printTriangle(h, d, j);

	system("PAUSE");
	return 0;

}

// function to print a triangle
void printTriangle(int inp, int dir, int just) {

	// string to contain the characters for current line
	std::string thisLine;

	// loop as many times as the input wants
	for (int i = 0; i < inp; i ++) {

		// initialize this line
		thisLine = "";

		// loop a second time for each line input depending on the direction
		if (dir == 0) {		// right side up
			for (int j = i + 1; j > 0; j--) {
				// add a character to the line
				thisLine += "*";
			}
		}
		else {				// upside down
			for (int j = inp; j > i; j--) {
				// add a character to the line
				thisLine += "*";
			}
		}
		
		// print the line according to justification
		if( just == 0){		// justify left
			std::cout << thisLine;
		}
		else {				// justify right
			std::cout << std::right << std::setw(inp) << thisLine;
		}

		// create a new line
		std::cout << std::endl;
	}

	return;

}