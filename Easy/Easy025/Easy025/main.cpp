/*	vote result program
*/

#include <iostream>
#include <vector>
#include <string>

// structure to store the party and its respective votes
struct vote {
	std::string party;
	int votes;
};

// function declarations
std::string getWinner(std::vector<vote>);

int main(int argc, char* argv[]) {

	// initialize a vector for the votes
	std::vector<vote> votes = { {"PARTY A", 10}, {"PARTY B", 15}, {"PARTY C", 15} };

	// show the results
	std::cout << "ELECTION RESULTS: " << getWinner(votes) << std::endl;

	system("PAUSE");
	return 0;

}

// function to determine the winner and print it out
std::string getWinner(std::vector<vote> inp){

	// vote struct to hold current highest votes
	// initialize it at the vote count for the first party of the vector
	vote cWin = inp.at(1);

	// boolean to store if highest is a tie
	bool tie = false;

	// loop through the vector
	for (unsigned int i = 1; i < inp.size(); i++) {	// start from the second
		// if the current one has more votes than the previous
		if (inp.at(i).votes > cWin.votes) {
			// change the winning party to current party
			cWin = inp.at(i);
			// set the tie boolean to false
			tie = false;
		}
		// if the current votes is the same as the highest
		else if(inp.at(i).votes == cWin.votes){
			// set the tie boolean to true
			tie = true;
		}
	}

	// if there isn't a tie
	if (!tie) {
		// return the name of the winning party
		return cWin.party;
	}

	// return no winners otherwise
	return "NO WINNERS";

}