/*	justify left/right program
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	
	// file to read from
	std::fstream iFile;
	iFile.open("text.txt");

	// temporary file to store output
	std::fstream oFile;
	oFile.open("temp.txt");

	// integer to store the direction of the justify direction
	int dir;
	
	// ask the user for the direction
	std::cout << "Which way would you like to justify the text?" << std::endl;
	std::cout << "[1]:left       [2]:right" << std::endl;
	std::cin >> dir;

	// string to store the current line
	std::string tLine;
	
	// loop through the file as long as there are still lines
	while (std::getline(iFile,tLine)) {
		if (dir == 1) {		// left
			// write the data into the output file
			oFile << std::left << tLine << std::endl;
		}
		else {				// right
			//write the data into the output file
			oFile << std::right << std::setw(10) << tLine << std::endl;
		}
	}

	// replace the content of both files
	iFile.swap(oFile);

	// close file streams and delete temp file
	iFile.close();
	oFile.close();

	std::remove("temp.txt");

	system("PAUSE");
	return 0;

}