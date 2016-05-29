/*	Right Triangle Program
*/

#include <iostream>

int main() {

	// integer to store user input
	int inp;

	// prompt the user for an input
	std::cout << "Please enter the numbers you would like in your triangle:" << std::endl;
	std::cin >> inp;

	// integers to keep track of stats
	int lastRow = 0, cRow = 1, lTotal = 0;

	// loop through each number
	for (int i = 1; i <= inp; i++) {
		// exit the loop if there aren't enough numbers left
		if ((inp-lTotal) < cRow) {
			break;
		}
		// print the current number
		std::cout << i;
		if ((i-lTotal)==cRow) {
			std::cout << std::endl;
			lastRow = cRow;
			lTotal += lastRow;
			cRow++;
		}
	}

	system("PAUSE");
	return 0;

}