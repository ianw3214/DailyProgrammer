#include <iostream>
#include <stdlib.h>

int getReverseFactorial(int input) {
	/*	Returns the factorial number corresponding to the input
		- Returns -1 if there is no factorial for the input
	*/

	int currentNum = 0, currentTotal = 0;
	while (currentTotal <= input) {
		if (currentTotal == input) {
			return currentNum;
		}
		else {
			currentNum++;
			currentTotal != 0 ? currentTotal *= currentNum : currentTotal = 1;
		}
	}

	// if the function runs to this point, there is not factorial for the number
	return -1;

}

int main(int argc, char * argv[]) {

	// see if there is a command line argument
	if (argc > 1) {
		int key = atoi(argv[1]);
		int num = getReverseFactorial(key);
		// a reverse factorial was found
		if (num >= 0) {
			std::cout << key << " = " << num << "!";
		}
		else {
			std::cout << key << " has no reverse factorial..";
		}
	}
	else {
		// notify the user to enter an input
		std::cout << "please enter an input...";
	}

	return 0;

}