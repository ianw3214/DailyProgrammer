/*	Day of the week calculating program
*/

#include <iostream>
#include <ctime>

// array to hold the names of the weekdays
char* days[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

int main(int argc, char* argv[]) {

	// the time structure for the user to input into
	tm * inputTime;							// using pointer so it can be accessed by mktime function
	// integer to handle the inputs from the user
	int userInput;

	// initialize the struct tm
	time_t rawTime;
	time(&rawTime);
	inputTime = localtime(&rawTime);

	// prompt the user to input the time info
	std::cout << "CALCULATE DAY OF THE WEEK FROM TIME:" << std::endl << std::endl;
	std::cout << "please input the day of the month" << std::endl;
	std::cin >> userInput;
	inputTime->tm_mday = userInput;			// get the day of the month from the user
	std::cout << "please input the month of the year" << std::endl;
	std::cout << "(input a number, 1 for jan, 2 for feb, etc...)" << std::endl;
	std::cin >> userInput;
	inputTime->tm_mon = userInput-1;		// get the month of the year from the user
	std::cout << "please input the year of the time you want" << std::endl;
	std::cout << "(2016, 2020, 3000, etc...)" << std::endl;
	std::cin >> userInput;
	inputTime->tm_year = userInput - 1900;	// get the year from the user

	// adjust the values for the tm structure
	mktime( inputTime );

	std::cout << "The day of the time is: "<< days[inputTime->tm_wday] << std::endl;

	system("PAUSE");
	return 0;

}