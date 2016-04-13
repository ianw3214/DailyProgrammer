/*	MORSE CODE PROGRAM
*/

#include <iostream>
#include <string>
#include <vector>

// function declarations
std::vector<std::string> seperateCode(std::string);
std::vector<std::vector<std::string>> seperateWord(std::vector<std::string>);
std::vector<std::vector<char>> parseInput(std::vector<std::vector<std::string>>);
std::string toString(std::vector<std::vector<char>>);

int main(int argc, const char* argv[]) {

	// string of code to decipher
	std::string code = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--";

	// seperate code string
	std::vector<std::vector<std::string>> inputCode = seperateWord(seperateCode(code));

	// parse the code
	std::vector<std::vector<char>> charCode = parseInput(inputCode);

	// output the result to the user
	std::string finalCode = toString(charCode);
	std::cout << finalCode << std::endl;

	system("PAUSE");
	return 0;

}

// function for the initial seperation of the code
std::vector<std::string> seperateCode(std::string input) {

	std::vector<std::string> output; 	// variable to return the final output in
	std::string tempString = "";		// string to temporarily store the characters in

	for (unsigned int i = 0; i < input.size(); ++i) {
		char tempChar = input[i];
		if (tempChar=='/' || i == (input.size()-1)) {	// added or statement to make sure the last word is included as well
			if (tempChar != '/') {						// make sure to include the last character if it is not a space
				tempString += input[i];
			}
			output.push_back(tempString);
			tempString = "";
		}
		else{
			tempString += input[i];
		}
	}

	return output;

}

// function for the secondary seperation of the code
std::vector<std::vector<std::string>> seperateWord(std::vector<std::string> input) {

	std::vector<std::vector<std::string>> output;	// variable to return the final output in
	
	int vCounter = 0;		// counter to keep track of loop to access data
	for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++) {	// iterate through each string in the vector

		std::string tempString = input.at(vCounter);	// string to hold the current vector string
		std::vector<std::string> tempVector;			// vector to store the temporary data
		std::string outString = "";						// string to hold the string to insert into output vector

		// iterate through each character in the string
		for (unsigned int i = 0; i < it->size(); i++) {
			char tempChar = tempString[i];
			if ((tempChar==' ' || i == (it->size()-1)) && i!=0) {	// seperate at spaces and dont run once for the first space
																	// also run for the last character in case it is not a white space
				// make sure there are no spaces on either side of the string
				if (outString[0] == ' ') {	
					outString.erase(0, 1);
				}
				if (outString[outString.size() - 1] != ' ' && i == (it->size() - 1)) {
					outString += tempChar;
				}
				if (outString[outString.size() - 1] == ' ') {
					outString.erase(outString.size() - 1, 1);
				}
				std::cout << outString << std::endl;
				// push the string into the vector
				tempVector.push_back(outString);
				outString = "";		// clear the temporary string
			}
			else {
				outString += tempChar;
			}
		}

		output.push_back(tempVector);	// push the current vector into the final vector

		// increase the counter to keep track of vector position
		vCounter++;
	}

	return output;

}

// function to change the strings in the input to characters
std::vector<std::vector<char>> parseInput(std::vector<std::vector<std::string>> input) {

	std::vector<std::vector<char>> output;	// the vector for the function to output

	int counter = 0;		// counter integer to keep track of position in vector
	// loop through the first level of the vector
	for (std::vector<std::vector<std::string>>::iterator it = input.begin(); it != input.end(); ++it) {

		std::vector<char> tempVector;	// temporary vector to store current word letters in

		int counter2 = 0;	// counter integer to keep track of position in vector
		// loop through the second level of the vector
		for (std::vector<std::string>::iterator it2 = input.at(counter).begin(); it2 != input.at(counter).end(); ++it2) {
			std::string tempString = input.at(counter).at(counter2);
			if (tempString == ".-") {
				tempVector.push_back('A');
			}
			else if (tempString == "-...") {
				tempVector.push_back('B');
			}
			else if (tempString == "-.-.") {
				tempVector.push_back('C');
			}
			else if (tempString == "-..") {
				tempVector.push_back('D');
			}
			else if (tempString == ".") {
				tempVector.push_back('E');
			}
			else if (tempString == "..-.") {
				tempVector.push_back('F');
			}
			else if (tempString == "--.") {
				tempVector.push_back('G');
			}
			else if (tempString == "....") {
				tempVector.push_back('H');
			}
			else if (tempString == "..") {
				tempVector.push_back('I');
			}
			else if (tempString == ".---") {
				tempVector.push_back('J');
			}
			else if (tempString == "-.-") {
				tempVector.push_back('K');
			}
			else if (tempString == ".-..") {
				tempVector.push_back('L');
			}
			else if (tempString == "--") {
				tempVector.push_back('M');
			}
			else if (tempString == "-.") {
				tempVector.push_back('N');
			}
			else if (tempString == "---") {
				tempVector.push_back('O');
			}
			else if (tempString == ".--.") {
				tempVector.push_back('P');
			}
			else if (tempString == "--.-") {
				tempVector.push_back('Q');
			}
			else if (tempString == ".-.") {
				tempVector.push_back('R');
			}
			else if (tempString == "...") {
				tempVector.push_back('S');
			}
			else if (tempString == "-") {
				tempVector.push_back('T');
			}
			else if (tempString == "..-") {
				tempVector.push_back('U');
			}
			else if (tempString == "...-") {
				tempVector.push_back('V');
			}
			else if (tempString == ".--") {
				tempVector.push_back('W');
			}
			else if (tempString == "-..-") {
				tempVector.push_back('X');
			}
			else if (tempString == "-.--") {
				tempVector.push_back('Y');
			}
			else if (tempString == "--..") {
				tempVector.push_back('Z');
			}
			else if (tempString == "-----") {
				tempVector.push_back('0');
			}
			else if (tempString == ".----") {
				tempVector.push_back('1');
			}
			else if (tempString == "..---") {
				tempVector.push_back('2');
			}
			else if (tempString == "...--") {
				tempVector.push_back('3');
			}
			else if (tempString == "....-") {
				tempVector.push_back('4');
			}
			else if (tempString == ".....") {
				tempVector.push_back('5');
			}
			else if (tempString == "-....") {
				tempVector.push_back('6');
			}
			else if (tempString == "--...") {
				tempVector.push_back('7');
			}
			else if (tempString == "---..") {
				tempVector.push_back('8');
			}
			else if (tempString == "----.") {
				tempVector.push_back('9');
			}
			else {
				tempVector.push_back('*');
			}

			counter2++;	// increase the counter
		}

		output.push_back(tempVector);	// add the current vector to the final output vector
		counter++;			//increase the counter

	}

	return output;	// return the final vector

}

std::string toString(std::vector<std::vector<char>> input) {

	std::string output;		// string to store the final output in

	int counter = 0;		// counter variable to keep track of position in vector
	// iterate through the first vector
	for (std::vector<std::vector<char>>::iterator it = input.begin(); it != input.end(); ++it) {

		int counter2 = 0;	// counter variable to keep track of position in vector
		// iterate through second vector
		for (std::vector<char>::iterator it2 = input.at(counter).begin(); it2 != input.at(counter).end(); ++it2) {
			output += input.at(counter).at(counter2);	// push the char to the output string
			counter2++;
		}

		output += ' ';		// add a blank space behind each word
		counter++;

	}

	return output;
}