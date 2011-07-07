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
