/*	Number Sorting Program 
*/

#include <iostream>
#include <vector>

// function declarations
std::vector<char> sort(std::vector<char>);
void printVector(std::vector<char>);

// entry point
int main(int argc, char* argv[]) {

	// vector to hold the inputs of the user
	std::vector<char> vNum;
	bool quit = false;		// the boolean to hold whether the user wants to quit or not
	char uInput;			// character to hold the users input

	while (!quit) {			// while the user doesn't want to quit
		// prompt the user to enter the characters to the program
		std::cout << "PLEASE ENTER THE CHARACTER YOU WANT TO SORT: " << std::endl;
		std::cout << "ENTER [q] TO QUIT" << std::endl;
		std::cin >> uInput;
		std::cout << std::endl;

		if (uInput == 'q' || uInput == 'Q') {
			std::cout << "LEAVING THE APPLICATION..." << std::endl;
			quit = true;
		}
		else {
			std::cout << "ADDED " << uInput << " TO LIST" << std::endl;
			vNum.push_back(uInput);
		}

		// sort the vector and print it
		vNum = sort(vNum);
		printVector(vNum);

	}

	system("PAUSE");
	return 0;

}

// function to sort the characters of the vector
std::vector<char> sort(std::vector<char> input) {

	// vector to return to the user
	std::vector<char> finalVector = input;

	// make a container to hold the size of the vector
	std::vector<char>::size_type sz = input.size();

	// loop through the elements of the vector
	for (int i = 0; i < (sz-1); i++) {
		// loop each element to swap characters
		for (int j = 0; j < (sz - 1); j++) {
			
			// temporary characters for calculating
			char a = finalVector.at(j);
			char b = finalVector.at(j+1);
			// boolean to store whether to flip numbers or not
			bool switchChars = false;					

			// decide whether to switch the characters or not
			if ( a<58 && b>64 ) {									// if its a number and then an alphabet
				switchChars = true;
			}
			else {													// not a number then alphabet
				if ( a<58 && b<58) {								// if both characters are numbers
					if (a > b) {
						switchChars = true;
					}
				}
				else if(a>64 && b>64){								// both characters are letters
					// check if they are the same letter first
					if (a == b || a==(b+32) || a==(b-32)) {
						if (a > b) {								// switch if the capitol letter is after the lower case
							switchChars = true;
						}
					}
					else {
						// convert both to the upper case
						if (a > 96) {
							a -= 32;
						}
						if (b > 96) {
							b -= 32;
						}
						if (a > b) {
							switchChars = true;
						}
					}
				}
			}

			// code to switch the places of the characters
			if (switchChars) {										// if a is bigger than b	
				char c = finalVector.at(j);							// use a temp char because we altered a and b
				finalVector.at(j) = finalVector.at(j+1);
				finalVector.at(j+1) = c;
			}

		}

	}

	return finalVector;

}

// function to print vector elements
void printVector(std::vector<char> input) {

	// make a container to hold the size of the vector
	std::vector<char>::size_type sz = input.size();

	// loop through all the elements of the vector
	for (int i = 0; i < sz; i++) {
		// output the value 
		std::cout << input.at(i) << "  ";
	}

	std::cout << std::endl;

	return;
}