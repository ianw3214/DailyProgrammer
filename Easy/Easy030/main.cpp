/*	sum determining program
*/

#include <iostream>
#include <vector>

struct result {
	int a;
	int b;
};

// function declarations
result sumNum(std::vector<int>, int);

// entry point
int main() {

	// input vector and wanted sum
	std::vector<int> input = { 5, 6, 7, 8, 9, 10};
	int SUM = 19;

	// run the function
	result output = sumNum(input, SUM);

	// if there is a result
	if (output.a != 0 && output.b != 0) {
		std::cout << "The two numbers that make up " << SUM << " are : " << output.a << " and " << output.b << std::endl;
	}
	else {
		std::cout << "There were no numbers that make up " << SUM << std::endl;
	}

	system("PAUSE");
	return 0;

}

// function that finds two numbers that add to a third number
result sumNum(std::vector<int> input, int key) {

	// loop through the input vector
	for (unsigned int i = 0; i < input.size()-1; i++) {
		// loop through the rest of the vector
		for (unsigned int j = 0; j < input.size(); j++) {
			// see if the two numbers add to form the wanted number
			if (input.at(i) + input.at(j) == key) {
				// return the two numbers
				return {input.at(i), input.at(j)};
			}
		}
	}

	// return an empty struct if there is no pair
	return{ 0, 0 };

}