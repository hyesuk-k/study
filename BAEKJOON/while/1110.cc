#include <iostream>

int main() {
	int n, newNumber;
	int ret = 0;

	int tmp1,tmp2;
	int t;
	
	std::cin >> n;

	newNumber = n;

	do {
		if (newNumber < 10) {
			tmp1 = 0;
			tmp2 = newNumber;
			t = tmp1 + tmp2;
			newNumber = (newNumber * 10) + (t % 10);
		} else {
			tmp1 = newNumber / 10;
			tmp2 = newNumber % 10;
			t = tmp1 + tmp2;
			newNumber = ((newNumber % 10)*10) + (t % 10);
		}
		ret++;
	} while (n != newNumber);

	std::cout << ret << std::endl;
	return 0;
}
