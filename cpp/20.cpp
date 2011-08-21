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

class Number {
		short *numArray;
		int numDigits;
		int capacity;
			
	public:
		Number (int capacity);
		Number (int capacity, long number);
		Number (const Number &cSource);
		string str();
		int getCapacity ();
		int getLength ();
		short* asArray() { return numArray; }
		short operator[] (int index);
		Number operator + (Number other);
		Number operator * (Number other);
	
	private:
		void init(int capacity);
		void addToDigit(int index, short digit);
		static Number multiply(Number a, Number b);
};
Number::Number (int capacity) {
	init(capacity);
}
Number::Number (int capacity, long number) {
	init(capacity);	
	while (number != 0) {
		numArray[numDigits] = number % 10;
		number /= 10;
		numDigits++;
	}
}
Number::Number (const Number &source) {
	init(source.capacity);	
	numDigits = source.numDigits;
	for (int i = 0; i < numDigits; i++) {
		numArray[i] = source.numArray[i];
	}
}
void Number::init (int cap) {
	capacity = cap;
	numArray = new short[capacity];
	for (int i = 0; i < capacity; i++) {
		numArray[i] = 0;
	}
	numDigits = 0;
}
string Number::str () {
	if (numDigits == 0) {
		return "NULL";
	}
	stringstream conv_stream;
    conv_stream << setprecision(numDigits);
	for (int i = numDigits-1; i > -1; i--) {
		conv_stream << numArray[i];
	}
	return conv_stream.str();
}
void Number::addToDigit(int index, short digitValue) {
	if (digitValue !=0) {
		short sum = numArray[index] + digitValue;
		numArray[index] = sum % 10;
		addToDigit(index+1, sum/10);
		if (index >= numDigits) {
			numDigits = index + 1;
		}
	}
}
int Number::getCapacity () {
	return capacity;
}
int Number::getLength () {
	return numDigits;
}
Number Number::operator+ (Number other) {
	Number sum (*this);
	for (int i = 0 ; i < sum.getLength(); i++) {
		sum.addToDigit(i, other[i]);
	}
	return (sum);
}
short Number::operator[] (int index) {
	return numArray[index];
}
Number Number::operator* (Number other) {
	int otherCap = other.getCapacity();
	if (otherCap > capacity) {
		return multiply(other, *this);
	} else {
		return multiply(*this, other);
	}
}
/**
 * REQUIRED:
 * a >= b
 */
Number Number::multiply(Number a, Number b) {
	Number product (a.getCapacity());
	short dA, dB, prod;
	for (int bIndex = 0 ; bIndex < b.getLength(); bIndex++) {
		dB = b[bIndex];
		for (int aIndex = 0; aIndex < a.getLength(); aIndex++) {
			dA = a[aIndex];
			prod = dA * dB;
			product.addToDigit(aIndex+bIndex,prod);
		}
	}
	return product;
}

int main(int argc, char* argv[]) {
	int a = atoi(argv[1]);
	Number base (500, a);
	cout << "BASE: " << base.str() << endl;
	
	Number fact (500, 1);
	for (int i = a; i > 0; i--) {
		Number n (500, i);
		fact = fact * n;
	}
	int sum = 0;
	for (int i = 0; i < fact.getLength(); i++) {
		sum += fact[i];
	}
	cout << "Sum: " << sum << endl;
	
	return 0;
}
