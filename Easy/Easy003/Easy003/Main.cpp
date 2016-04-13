/*	Caesar Cipher Program
*/

#include <iostream>
#include <string>

#define newLine std::cout<<std::endl;

// function declarations
std::string removeSymbols(std::string);
std::string encrypt(std::string);
std::string decrypt(std::string);

int main(int argc, const char* argv[]) {

	std::string inputString, fString, eString, dString;

	// request a string from the user
	std::cout << "please type the string you would like to by encrypted:" << std::endl;
	std::getline(std::cin, inputString);

	// remove all symbols from the string
	fString = removeSymbols(inputString);

	newLine;

	// encrypt the input string from the user and print it
	eString = encrypt(fString);
	std::cout << "The encrypted string is: " << std::endl << eString << std::endl;

	newLine;

	// decrypt the encrypted string and print it
	dString = decrypt(eString);
	std::cout << "The decrypted string is: " << std::endl << dString << std::endl;

	newLine;

	system("PAUSE");
	return 0;

}

// remove anything thats not a white space or a letter
std::string removeSymbols(std::string iString) {

	std::string fString;
	fString = iString;

	for (int i = fString.length() - 1; i >= 0; i--) {
		char key = fString[i];
		if (key!=32&&(key<65||key>90)&&(key<97||key>122)) {
			fString.erase(i, 1);
		}
	}

	return fString;
}

// shift all characters three letters to the left to encrypt
std::string encrypt(std::string iString) {

	std::string fString;
	fString = iString;

	for (unsigned int i = 0; i <= fString.length() - 1; i++) {
		char key = fString[i];
		if (key < 68 && key != 32) {
			fString[i] += 23;
		}
		else if (key < 91 && key != 32) {
			fString[i] -= 3;
		}
		else if (key < 100 && key != 32) {
			fString[i] += 23;
		}
		else if (key < 123 && key != 32) {
			fString[i] -= 3;
		}
	}

	return fString;

}

// shift all characters three letters to the right to encrypt
std::string decrypt(std::string iString) {

	std::string fString;
	fString = iString;

	for (unsigned int i = 0; i <= fString.length() - 1; i++) {
		char key = fString[i];
		if (key > 119 && key != 32) {
			fString[i] -= 23;
		}
		else if (key > 96 && key != 32) {
			fString[i] += 3;
		}
		else if (key > 87 && key != 32) {
			fString[i] -= 23;
		}
		else if (key > 64 && key != 32) {
			fString[i] += 3;
		}
	}

	return fString;

}