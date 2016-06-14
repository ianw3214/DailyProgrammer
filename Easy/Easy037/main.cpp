/*	Line count Program
 *
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::fstream inpFile;
	inpFile.open("inp.txt");
	
	// integers to hold the amount of lines and words from the text file
	int lCount = 0, wCount = 0;

	// loop through the file lines until there are no more
	std::string temp;
	while (std::getline(inpFile, temp)) {
		lCount++;
		// loop through each character in the string
		for (int i = 0; i < temp.size(); i++) {
			// if the character is a space or it is the last character, add to word count
			if (temp[i] ==' ' || i == (temp.size()-1)) {
				wCount++;
			}
		}
	}

	std::cout << "LINES: " << lCount << std::endl;
	std::cout << "WORDS: " << wCount << std::endl;

	return 0;

}