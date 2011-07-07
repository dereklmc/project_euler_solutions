/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #2
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=2).
 */

#include<iostream>

using namespace std;

int fibSumBelow(int limit) {
	int sum = 0;
	int a = 0;
	int b = 1;
	int s;
	while (b < limit) {
		s = a + b;
		a = b;
		b = s;
		sum += (b % 2 == 0) ? b : 0;
	}
	return sum;
}

int main() {
	cout << fibSumBelow(4000000) << "\n";
}
