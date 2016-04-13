/*	Physics Force Application
*/

#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {

	std::string input;

	std::cout << "select the value you want to solve for:" << std::endl;
	std::cout << "[f]force, [m]mass, [a]acceleration" << std::endl;
	std::getline(std::cin, input);

	// store the first letter of the input into a char
	char key = input[0];
	
	switch (key) {
	case 'f':
		float mf, af;
		std::cout << "Please input the mass: ";
		std::cin >> mf;
		std::cout << "Please input the acceleration: ";
		std::cin >> af;
		std::cout << std::endl;

		std::cout << "The force is " << mf*af << std::endl;
		break;
	case 'm':
		float fm, am;
		std::cout << "Please input the force: ";
		std::cin >> fm;
		std::cout << "Please input the acceleration: ";
		std::cin >> am;
		std::cout << std::endl;

		std::cout << "The mass is " << fm/am << std::endl;
		break;
	case 'a':
		float fa, ma;
		std::cout << "Please input the force: ";
		std::cin >> fa;
		std::cout << "Please input the mass: ";
		std::cin >> ma;
		std::cout << std::endl;

		std::cout << "The acceleration is " << fa / ma << std::endl;
		break;
	default:
		std::cout << "Sorry, that was not a valid input..." << std::endl;
	}

	system("PAUSE");

	return 0;

}