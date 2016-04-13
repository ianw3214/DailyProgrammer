/*	99 bottles of beer on the wall 
	Lyric Program
*/

#include <iostream>

// function declarations
void printSong();

int main(int argc, char* argv[]) {
	
	// call the function to print the song
	printSong();

	system("PAUSE");
	return 0;

}

// put the lyric printing program in a seperate function
void printSong() {
	// loop through each number of the song
	for (int i = 99; i >= 0; --i) {			// include 0 for when the song reaches the last line
		if (i==0) {
			std::cout << "No more bottles of beer on the wall, no more bottles of beer. " << std::endl;
			std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall." << std::endl;
			std::cout << std::endl;
		}
		else if (i==1){
			std::cout << "1 bottle of beer on the wall, 1 bottle of beer." << std::endl;
			std::cout << "Take one down and pass it around, no more bottles of beer on the wall." << std::endl;
			std::cout << std::endl;
		}
		else {
			std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer." << std::endl;
			std::cout << "Take one down and pass it around, "<< --i <<" bottle of beer on the wall." << std::endl;
			// std::cout << std::endl;
		}
	}
	return;
}