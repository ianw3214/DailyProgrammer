/*	quiz program
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

struct Question {
	std::string q;
	std::string a;
};

// function declarations
bool loadData(std::string, std::vector<Question>*);
Question getQuestion(std::string);
void quiz(const std::vector<Question>);

// entry point
int main() {

	// make sure the user knows how to exit ;)
	std::cout << "please type 'exit' to exit the application." << std::endl;

	// vector to store the data from the txt
	std::vector<Question> questions;
	
	// initialize the vector from the text file
	if (loadData("key.txt", &questions)) {
		// if the txt file loaded correctly, start the quiz
		quiz(questions);
	}
	else {
		// output that an error occured
		std::cout << "AN ERROR OCCURED WHILE OPENING THE FILE..." << std::endl;
	}

	system("PAUSE");
	return 0;

}

// function that loads data from a file into a vector
bool loadData(std::string path, std::vector<Question> * qList) {

	// get the targeted file and open it
	std::fstream keyFile;
	keyFile.open(path);

	// make sure the file is open
	if (keyFile.is_open()) {

		// string to store each line while function is looping
		std::string cLine;

		// keep getting lines from the text file until there is not more
		while (std::getline(keyFile, cLine)) {
			// push the question structure into the input vector
			qList->push_back(getQuestion(cLine));
		}

		// close the file
		keyFile.close();

		// return success
		return true;

	}

	// return failure if the code didn't run inside the if loop
	return false;

}

// function that returns a struct type from an input string
Question getQuestion(std::string input) {
	
	// strings to store the output data
	std::string q, a;

	// boolean to determine if character belings in question or answer
	bool question = true;

	// loop through the input string
	for (unsigned int i = 0; i < input.size(); i++) {
		// if the current character is a question
		if (question) {
			// if the current character is a question mark
			if (input[i] == '?') {
				// switch the function to start putting into answer string
				question = false;
			}
			else {
				// add the current character to the output string
				q += input[i];
			}
		}
		// if the current character belongs in the answer string
		else {
			// add the current character to the output string
			a += input[i];
		}
	}
	
	// if the input never switched to an answer
	if (question) {
		// return a question without an answer
		return {input, "NO ANSWER"};
	}

	// return the question and answer together
	return{ q, a };

}

// function that runs the quiz
void quiz(const std::vector<Question> qList) {

	// string to store user inputs
	std::string input;

	// initialize the random seed
	srand(time(NULL));

	// boolean to determine whether the question repeats
	bool repeat = false;

	// number to determine the number of each question for each loop
	int qNum;

	// run the quiz code
	do {
		// get the random number to determine question as long as the question isn't repeated
		if(!repeat) qNum = rand() % (qList.size());
		// output the question for that number
		std::cout << qList[qNum].q << std::endl;
		// prompt the user for an input
		std::cout << "Please type in your answer:" << std::endl;
		std::getline(std::cin, input);
		// determine whether the answer is right or wrong and set the repeat to match the result
		if (input == qList[qNum].a) {
			std::cout << "That is correct! Moving on..." << std::endl;
			repeat = false;
		}
		// otherwise the answer is incorrect
		else {
			std::cout << "Sorry that is the wrong answer!" << std::endl;
			repeat = true;
		}

	} while (input != "exit");	// quit when the user types exit

	return;

}