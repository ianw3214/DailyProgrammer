/*	Phone number converting program
*/

#include <iostream>
#include <string>

// entry point
int main(int argc, char* argv[]) {

	// string to store user input
	std::string input;

	// get the string from the user
	std::cout << "please input the telephone number you want to convert to numbers" << std::endl;
	std::getline(std::cin, input);

	// loop through each character to convert letters to numbers
	for (int i = 0; i < input.size(); i++) {
		// check if the character is a letter
		if ( (64<input[i]&&input[i]<91) || (97<input[i] && input[i]<123) ) {
			char c = tolower(input[i]);					// change the character to lower case
			if (c == 97 || c == 98 || c == 99) {		// ABC
				input[i] = '2';
			}
			if (c == 100 || c == 101 || c == 102) {		// DEF
				input[i] = '3';
			}
			if (c == 103 || c == 104 || c == 105) {		// GHI
				input[i] = '4';
			}
			if (c == 106 || c == 107 || c == 108) {		// JKL
				input[i] = '5';
			}
			if (c == 109 || c == 110 || c == 111) {		// MNO
				input[i] = '6';
			}
			if (c == 112 || c == 113 || c == 114 || c == 115) {		// PQRS
				input[i] = '7';
			}
			if (c == 116 || c == 117 || c == 118) {		// TUV
				input[i] = '8';
			}
			if (c == 119 || c == 120 || c == 121 || c == 122) {		// WXYZ
				input[i] = '9';
			}
		}
	}

	std::cout << "The resulting phone number is: " << input;

	system("PAUSE");
	return 0;

}