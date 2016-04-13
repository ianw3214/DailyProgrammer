/*	permutation program
*/

#include <iostream>
#include <vector>
#include <string>

// function declarations
void permute(std::string, std::string, std::vector<std::string>*);

// entry point
int main(int argc, char* argv[]) {

	std::string input;					// string that contains the user input
	std::vector<std::string> vFinal;	// vector that contains the final vector with permutations

	// prompt the user to input a string to calculate permutations
	std::cout << "Please enter the string you would like to permute:" << std::endl;
	std::getline(std::cin, input);
	std::cout << std::endl;

	// push the input to the permute function
	permute(input, "", &vFinal);

	for (int i = 0; i < vFinal.size(); i++) {
		std::cout << vFinal.at(i) << std::endl;
	}

	system("PAUSE");
	return 0;

}

// function to calculate each permutation of the input string (recursive)
void permute(std::string input, std::string current, std::vector<std::string>* vFinal) {
	// input is the rest of the string to loop through
	// current is the current string that is being calculated
	// vFinal is the vector that results will be pushed onto

	// loop through each element of the input
	for (int i = 0; i < input.size(); i++) {
		if (input.size() == 1) {	// if this is the last character of the loop
			
			// add the last character to the current string
			current += input[i];

			// add the result to the vector
			vFinal->push_back(current);

		}
		else {						// continue on with the permutation loop

			// new string to pass as the current string
			std::string newCur = current + input[i];

			// new string to pass as an input
			std::string newInp = input;
			newInp.erase(i, 1);

			// call this function again
			permute(newInp, newCur, vFinal);
		}
	}
}