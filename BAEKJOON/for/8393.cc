#include <iostream>

int factorial(int n) {
	int result = 1;
	for (int i = 2; i <= n ; i++) {
		result += i;
	}
	return result;
}

int main () {
	int n;

	std::cin >> n;

	std::cout << factorial(n) << std::endl;

	return 0;
}
