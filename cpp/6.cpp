/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #6
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=6).
 */

#include<iostream>

using namespace std;

int main() {
	
	int sum = 0;
	int sumSquares = 0;
	
	for (int i = 1; i < 101; i++) {
		sum += i;
		sumSquares += i*i;
	}

	int squareSum = sum * sum;
	
	int diff = squareSum - sumSquares;
		
	cout << "Diff: " << diff << endl;
	
	return 0;
}
