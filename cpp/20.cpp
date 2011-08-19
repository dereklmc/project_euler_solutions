/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #20
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=20).
 */


#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

using namespace std;

string toString(long double n) {
        stringstream conv_stream;
        conv_stream << setprecision(10000);
        conv_stream << n;
        return conv_stream.str();
}


bool notZero(string number) {
	char zero = '0';
	int len = number.size();
	for (int i = 0; i < len; i++) {
		if (number[i] != zero) {
			return true;
		}
	}
	return false;
}

string padLeft(string num, size_t numZ) {
	string pad (numZ, '0');
	return pad + num;
}

int intAt(string s, int index) {
	char c = s[index];
	return atoi(&c);
}

string add(string a, string b) {
	size_t lenA = a.size();
	size_t lenB = b.size();
	if (lenA < lenB) {
		a = padLeft(a, lenB - lenA);
	} else if (lenA > lenB) {
		b = padLeft(b, lenA - lenB);
	}
	size_t numLength = a.size();
	
	for (int i = numLength-1; i > -1; i--) {
		int digA = intAt(a, i);
		for (int j = i; j > -1; j--) {
			int digB = intAt(b, j);
			int sum = digA + digB;
			digA = sum / 10;
			b[j] = toString(sum % 10)[0];
		}
		if (digA > 0) {
			string overStr = toString(digA);
			b = overStr + b;
			a = string (overStr.size(), '0') + a;
		}
	}
	return b;
}

string mult(string a, string b) {
	string product = "0";
	int lenA = a.size();
	int lenB = b.size();
	for (int i = lenA - 1; i > -1; i--) {
		int digA = intAt(a, i);
		for (int j = lenB - 1; j > -1; j--) {
			int digB = intAt(b, j);
			int iProd = digA * digB;
			string prod = toString(iProd) + string (lenA - i + lenB - j - 2, '0');
			product = add(product, prod);
		}
	}
	cout << product << endl;
	return product;	
}

int main(int argc, char* argv[]) {
	int base = atoi(argv[1]);
	cout << "Base: " << base << endl;

	string fact = "1";	
	for (int i = 1; i <= base; i++) {
		string n = toString(i);
		cout << n << ", ";
		fact = mult(fact, n);
		cout << fact << endl;
	}
	
	cout << "Factorial: " << fact << endl;
	
	return 0;
}
/*
long factorial(int base) {
	long long num = 1;
	for (int i = base; i > 0; i--) {
		cout << i << " - ";
		num *= i;
		cout << num << endl;
	}
	return num;
}

string toString(long double n) {
        stringstream conv_stream;
	conv_stream << setprecision(10000);
        conv_stream << n;
        return conv_stream.str();
}

int main(int argc, char* argv[]) {
	cout << setprecision(1000);	
	int base = atoi(argv[1]);
	cout << "Start: " << base << endl;
	
	long fact = factorial(base);
	string digits = toString(fact);
	int len = digits.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		char c = digits[i];
		int digit = atoi(&c);
		sum += digit;
	}
	
	cout << endl << sum << endl;
	
	return 0;
}
*/
