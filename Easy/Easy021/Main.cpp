/*	number program
*/

#include <iostream>
#include <vector>
#include <string>

// function declarations
void permute(std::string, std::string, std::vector<std::string>*);
std::vector<int> vToInt(std::vector<std::string>);
int findBigger(std::vector<int>, int);
int getMax(std::vector<int>);

int main(int argc, char* argv[]) {

	// prompt the user to enter a number
	std::cout << "Please enter a number:" << std::endl;
	int inp;
	std::cin >> inp;

	// convert the input number to a string
	std::string sInp = std::to_string(inp);

	// set up a vector and get the permutations
	std::vector<std::string> permutations;
	permute(sInp, "", &permutations);

	// the run the function to find the bigger number after converting the values from type string to int
	int result = findBigger(vToInt(permutations), inp);

	// output the result
	std::cout << "The next number with those digits is: " << result << std::endl;

	system("PAUSE");
	return 0;

}

// function to calculate each permutation of the input string (recursive)
void permute(std::string input, std::string current, std::vector<std::string>* vFinal) {
	// input is the rest of the string to loop through
	// current is the current string that is being calculated
	// vFinal is the vector that results will be pushed onto

	// loop through each element of the input
	for (unsigned int i = 0; i < input.size(); i++) {
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

// function to convert a string vector to an int vector
std::vector<int> vToInt(std::vector<std::string> inp) {

	// final vector to store int values
	std::vector<int> output;

	// loop through the input vector
	for (unsigned int i = 0; i < inp.size(); i++) {
		// convert the string to an integer
		int temp = std::atoi(inp.at(i).c_str());
		// push the integer to the vector
		output.push_back(temp);
	}

	// return the final integer vector
	return output;

}

// function to find the next biggest int from the same set of permutations 
int findBigger(std::vector<int> vInp, int inp) {

	// integer to store the final integer
	// initlialized to the biggest number in the vector
	int result = getMax(vInp);

	// loop through the vector
	for (unsigned int i = 0; i < vInp.size(); i++) {

		// if the number is bigger than the input
		if (vInp.at(i)>inp) {
			// if the number is smaller than the current result but is not the input
			if (vInp.at(i) < result && vInp.at(i) != inp) {
				result = vInp.at(i);	// set the result equal to that number
			}
		}

	}

	// return the final number
	return result;

}

// function to get the biggest number from a vector
int getMax(std::vector<int> vInp) {

	// integer to store the result
	int result = 0;	// initialize to 0

	// loop through the vector
	for (unsigned int i = 0; i < vInp.size(); i++) {
		// if the current number is bigger than the current result
		if (vInp.at(i)>result) {
			// update the result
			result = vInp.at(i);
		}
	}

	// return the final number
	return result;

}