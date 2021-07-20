#include <iostream>
#include <array>

int main() {
	int t;

	std::cin >> t ;

	int *a = new int[t];
	int *b = new int[t];

	for (int i = 0 ; i < t ; i++) {
		std::cin >> a[i] >> b[i];
	}

	for (int i = 0 ; i < t ; i++) {
		std::cout << a[i] + b[i] << std::endl;
	}

	delete[] a, b;
	return 0;
}
