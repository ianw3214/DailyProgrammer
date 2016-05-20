/*	base 26 products
	- A = 1, B = 2, C = 3 ....
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

// function declarations
int getBase10(std::string);
std::string getBase26(int);

int main() {

	// variables to store the input data
	std::string a, b;

	// prompt the user for the input data
	std::cout << "PLEASE INPUT THE FIRST BASE 26 STRING: " << std::endl;
	std::getline(std::cin, a);
	std::cout << "PLEASE INPUT THE SECOND BASE 26 STRING: " << std::endl;
	std::getline(std::cin, b);

	// output the resultant data
	std::cout << "THE RESULT IS: " << getBase26(getBase10(a)*getBase10(b)) << std::endl;

	system("PAUSE");
	return 0;

}

// function to convert from base 26 to base 10
int getBase10(std::string input) {

	// integer to store the ouput
	int result = 0;

	// put the input string into lower case to work with
	std::string key = input;
	std::transform(key.begin(), key.end(), key.begin(), ::tolower);

	// the power to multiply by for each level
	int power = 0;

	// loop through the string in reverse
	for (int i = key.size()-1; i >= 0; i--) {
		// add the respective number of the current level to the output
		result += std::pow(26, power)*(key[i]-97);
		// increase the power modifier
		power++;
	}

	// return the resultant number
	return result;

}

// convert a base 10 number to a base 26
std::string getBase26(int input) {

	// string for the function to return
	std::string result;	

	// integer to store the current number
	int cur = input;

	// keep looping while the current number isn't 0
	while (cur > 0) {
		// add the current number to the front of the string
		char temp = cur % 26 + 97;
		result = temp + result;
		// divide the current number by 26
		cur /= 26;
	}

	// return the resultant string
	return result;

}