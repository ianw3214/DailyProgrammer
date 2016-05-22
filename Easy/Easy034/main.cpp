/*	basic algorithm program
	-the sum of the squares of the two larger numbers
*/

#include <iostream>

// entry point
int main() {

	// integers to store the three input variables
	int a, b, c;
	
	// prompt the user to input numbers
	std::cout << "PLEASE INPUT 3 NUMBERS: " << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	// perform the algorithm
	int result = a > b ? a*a + (b > c ? b*b : c*c) : b*b + (a>c? a*a : c*c);

	// output the result
	std::cout << "THE SUM OF SQUARES OF THE 2 LARGEST NUMBERS IS: " << result << std::endl;

	system("PAUSE");
	return 0;

}