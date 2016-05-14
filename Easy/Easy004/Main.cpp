/*	Random Password Generator
*/

#include <iostream>
#include <string>
#include <ctime>

// function declarations
std::string getPassword(int);

int main(int varc, const char* args[]) {
	
	int passLength; // the length of the password

	// set the seed for the random numbers
	std::srand(std::time(0));

	// prompt the user to enter the number of characters in the password
	std::cout << "How many characters would you like in your password?" << std::endl;
	std::cin >> passLength;
	std::cout << std::endl << "Your Password: " << getPassword(passLength) << std::endl;

	system("PAUSE");
	return 0;

}

std::string getPassword(int size) {

	std::string charKey = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string returnString = "";

	for (int i = size; i > 0; i--) {
		int nKey = std::rand()%62;		// get the number we will use to decide what the character will be
		returnString += charKey[nKey];	// add the matching character to the string
	}

	return returnString;
}