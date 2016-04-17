/*	Day of year calculator
*/

// remove precomiler secure warnings
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <ctime>

int main(int argc, char* argv[]) {

	// get the current time into a tm structure
	time_t rawTime;
	struct tm * finalTime;
	time(&rawTime);
	finalTime = localtime(&rawTime);

	// adjust the time to the time to calculate
	finalTime->tm_mon = 3;		// 0-11
	finalTime->tm_mday = 1;		// 1-31

	// adjust all other details accordingly
	mktime(finalTime);

	// output the result
	std::cout << "That day is " << finalTime->tm_yday << " days into the year." << std::endl;

	system("PAUSE");
	return 0;

}