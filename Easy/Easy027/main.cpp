/*	century calculating program
*/

#include <iostream>
#include <string>

// function declarations
std::string isLeapYear(int);

int main() {

	// variable to store the user input
	int inp;

	// prompt the user for an input
	std::cout << "please enter a year" << std::endl;
	std::cin >> inp;

	// output the result
	std::cout << "Century: " << inp/100+1 << std::endl;
	std::cout << "Leap year: " << isLeapYear(inp) << std::endl;

	system("PAUSE");
	return 0;

}

// function to see if the year is a leap year
std::string isLeapYear(int inp) {

	// if the year is divisible by 4
	if (inp % 4 == 0) {
		return "YES";
	}

	// return no if code runs to this part
	return "NO";

}