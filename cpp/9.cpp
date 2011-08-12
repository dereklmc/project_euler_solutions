/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #9
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=9).
 */

#include <iostream>
#include <math.h>

using namespace std;

int getTripleProductForSum(int sum) {
	int a, b, c;
	int b2, c2, bcSum;
	for (double c = 1; c < sum; c++) {
		c2 = c*c;
		for (int b = 1; b < c; b++) {
			b2 = b*b;
			bcSum = b + c;
			for (int a = 1; a < b; a++) {
				if ((a*a + b2 == c2) && (a + bcSum == sum)) {
					return a*b*c;
				}
			}
		}
	}
	return -1;
}

int main() {
	int prod = getTripleProductForSum(1000);
	
	cout << prod << endl;
	
	return 0;
}
