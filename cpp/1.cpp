/*
 * Copyright (C) 2011 Derek McLean
 * 
 * You are free to do whatever you want with this program provided
 * this notice is preserved. This program is free software. It 
 * comes without any warranty, to the extent permitted by applicable law.
 * 
 * Solution for Project Euler Problem #1
 * The problem page can be found at:
 * (http://projecteuler.net/index.php?section=problems&id=1).
 */

#include <iostream>

using namespace std;

int countNum(int num, int range) {
        int sum = 0;
        for (int i = num; i < range; i += num) {
                 sum = sum + i;
        }
        return sum;
}

int main() {
	int threes = countNum(3, 1000);
	int fives = countNum(5, 1000);
	int fifteens = countNum(15, 1000);
	
	int sum = threes + fives - fifteens;
	cout << sum << "\n";
}
