#include <iostream>
#include <vector>

using namespace std;

vector<long> getMultiples(long num) {
	vector<long> multiples;
	for (long divisor = 2; divisor < num/divisor; divisor++) {
		if (num % divisor == 0) {
			multiples.push_back(divisor);
			multiples.push_back(num/divisor);
		}
	}
	return multiples;
}

int main() {
	long number = 600851475143;
	vector<long> mults = getMultiples(number);
	
	long largestPrime = number;
	
	vector<long>::iterator it = mults.begin();
	while (it != mults.begin()) {
		vector<long>::iterator testIt = mults.begin();
		bool isPrime = true;
		long num = *it;
		while (testIt < it) {
			if (num % *testIt == 0) {
				isPrime = false;
			}
			testIt++;
		}
		if (isPrime) {
			largestPrime = num;
			break;
		}
		it--;
	}
	
	cout << largestPrime << "\n";
	
	return 0;
}	
