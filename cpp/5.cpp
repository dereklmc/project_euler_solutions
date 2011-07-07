/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #5
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=5).
 */

#include<iostream>
#include<vector>

using namespace std;

int main() {
	
	int factors[20];
	for (int i = 0; i < 20; i++)
		factors[i] = i + 1;
	
	bool allOne = false;
	int product = 1;
	int currDivisor = 2;
	while (!allOne) {
		bool canDivide = false;
		allOne = true;
		for (int j = 0; j < 20; j++) {
			if (factors[j] % currDivisor == 0) {
				canDivide = true;
				factors[j] /= currDivisor;
			}
			if (factors[j] != 1)
				allOne = false;
		}
		if (canDivide)
			product *= currDivisor;
		else
			currDivisor += 1;
	}
	
	cout << product << endl;
	
	return 0;
}
