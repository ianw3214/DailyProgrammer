/*	  KAPREKAR NUMBERS
	- a Kaprekar number for a given base is a non-negative integer, the representation 
	of whose square in that base can be split into two parts that add up to the original 
	number again.

	e.g. 45^2 = 2025 and 20+25 = 45

	program should take range of input and find kaprekar numbers in the range
*/
#include <iostream>
#include <cmath>
#include <vector>

// finds the number of digits in an integer
int getDigits(int input) {

	int digits = 0;
	while (pow(10, digits) <= input) {
		digits++;
	}
	return digits;

}

void getKaprekar(int start, int end) {
	
	std::vector<int> results;

	// loop through every number in the range
	for (int i = start; i <= end; i++) {
		// flag boolean to denote whether the target number is a goal number
		bool flag = false;
		// first get the square
		int square = i * i;
		int digits = getDigits(square);
		// loop from 1 to # of digits - 1
		for (int j = 1; j < digits; j++) {
			int rightNum = square % static_cast<int>(pow(10, j));
			int leftNum = (square - rightNum)/static_cast<int>(pow(10, j));
			// flag the number if it satisfies the conditions
			// make sure neither of the numbers are 0
			if ((rightNum + leftNum) == i && rightNum != 0 && leftNum != 0) {
				// std::cout << rightNum << " : " << leftNum << " :: " << i << std::endl;
				flag = true;
			}
		}
		// if the number is flagged, add it to the vector
		if (flag) {
			results.push_back(i);
		}
	}

	// print the results
	for (int i = 0; i < results.size(); i++) {
		std::cout << results[i] << " ";
	}

}

int main() {

	getKaprekar(101, 9000);

	std::cin.get();
	return 0;

}
