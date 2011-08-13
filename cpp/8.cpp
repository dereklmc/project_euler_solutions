/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #8
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=8).
 */


#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inFile (argv[1]);
	
	string line;
	
	if (inFile.is_open() && inFile.good()) {
		getline (inFile,line);
		int largest = 0;
		int len = line.size();
		for (int i = 0; i < len-5; i++) {
			int prod = 1;
			for (int j = i; j < i+5; j++) {
				char c = line[j];
				int digit = atoi(&c);
				prod *= digit;
			}
			if (prod > largest) {
				largest = prod;
			}
		}
		
		cout << largest << endl;
		
		inFile.close();
	}
	
	return 0;
}
