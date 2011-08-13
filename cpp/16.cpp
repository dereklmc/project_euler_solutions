/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #4
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=4).
 */

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

string toString(double n) {
	stringstream conv_stream;
	conv_stream << setprecision(1000);
	conv_stream << n;
	return conv_stream.str();
}

int main() {
	long double b = 2;
	long double number = pow(b, 1000);
	
	string digits = toString(number);
	
	int sum = 0;
	int len = digits.size();
	for (int i = 0; i < len; i++) {
		char c = digits[i];
		int d = atoi(&c);
		sum += d;
	}
	cout << sum << endl;
	
	return 0;
}
