/*	Duplicate finding program
*/

#include <iostream>
#include <vector>

// function declarations
int getDuplicate(std::vector<int>);

int main() {

	// the vector to put through the function
	std::vector<int> input = { 1, 5, 6, 7, 2, 3, 4, 9, 2};

	// run the function and store to an integer
	int output = getDuplicate(input);

	// output the result
	std::cout << "The duplicate of the vector is: " << output << std::endl;

	system("PAUSE");
	return 0;

}

// function to return 1 duplicate number in an array
int getDuplicate(std::vector<int> inp) {

	// loop through the input vector
	for (int i = 0; i < inp.size(); i++) {
		// loop through the rest of the vector from the next element
		for (int j = i + 1; j < inp.size(); j++) {
			// if the two elements are the same
			if (inp.at(i) == inp.at(j)) {
				// return the number
				return inp.at(i);
			}
		}
	}

	// there are no duplicates if the function runs here
	return 0;

}