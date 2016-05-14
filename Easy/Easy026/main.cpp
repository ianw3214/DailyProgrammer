/*	duplicate splice program
*/

#include <iostream>
#include <string>

// function declarations
std::string removeDuplicate(std::string*);
std::string reverse(std::string);

int main(int argc, char* argv[]) {

	// string to put through the code 
	std::string input = "ddaaiillyypprrooggrraammeerr";

	// output the result
	std::cout << removeDuplicate(&input) << " : " << input << std::endl;

	system("PAUSE");
	return 0;

}

// function to remove duplicates out of a string
std::string removeDuplicate(std::string* inp) {

	// string to output
	std::string duplicates = "";

	// loop through the characters of the string in reverse
	for (unsigned int i = inp->size()-1; i > 0; i--) {
		// compare the current character to the previous
		if (inp->at(i) == inp->at(i-1)) {
			// add the current character to the output string
			duplicates += inp->at(i);
			// remove the character from the original string
			inp->erase(i,1);
		}
	}

	// reverse the output string
	duplicates = reverse(duplicates);

	// return the result
	return duplicates;

}

// function to reverse a string
std::string reverse(std::string inp) {

	// string to output
	std::string result = "";

	// loop through the input backwards
	for (int i = inp.size() - 1; i >= 0; i--) {
		// insert the character into the output string
		result += inp[i];
	}

	// return the result
	return result;

}