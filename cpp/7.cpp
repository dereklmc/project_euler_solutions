/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #7
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=7).
 */


#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> primes;
	
	primes.push_back(2);
	
	int num = 3;
	bool isPrime;
	while (primes.size() < 10001) {
		isPrime = true;
		vector<int>::iterator it;
		for (it = primes.begin(); it < primes.end(); it++) {
			if (num % *it == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(num);
		}
		num += 2;
	}
	
	cout << primes[primes.size() - 1] << endl;
	
	return 0;
}
