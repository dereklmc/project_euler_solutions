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

using namespace std;

string int2String(int n) {
	stringstream conv_stream;
	conv_stream << n;
	return conv_stream.str();
}

bool isPalindrome(string s) {
	int size = s.size();
	for (int i = 0, j = size-1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

int largestPalindrome(int min, int max) {
	int largest = 0;
	for (int a = min; a < max; a++) {
		for (int b = min+1; b < max+1; b++) {
			int numProduct = a * b;
			string strProduct = int2String(numProduct);
			if (isPalindrome(strProduct) and numProduct > largest) {
				largest = numProduct;
			}
		}
	}
	return largest;
}

int main() {
	int number = largestPalindrome(100, 999);
	
	cout << "Largest Palindrome: ";
	if (number == -1) {
		cout << "NAN";
	} else {	
		cout << number;
	}
	cout << " " << endl;
	return 0;
}
