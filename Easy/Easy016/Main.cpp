/*	Char Remove Program
*/

#include <iostream>
#include <string>

// function declarations
std::string removeFrom(std::string, std::string);

int main(int argc, char* argv[]) {

	// the two strings to store inputs
	std::string inp, key;
	
	// get the two input strings from the user
	std::cout << "Please enter a string:" << std::endl;
	std::getline(std::cin, inp);
	std::cout << "Please enter the characters you would like to remove from the string:" << std::endl;
	std::cout << "(spaces and special characters cout too)" << std::endl;
	std::getline(std::cin, key);

	// remove the characters of key from inp
	inp = removeFrom(inp, key);

	// output the result
	std::cout << "The resultant string is: " << inp << std::endl;

	system("PAUSE");
	return 0;

}

// remove characters of B from A
std::string removeFrom(std::string A, std::string B) {

	// final string to return
	std::string fString;

	// boolean to check for same characters
	bool isSame;

	// loop through the first string
	for (unsigned int i = 0; i < A.size(); i++) {

		// set the boolean to false at first
		isSame = false;

		// loop through the key string
		for (unsigned int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) {
				// set the boolean to true if characters are the same
				isSame = true;
				// break from current second loop if characters are the same
				break;
			}
		}

		if (!isSame) {	// if the characters are not the same
			// add the character to the final string
			fString += A[i];
		}
	}

	// return the final string to the user
	return fString;

}