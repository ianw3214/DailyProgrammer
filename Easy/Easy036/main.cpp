/*	1000 lockers problem

*/

#include <iostream>
#include <vector>

// entry point
int main() {

	// initialize vector
	std::vector<bool> lockers;
	
	// create lockers 1 through 1000
	for (int i = 1; i <= 1000; i++) {
		lockers.push_back(false);
	}

	// loop through each student
	for (int i = 1; i <= 1000; i++) {
		// loop through each multiple
		for (int j = 1; j*i <= 1000; j++) {
			// toggle the lockers
			if (lockers.at(j*i-1) ==true) {
				lockers.at(j*i - 1) = false;
			}
			else {
				lockers.at(j*i - 1) = true;
			}
		}
	}


	std::cout << "open lockers: ";

	// output the result
	for (int i = 0; i < lockers.size(); i++) {
		if (lockers.at(i)) {
			std::cout << i+1 << ", ";
		}
	}

	std::cout << std::endl;

	system("PAUSE");
	return 0;

}