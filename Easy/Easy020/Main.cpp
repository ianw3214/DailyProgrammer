/*	Prime Number Generation Program
*/

#include <iostream>
#include <vector>

// function declarations
std::vector<int> getPrime(int);

int main(int argc, char* argv[]) {

	// vector to store the prime numbers
	std::vector<int> primes = getPrime(2000);

	// output the result
	std::cout << "The prime numbers are: " << std::endl;
	
	// loop through the vector
	for (int i = 1; i <= primes.size(); i++) {
		// print out the number
		std::cout << primes.at(i-1) << ", ";
		// for every 10 lines
		if (i%10 == 0) {
			// print a new line
			std::cout << std::endl;
		}
	}

	system("PAUSE");
	return 0;

}

// function to get the prime numbers up to a certain point
std::vector<int> getPrime(int nums) {

	// final vector to return
	std::vector<int> fPrimes;

	// loop from 2 to the input num
	for (int i = 2; i <= nums; i++) {

		// boolean to store whether the number is prime
		bool prime = true;

		// loop through numbers between 2 and current number
		for (int j = 2; j <= i; j++) {
			if (i % j == 0 && i != j) {	// if the number is divisible by the factor
				prime = false;			// the number isn't prime if it has a factor
			}
		}

		// if it is a prime number
		if (prime) {
			// push the current number into the vector
			fPrimes.push_back(i);
		}

	}

	// return the final array
	return fPrimes;

}