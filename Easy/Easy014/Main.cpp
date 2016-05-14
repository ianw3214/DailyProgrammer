/*	list reversing program
*/

#include <iostream>
#include <vector>
#include <string>

// function declaration
void reverseBlock(std::vector<std::string>*, int);

// entry point
int main(int argc, char* argv[]) {

	// the vector to store the input 
	std::vector<std::string> input = {"1", "2", "3", "4", "5", "6"};

	// apply the reverse function to the input vector
	reverseBlock(&input, 4);

	// loop through the vector and print the result
	for (unsigned int i = 0; i < input.size();i++) {
		// print the element
		std::cout << input.at(i) << " ";
	}

	system("PAUSE");
	return 0;

}


// reverse the vector every every few numbers
void reverseBlock(std::vector<std::string> *inp, int k)
{
	
	// create a temporary vector to store the resultant vector
	std::vector<std::string> temp;

	// loop through every interval of the vector
	for (int i = 0; i < inp->size(); i+=k) {
		int counter;
		if ((inp->size()-i) < k) {			// if there arent enough elements left in the vector
			counter = inp->size() - i;		// loop less times
		}
		else {
			counter = k;					// loop the specified amount of times
		}

		// loop through each interval
		for (int j = counter; j > 0; j --) {
			temp.push_back(inp->at(i + j-1));	// insert the corresponding value
		}
	}

	// replace the vector with the final vector
	*inp = temp;

	return;

}
