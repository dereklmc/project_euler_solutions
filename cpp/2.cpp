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
