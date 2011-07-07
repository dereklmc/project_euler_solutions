/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #3
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=3).
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/*
 * Returns a list of all factors of a given number.
 */
list<long> getFactors(long num) {
	list<long> facts;
	for (long divisor = 2; divisor < num/divisor; divisor++) {
		if (num % divisor == 0) {
			facts.push_back(divisor);
			facts.push_back(num/divisor);
		}
	}
	return facts;
}

int main() {
	long number = 600851475143;
	list<long> factors = getFactors(number);
	
	factors.sort();

	list<long>::iterator it;
	for (it = factors.begin(); it != factors.end(); it++) {
		long fact = *it;
		list<long>::iterator sieveIt = it;
		sieveIt++;
		while (sieveIt != factors.end())
			if (*sieveIt % fact == 0)
				sieveIt = factors.erase(sieveIt);
			else
				sieveIt++;
	}
	
	cout << "Largest Prime: " << factors.back() << endl;
	
	return 0;
}
