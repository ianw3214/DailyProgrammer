/*	Reverse Number Guessing Game
*/

#include <iostream>
#include <random>
#include <ctime>
#include <string>

// function declarations
int getGuess(int, int);
void playGame();

int main(int argc, const char* argv[]) {

	// boolean to decide whether to keep playing the game or not
	bool quit = false;
	std::string userInput;

	std::cout << "Welcome to a the number guessing game!" << std::endl;

	while (!quit) {
		playGame();														// play the game
		std::cout << "Would you like to quit the game?" << std::endl;	// ask the user to keep playing
		std::cout << "[y] / [n]" << std::endl;
		std::getline(std::cin, userInput);								// get the user input
		if (userInput[0] == 'y' || userInput[0] == 'Y') {				// quit the game on the next loop if the user says yes
			quit = true;
		}
		else {
			std::cout << "TIME FOR ANOTHER ROUND!!" << std::endl;
		}
	}

	system("PAUSE");
	return 0;

}

// function to handle the number that the AI will guess
int getGuess(int min, int max) {

	int range = max - min + 1;
	int guess = std::rand() % range;
	return min + guess;

}

// function that handles the game state
void playGame() {
	
	// initialize the seed for random number generation
	std::srand(std::time(0));

	bool gameWon = false;			// boolean to store the result of the game
	int min = 1, max = 100;			// integers to store the possible values to guess from
	std::string userInput;			// string to store the input from the user

	std::cout << "Please think of a number between 1 to 100" << std::endl;
	system("PAUSE");		// give the user time to decide on the number
	std::cout << std::endl;

	// the AI only gets 6 turns to guess the number of the user
	for (int i = 0; i < 6; i++) {
		// the guess of the AI this turn
		int thisGuess = getGuess(min, max);
		std::cout << "Is your number: " << thisGuess << std::endl;

		// get a response from the user for the number
		std::cout << "type [h] if it is bigger, [l] if it is lower, or [w] if I guessed right!" << std::endl;
		std::getline(std::cin, userInput);

		// check the input for letters of both cases
		if (userInput[0] == 'h' || userInput[0] == 'H') {
			min = thisGuess;	// make the next guesses higher than the current guess
		}
		else if (userInput[0] == 'l' || userInput[0] == 'L') {
			max = thisGuess;	// make the next guesses lower than the current guess
		}
		else if (userInput[0] == 'w' || 'W') {
			gameWon = true;		// change the boolean so the results will show later
			break;				// break out of the for loop to stop the AI from guessing
		}
		else {
			std::cout << "Sorry i did not understand that input..." << std::endl;
			i--;	// make sure to take one of the counter if there was nothing played that turn
		}

	}

	// output the result of the game to the player
	if (gameWon) {
		std::cout << std::endl;
		std::cout << "HAHAHAHAHAHAHAHAHAHAHAHAHAHA" << std::endl;
		std::cout << "+---------I WIN------------+" << std::endl;
		std::cout << "HAHAHAHAHAHAHAHAHAHAHAHAHAHA" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "congratulations, you win the game!" << std::endl;
		std::cout << std::endl;
	}

	return;

}