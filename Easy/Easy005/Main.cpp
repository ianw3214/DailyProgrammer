/*	Password Protection Program
*/

#include <iostream>
#include <fstream>
#include <string>

bool checkInput(std::string, std::string);

int main(int argc, const char* argv[]) {

	std::string iUsername, iPassword;
	bool success;

	// have the user input his/her username and password
	std::cout << "Please enter your username:";
	std::getline(std::cin, iUsername);
	std::cout << "Please enter your password:";
	std::getline(std::cin, iPassword);

	// store in a boolean the success of the user/pass combination
	success = checkInput(iUsername, iPassword);

	// show the user the result
	if (success) {
		std::cout << "ACCESS GRANTED" << std::endl;
	}
	else {
		std::cout << "ACCESS DENIED, SYSTEM SHUTTING DOWN..." << std::endl;
	}

	system("PAUSE");
	return 0;

}

bool checkInput(std::string user, std::string pass) {
	
	// variables to store the real combination
	std::string rUser, rPass;

	// open the file that stores the username and password
	std::ifstream key;
	key.open("db.txt");

	// store the info to the variables
	std::getline(key, rUser);
	std::getline(key, rPass);

	// compare the input to the key
	if (rUser == user && rPass == pass) {
		return true;
	}
	else {
		return false;
	}

	std::cout << "SYSTEM ERROR" << std::endl;
	return false;

}