/*	PHONE NUMBER VALIDATOR PROGRAM
*/

#include <iostream>
#include <string>

// function declarations
bool checkNumber(std::string);
bool checkDigits(std::string, int);

int main(int argc, char* argv[]) {

	// string to store the user input
	std::string input;
	// boolean to store whether the input is valid or not
	bool valid;

	// prompt the user to enter the number to check
	std::cout << "Please input the phone number you would like to check." << std::endl;
	std::getline(std::cin, input);

	// check if the input is a valid phone number
	valid = checkNumber(input);

	// show the result to the user
	if (valid) {
		std::cout << input << " is a valid phone number" << std::endl;
	}
	else {
		std::cout << input << "is not a valid phone number" << std::endl;
	}

	system("PAUSE");
	return 0;

}

// function to check the input number 
bool checkNumber(std::string input) {

	// boolean to return whether the input is valid or not
	bool result = false;				// default the result to be false

	/*	VALID PHONE NUMBERS 
		1234567890, 123-456-7890, 123.456.7890, (123)456-7890, (123) 456-7890 (note the white space following the area code), and 456-7890 */

	if (checkDigits(input, 10)) {		// if there are 10 integer digits in the string
		if (input.size() == 10) {		// if the input consists of only numbers
			result = true;
		}
		else if (input.size() == 12) {	// if the string has 2 extra characters
			if (input[3]=='.' && input[7]=='.') {
				// return true if the fourth and seventh character are periods
				result = true;
			}
			else {
				result = false;
			}
		}
		else if (input.size() == 13) {	// if the string has 3 extra characters
			if (input[0] == '(' && input[4] == ')' && input[8] == '-') {
				// (xxx)xxx-xxxx
				result = true;
			}
			else {
				result = false;
			}
		}
		else if (input.size() == 14) {	// if the string has 4 extra characters
			if (input[0] == '(' && input[4] == ')' && input[5] == ' ' && input[9] == '-') {
				// (xxx) xxx-xxxx
				result = true;
			}
			else {
				result = false;
			}
		}
	}
	else if (checkDigits(input, 7) && input[3] == '-'&& input.size() == 8) {
		// xxx-xxxx
		result = true;
	}
	else {
		// none of the above conditions satisfied
		result = false;
	}

	if (result == NULL) {
		// if the result didn't pass through the loop
		std::cout << "PROGRAM FAILED" << std::endl;
		result = false;
	}

	return result;

}

// function to check if there are the right amount of digits
bool checkDigits(std::string input, int key) {

	// counter to add up the number of integers in the string
	int iCounter = 0;

	// loop through each character in the string
	for (unsigned int i = 0; i < input.size(); i++) {
		// store the character for this loop
		char tempChar = input[i];
		// if the character is a digit
		if (tempChar > 47 && tempChar < 58) {
			iCounter++;		// increase the integer counter
		}
	}

	if (iCounter==key) {
		return true;		// return true if there are the exact amount of digits
	}
	else {
		return false;		// return false if the amount of digits is wrong
	}

	return false;			// return false by default

}