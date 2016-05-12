/*	list program

	because heterogenous lists are harder to implement in c++, I am using integer vectors instead

*/

#include <iostream>
#include <vector>

// function declaration
void splitIntoTwo(std::vector<int>, std::vector<int>*, std::vector<int>*);
void showVector(std::vector<int>);

int main(int argc, char* argv[]) {

	// input vector
	std::vector<int> inp = {5, 10, 3, 6, 61, 234};

	// two output vectors
	std::vector<int> out1, out2;

	// split the vector and store it
	splitIntoTwo(inp, &out1, &out2);

	// output the result
	std::cout << "VECTOR 1: ";
	showVector(out1);
	std::cout << "VECTOR 2: ";
	showVector(out2);

	system("PAUSE");
	return 0;

}

// function to split a vector into two and put them into two seperate vectors
void splitIntoTwo(std::vector<int> inp, std::vector<int>* o1, std::vector<int>* o2) {

	// loop through the input vector 
	for (int i = 0; i < inp.size(); i++) {
		// if the counter is even, put into 1 vecor
		if (i%2 == 0) {
			o1->push_back(inp.at(i));
		}
		// if it is odd, put into the other
		if (i%2 == 1) {
			o2->push_back(inp.at(i));
		}
	}

	// exit the function
	return;

}

// function to show the contents of a vector
void showVector(std::vector<int> inp) {

	// loop through the input vector
	for (int i = 0; i < inp.size(); i++) {
		// print the data to the screen
		std::cout << inp.at(i) << " ";
	}

	// break a new line
	std::cout << std::endl;

	return;

}