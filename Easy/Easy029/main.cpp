/*	Palindrome program
*/

#include <iostream>
#include <string>

// function declarations
bool isPalindrome(std::string);
std::string toFormat(std::string);
std::string reverse(std::string);

int main() {

	// string to store user input
	std::string input;
	
	// prompt the user for an input
	std::cout << "What string would you like to test?" << std::endl;
	std::getline(std::cin, input);

	// boolean to store the result
	bool palindrome = isPalindrome(toFormat(input));

	// output the results
	if (palindrome) {
		std::cout << "'" << input << "' is a Palindrome!" << std::endl;
	}
	else {
		std::cout << "'" << input << "' is not a Palindrome..." << std::endl;
	}

	system("PAUSE");
	return 0;

}

// function to test if the input is a palindrome
bool isPalindrome(std::string input) {

	// boolean to store the result
	bool result = false;

	// string to store the reverse of the input
	std::string sReverse = reverse(input);

	// if the reverse is the same as the original
	if (input == sReverse) {
		// the string is a palindrome
		result = true;
	}

	// return whether the string is a palindrome or not
	return result;
}

// function to convert the input to a better format to test
std::string toFormat(std::string input) {

	// output string
	std::string output;

	// loop through the input string
	for (unsigned int i=0; i < input.size(); i++) {
		// if the current character is a space
		if (input[i] == 32) {
			// skip it
		}
		else {
			// if the character is upper case
			if (input[i] < 91 && input[i] > 64) {
				// add the lowercase letter
				output += input[i] + 32;
			}
			// if the character is lower case
			else if(input[i]>96 && input[i] < 122){
				// add the original character
				output += input[i];
			}
			else {
				// do nothing if it is not a character
			}
		}
	}

	// return the output string
	return output;

}

// function to reverse an input string
std::string reverse(std::string input) {

	// output string
	std::string output;

	// loop through the input string in reverse
	for (unsigned int i = input.size(); i > 0; i--) {
		// add the character to the output string
		output += input[i-1];
	}

	return output;
}