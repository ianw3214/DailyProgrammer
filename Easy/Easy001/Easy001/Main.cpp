#include <iostream>
#include <fstream>
#include <string>

void saveToFile(std::string);
void printFileData();

int main(int argc, const char* argv[]) {
	
	// variables to store the inputs
	std::string name, sAge, uName, fString;

	// gather the information from the user
	std::cout << "What is your name?" << std::endl;
	std::getline(std::cin, name);
	std::cout << "How old are you?" << std::endl;
	std::getline(std::cin, sAge);
	std::cout << "What is your reddit username?" << std::endl;
	std::getline(std::cin, uName);

	// show the information onto the screen
	fString = "Your name is " + name + ", you are " + sAge + " years old, and your reddit username is " + uName;
	std::cout << fString << std::endl;

	// log the output to a text file
	saveToFile(fString);

	// show the contents of the text file
	printFileData();

	system("PAUSE");
	return 0;
	
}

// function to save the data to a text file
void saveToFile(std::string input) {
	std::ofstream myFile;
	myFile.open("log.txt", std::ios_base::app);
	myFile << input << std::endl;
	myFile.close();	
	return;
}

// function to output the text file data
void printFileData() {
	std::string line; // string to store each line of the text file
	std::ifstream myFile;
	myFile.open("log.txt");
	while (std::getline(myFile, line)) {
		std::cout << line << std::endl;
	}
	myFile.close();
	return;
}