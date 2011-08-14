/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #10
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=10).
 */


#include <iostream>
#include<stdlib.h>

using namespace std;

void eliminateMultiples(int num, int range[], int len) {
	int s = 0;
	for (int i = num*2; i < len; i+=num) {
		range[i] = 0;
		s += 1;
	}
	//cout << num << " : " << s << endl;
}

void fillArray(int num, int array[], int len) {
	for (int i = 0; i < len; i++) {
		array[i] = num;
	}
}

int main(int argc, char* argv[]) {
	long int limit = atoi(argv[1]);
	int range [limit];
	fillArray(1, range, limit);
	
	long int primeSum = 0;
	
	for (int i = 2; i < limit; i++) {
		if (range[i] == 1) {
			//cout << i << endl;
			primeSum += i;
			eliminateMultiples(i, range, limit);
		}
	}
	
	cout << primeSum << endl;
	
	return 0;
}		
