/*	character count program
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

	// open the file
	std::ifstream file;
	file.open("story.txt");

	// integer to store the final value
	int count = 0;

	// string to store current line
	std::string line;

	// loop through each line
	while (std::getline(file, line)) {
		// go through each character
		for (unsigned int i = 0; i < line.size(); i++) {
			// if the character is a number, uppercase or lowercase letter
			if ((line[i]>47&&line[i]<58) || (line[i]>64 && line[i]<91) || (line[i]>96 && line[i]<123)) {
				count++;		// add to the count
			}
		}
	}

	std::cout << "There are " << count << "alphanumeric characters in the story." << std::endl;

	// close the file
	file.close();

	system("PAUSE");
	return 0;

}